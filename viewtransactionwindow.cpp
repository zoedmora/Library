#include "viewtransactionwindow.h"
#include "ui_viewtransactionwindow.h"

viewTransactionWindow::viewTransactionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewTransactionWindow)
{
    ui->setupUi(this);
}

viewTransactionWindow::~viewTransactionWindow()
{
    delete ui;
}
