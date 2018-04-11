#include "edituser.h"
#include "ui_edituser.h"

EditUser::EditUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditUser)
{
    ui->setupUi(this);
    userInformation = new QStringList();
}

EditUser::~EditUser()
{
    delete ui;
}

void EditUser::changeNameText(QString n)
{
    ui->accountNameTextbox->setText(n);
}

void EditUser::changeIDText(QString id)
{
    ui->idTextbox->setText(id);
}

void EditUser::changePasswordText(QString p)
{
    ui->passwordTextbox->setText(p);
}

void EditUser::changefNameText(QString f)
{
    ui->fNameTextbox->setText(f);
}

void EditUser::changelNameText(QString l)
{
    ui->lNameTextbox->setText(l);
}

void EditUser::changeAddressText(QString a)
{
    ui->addressTextbox->setText(a);
}

void EditUser::changeCityText(QString c)
{
    ui->cityTextbox->setText(c);
}

void EditUser::changeZipText(QString z)
{
    ui->zipTextbox->setText(z);
}

void EditUser::changeEmailText(QString e)
{
    ui->emailTextbox->setText(e);
}

void EditUser::changePhoneText(QString p)
{
    ui->phoneTextbox->setText(p);
}

void EditUser::reject()
{
    qDebug() << "Reject was called.";
    QDialog::reject();
}

void EditUser::accept()
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
    emit confirmChangesButtonWasClicked(userInformation);

    QDialog::accept();
}
