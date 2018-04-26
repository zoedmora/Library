#include "deleteuser.h"
#include "ui_deleteuser.h"
#include "QDebug"

DeleteUser::DeleteUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteUser)
{
    ui->setupUi(this);
    idToSearch = new QStringList();

    // Hide the user information until a user ID is found.
    ui->accountNameLabel->hide();
    ui->addressLabel->hide();
    ui->buttonBox->hide();
    ui->cityLabel->hide();
    ui->emailLabel->hide();
    ui->fNameLabel->hide();
    ui->foundAccountName->hide();
    ui->foundAddress->hide();
    ui->foundCity->hide();
    ui->foundEmail->hide();
    ui->foundFName->hide();
    ui->foundLName->hide();
    ui->foundPhone->hide();
    ui->foundZip->hide();
    ui->lNameLabel->hide();
    ui->phoneLabel->hide();
    ui->zipLabel->hide();
}

void DeleteUser::changeNameText(QString n)
{
    ui->foundAccountName->setText(n);
    ui->foundAccountName->show();
    ui->accountNameLabel->show();
}

void DeleteUser::changefNameText(QString n)
{
    ui->foundFName->setText(n);
    ui->foundFName->show();
    ui->fNameLabel->show();
}

void DeleteUser::changelNameText(QString n)
{
    ui->foundLName->setText(n);
    ui->foundLName->show();
    ui->lNameLabel->show();
}

void DeleteUser::changeAddressText(QString n)
{
    ui->foundAddress->setText(n);
    ui->foundAddress->show();
    ui->addressLabel->show();
}

void DeleteUser::changeCityText(QString n)
{
    ui->foundCity->setText(n);
    ui->foundCity->show();
    ui->cityLabel->show();
}

void DeleteUser::changeZipText(QString n)
{
    ui->foundZip->setText(n);
    ui->foundZip->show();
    ui->zipLabel->show();
}

void DeleteUser::changeEmailText(QString n)
{
    ui->foundEmail->setText(n);
    ui->emailLabel->show();
    ui->foundEmail->show();
}

void DeleteUser::changePhoneText(QString n)
{
    ui->foundPhone->setText(n);
    ui->phoneLabel->show();
    ui->foundPhone->show();
}

QString DeleteUser::getSearch()
{
    return ui->idTextbox->text();
}

void DeleteUser::showButton()
{
    ui->buttonBox->show();
}

void DeleteUser::reject()
{
    qDebug() << "Reject was called.";
    QDialog::reject();
}

void DeleteUser::accept()
{
    emit confirmButtonWasClicked(idToSearch);
    QDialog::accept();
}

DeleteUser::~DeleteUser()
{
    delete ui;
}

void DeleteUser::on_searchButton_clicked()
{
    idToSearch->append(ui->idTextbox->text());
    emit searchButtonWasClicked(idToSearch);
    qDebug() << idToSearch->at(0) << idToSearch->at(1) << idToSearch->at(2) << idToSearch->at(3) << idToSearch->at(4) <<
                idToSearch->at(5) << idToSearch->at(6) << idToSearch->at(7) << idToSearch->at(8) << idToSearch->at(9) << idToSearch->at(10);

    changeAddressText(idToSearch->at(6));
    changeCityText(idToSearch->at(7));
    changeEmailText(idToSearch->at(8));
    changefNameText(idToSearch->at(4));
    changelNameText(idToSearch->at(5));
    changeNameText(idToSearch->at(2));
    changePhoneText(idToSearch->at(10));
    changeZipText(idToSearch->at(9));
    showButton();
}
