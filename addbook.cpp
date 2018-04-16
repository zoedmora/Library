#include "addbook.h"
#include "ui_addbook.h"

addbook::addbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addbook)
{
    bookInfo = new QStringList;
    isbnInfo = new QStringList;

    ui->setupUi(this);
    ui->Success->setVisible(false);
    ui->Failed->setVisible(false);
    ui->Success_2->setVisible(false);
    ui->Failed_2->setVisible(false);

//    QObject::connect(ui->ISBN_Input, SIGNAL(textChanged(QString)), this, SIGNAL(scanWasDone(QString)));
}

addbook::~addbook()
{
    delete ui;
}

void addbook::accept()
{
     qDebug() << "Ok button was clicked.";

     isbnInfo->clear();
     isbnInfo->append(ui -> ISBN_Input->text());
     bookInfo->clear();
     bookInfo->append(ui->Title_Field->text());
     bookInfo->append(ui->Author_Field->text());
     bookInfo->append(ui->Genre_Field->text());
     bookInfo->append(ui->Publisher_Field->text());
     bookInfo->append(ui->ISBN_Field->text());

     if (isbnInfo->at(0) == "" and bookInfo->at(4) != "") {
        emit okButtonWasClicked(bookInfo);

        qDebug() << "Lets check out the list: " << bookInfo->at(0);

        //success
        if(bookInfo->back() == "*")
        {
            ui->Success_2->setText("Success for ISBN: " + bookInfo->at(4));
            ui->Success_2->setVisible(true);
            ui->Failed_2->setVisible(false);
            ui->Success->setVisible(false);
            ui->Failed->setVisible(false);
        }
        //fail
        else
        {
            ui->Failed_2->setText("Failed for ISBN: " + bookInfo->at(4));
            ui->Failed_2->setVisible(true);
            ui->Success_2->setVisible(false);
            ui->Success->setVisible(false);
            ui->Failed->setVisible(false);
        }
     }

     else if (isbnInfo->at(0) != "") {
         ui->Title_Field->clear();
         ui->Author_Field->clear();
         ui->Genre_Field->clear();
         ui->Publisher_Field->clear();
         ui->ISBN_Field->clear();
         emit scanWasDone(isbnInfo);
         ui->ISBN_Input->clear();

         //success
         if(isbnInfo->back() == "*")
         {
             ui->Success->setText("Success for ISBN: " + isbnInfo->at(0));
             ui->Success->setVisible(true);
             ui->Failed->setVisible(false);
             ui->Success_2->setVisible(false);
             ui->Failed_2->setVisible(false);
         }
         //fail
         else
         {
             ui->Failed->setText("Failed for ISBN: " + isbnInfo->at(0));
             ui->Failed->setVisible(true);
             ui->Success->setVisible(false);
             ui->Success_2->setVisible(false);
             ui->Failed_2->setVisible(false);
         }
     }
     else
     {
         qDebug() << "Missing fields/Wrong info.";
         ui->Failed->setVisible(true);
         ui->Success->setVisible(false);
     }


}

