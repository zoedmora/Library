#include "checkbook.h"
#include "ui_checkbook.h"
#include "mainwindow.h"


checkbook::checkbook(QString userName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkbook)
{
    ui->setupUi(this);
    isbnInfo = new QStringList;
    ui->isbnInput->setFocus();
    user_Name = userName;
    ui->message->hide();

}

checkbook::~checkbook()
{
    delete ui;
}

void checkbook::accept()
{
     qDebug() << "Ok button was clicked.";
     isbnInfo->clear();
     isbnInfo->append(ui->isbnInput->text());
     emit confirmCheckButtonWasClicked(user_Name, isbnInfo);

     if(isbnInfo->back() == "*")
     {
        qDebug() << "Successful check out!";
        ui->message->setText("Successful check out: " + isbnInfo->at(0));
        ui->message->setVisible(true);
     }
     else if(isbnInfo->back() == "/")
     {
        qDebug() << "Successful check in!";
        ui->message->setText("Successful return of book: " + isbnInfo->at(0));
        ui->message->setVisible(true);
     }
     else if(isbnInfo->back() == "X")
     {
         qDebug() << "Failed to check out book. None in stock: " + isbnInfo->at(0);
         ui->message->setText("Failed to check out book. None available - Quantity is 0.");
         ui->message->setVisible(true);
     }
}
