#include "payfeeswindow.h"
#include "ui_payfeeswindow.h"
#include "mainwindow.h"

PayFeesWindow::PayFeesWindow(QString userName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PayFeesWindow)
{
    ui->setupUi(this);

    //Show payment history table on open
    QSqlTableModel *model = new QSqlTableModel(0, db);
    model->setTable("PayHistory");
    model->setFilter("userName like '"+ userName +"'");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("Paid Amount"));
    model->removeColumns(0,2);
    ui->tableView->setModel(model);

    //Show book charges table on open
    QSqlTableModel *feeModel = new QSqlTableModel(0, db);
    feeModel->setTable("UserFees");
    feeModel->setFilter("userName like '"+ userName +"'");
    feeModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    feeModel->select();
    feeModel->removeColumns(0,3);
    ui->FeeTable->setModel(feeModel);
}

PayFeesWindow::~PayFeesWindow()
{
    delete ui;
}

void PayFeesWindow::accept()
{
    //here we need to do the arithmatic to update our balance
    //then we need to update this balance in the database aswell

    qDebug() << "OK button was clicked.";

    double paymentAmount = ui->paymentLineEdit->text().toDouble();

    QString date = QDate::currentDate().toString("M/d/yy");

    //Updating balance variable
    if(balance - paymentAmount >= 0 && paymentAmount != 0){
        balance -= paymentAmount;
        //Success message box
        QMessageBox messageBox;
        messageBox.setText("Payment received!  ");
        messageBox.exec();

        //Updating Balance Label
        ui->balanceLabel->setText("Balance is : $" + QString::number(balance));

        //Signal for updating DB
        emit OKButtonWasClicked(balance, logedInUser);
        emit paymentButtonClicked(paymentAmount, logedInUser, date);
    }
    else {
        //Error message box
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Invalid input!");
        messageBox.setFixedSize(500,200);
    }

    //Update Payment history table on click
    QSqlTableModel *model = new QSqlTableModel(0, db);
    model->setTable("PayHistory");
    model->setFilter("userName like '"+ logedInUser +"'");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("Paid Amount"));
    model->removeColumns(0,2);
    ui->tableView->setModel(model);

}

void PayFeesWindow::reject()
{
    qDebug() << "Reject was called.";
    QDialog::reject();
}

void PayFeesWindow::updateBalance(double amount, double payment)
{
    balance = amount - payment;
    ui->balanceLabel->setText("Balance is: $" + QString::number(balance));
}


