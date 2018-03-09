#include "ui_loginwindow.h"
#include "loginwindow.h"
#include "mainwindow.h"

LogInWindow::LogInWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogInWindow)
{
    logedIn = false;
    userInfo = new QStringList;
    setModal(true);
    ui->setupUi(this);
    ui->noMatchWarningLabel->setVisible(false);

}

LogInWindow::~LogInWindow()
{
    delete ui;
}


void LogInWindow::setLogedInStatus(bool b)
{
    logedIn = b;
}

void LogInWindow::reject()
{
    qDebug() << "yay, I was called";
    QDialog::reject();

}

void LogInWindow::accept()
{
    qDebug() << "Ok button was clicked.";

    //grab the users information
    userInfo->append(ui->nameLineEdit->text());
    userInfo->append(ui->passwordLineEdit->text());

    qDebug() << "List is: " << userInfo->front() << userInfo->at(1);

    //signal the log-in controller to check the credentials
    emit okButtonWasClicked(userInfo);

    qDebug() << "Lets check out the list: " << userInfo->at(0) << userInfo->at(1);

    //checking if log in was successful
    if(userInfo->back() == "*"  || userInfo->back() == "_")
    {
        //to show if we have an employee account
        if(userInfo->back() == "_")
            employeeAccount = true;

        qDebug() << "Log in successful.";
        logedIn = true;
        QDialog::accept();
    }
    else
    {
        qDebug() << "Log in not successful";

        //reset our user info
        userInfo->clear();
        ui->noMatchWarningLabel->setVisible(true);
    }
}


void LogInWindow::practice()
{
    qDebug() << "Yay!------------------------" << endl;
}
