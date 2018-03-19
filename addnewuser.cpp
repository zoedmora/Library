#include "addnewuser.h"
#include "ui_addnewuser.h"
#include "mainwindow.h"

addnewuser::addnewuser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addnewuser)
{
    ui->setupUi(this);
    userInformation = new QStringList();
}

addnewuser::~addnewuser()
{
    delete ui;
}

void addnewuser::reject()
{
    qDebug() << "Reject was called.";
    QDialog::reject();
}

void addnewuser::accept()
{
    qDebug() << "Confirm button was clicked.";

    //Pull User Information from Textboxes
    userInformation->append(ui->idTextbox->text());
    userInformation->append(ui->passwordTextbox->text());
    userInformation->append(ui->accountNameTextbox->text());
    userInformation->append(ui->fNameTextbox->text());
    userInformation->append(ui->lNameTextbox->text());
    userInformation->append(ui->addressTextbox->text());
    userInformation->append(ui->cityTextbox->text());
    userInformation->append(ui->zipTextbox->text());
    userInformation->append(ui->emailTextbox->text());
    userInformation->append(ui->phoneTextbox->text());

    // Signal the add user controller
    emit confirmButtonWasClicked(userInformation);

    QDialog::accept();
}
