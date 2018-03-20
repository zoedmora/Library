#include "payfeeswindow.h"
#include "ui_payfeeswindow.h"
#include "mainwindow.h"

PayFeesWindow::PayFeesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PayFeesWindow)
{
    ui->setupUi(this);
    userFees = new QStringList();
}

PayFeesWindow::~PayFeesWindow()
{
    delete ui;
}

void PayFeesWindow::accept()
{
    qDebug() << "OK button was clicked.";

    userFees->append(ui->lineEdit->text());
    emit OKButtonWasClicked(userFees);
    QDialog::accept();
}

void PayFeesWindow::reject()
{
    qDebug() << "Reject was called.";
    QDialog::reject();
}
