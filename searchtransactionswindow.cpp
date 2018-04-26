#include "searchtransactionswindow.h"
#include "ui_searchtransactionswindow.h"

SearchTransactionsWindow::SearchTransactionsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchTransactionsWindow)
{
    ui->setupUi(this);
}

SearchTransactionsWindow::~SearchTransactionsWindow()
{
    delete ui;
}

void SearchTransactionsWindow::accept()
{
    //Get ID from line edit and send to db
    int userID = ui->idLineEdit->text().toInt();
    emit OKButtonWasClicked(userID);

    //Update Table
    QSqlTableModel *model = new QSqlTableModel(0, db);
    model->setTable("TransactionHistory");
    model->setFilter("userName like '"+ currentUser +"'");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("Title"));
    model->setHeaderData(1, Qt::Horizontal, tr("Transaction"));
    model->setHeaderData(2, Qt::Horizontal, tr("Date"));
    model->removeColumns(0, 3);
    ui->tableView->setModel(model);

    //set text labels
    ui->nameLabel->setText(currentUser + "'s Transactions");

}

void SearchTransactionsWindow::reject()
{
    QDialog::reject();
}

void SearchTransactionsWindow::open()
{
    if(currentUser.isNull()){
        qDebug() << "EMPTY STRING";
        QMessageBox messageBox;
        messageBox.setText("You must search a user's transactions first!");
        messageBox.exec();
    }
    else{
        QSqlTableModel *model = new QSqlTableModel(0, db);
        model->setTable("TransactionHistory");
        model->setFilter("userName like '"+ currentUser +"'");
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->select();
        model->setHeaderData(0, Qt::Horizontal, tr("Title"));
        model->setHeaderData(1, Qt::Horizontal, tr("Transaction"));
        model->setHeaderData(2, Qt::Horizontal, tr("Date"));
        model->removeColumns(0, 3);

        // [Collect model data to QString]
        QString textData;
        int rows = model->rowCount();
        int columns = model->columnCount();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {

                    textData += model->data(model->index(i,j)).toString();
                    textData += ", ";      // for .csv file format
            }
            textData += "\n";             // (optional: for new line segmentation)
        }

        // [Save to file] (header file <QFile> needed)
        // .csv
        QFile csvFile(currentUser + "Transactions.csv");
        if(csvFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {

            QTextStream out(&csvFile);
            out << textData;

            csvFile.close();
        }

        // .txt
        QFile txtFile(currentUser + "Transactions.txt");
        if(txtFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {

            QTextStream out(&txtFile);
            out << textData;

            txtFile.close();
        }

        QMessageBox messageBox;
        messageBox.setText("Exported transaction history to excel!");
        messageBox.exec();
    }

}

void SearchTransactionsWindow::setCurrentUser(QString user)
{
    currentUser = user;
}
