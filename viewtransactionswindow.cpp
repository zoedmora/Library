#include "viewtransactionswindow.h"
#include "ui_viewtransactionswindow.h"

viewtransactionswindow::viewtransactionswindow(QString userName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewtransactionswindow)
{
    ui->setupUi(this);

    //Show transaction history table on open
    QSqlTableModel *model = new QSqlTableModel(0, db);
    model->setTable("TransactionHistory");
    model->setFilter("userName like '"+ userName +"'");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("Title"));
    model->setHeaderData(1, Qt::Horizontal, tr("Transaction"));
    model->setHeaderData(2, Qt::Horizontal, tr("Date"));
    model->removeColumns(0, 3);
    ui->tableView->setModel(model);
}

viewtransactionswindow::~viewtransactionswindow()
{
    delete ui;
}

void viewtransactionswindow::accept()
{
    QSqlTableModel *model = new QSqlTableModel(0, db);
    model->setTable("TransactionHistory");
    model->setFilter("userName like '"+ logedInUser +"'");
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
    QFile csvFile(logedInUser + "Transactions.csv");
    if(csvFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {

        QTextStream out(&csvFile);
        out << textData;

        csvFile.close();
    }

    // .txt
    QFile txtFile(logedInUser + "Transactions.txt");
    if(txtFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {

        QTextStream out(&txtFile);
        out << textData;

        txtFile.close();
    }

    QMessageBox messageBox;
    messageBox.setText("Exported transaction history to excel!");
    messageBox.exec();

    QDialog::accept();
}

void viewtransactionswindow::reject()
{
    QDialog::reject();
}
