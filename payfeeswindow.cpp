#include "payfeeswindow.h"
#include "ui_payfeeswindow.h"
#include "mainwindow.h"

PayFeesWindow::PayFeesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PayFeesWindow)
{
    ui->setupUi(this);
    paymentAmount = new QString();
}

PayFeesWindow::~PayFeesWindow()
{
    delete ui;
}

void PayFeesWindow::accept()
{
    qDebug() << "OK button was clicked.";

    paymentAmount->append(ui->paymentLineEdit->text());
    emit OKButtonWasClicked(paymentAmount);
    QDialog::accept();
}

void PayFeesWindow::reject()
{
    qDebug() << "Reject was called.";
    QDialog::reject();
}

void PayFeesWindow::setBalance(QString balance)
{
    ui->label_3->setText("Your current balance is: $" + balance + ".00");
}
