#include "checkbook.h"
#include "ui_checkbook.h"
#include "mainwindow.h"


checkbook::checkbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkbook)
{
    ui->setupUi(this);
    isbnInfo = new QStringList;
    ui->isbnInput->setFocus();

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
     emit confirmCheckButtonWasClicked(isbnInfo);

     if(isbnInfo->back() == "*")
     {
        qDebug() << "Success!";

     }
     //fail
     else if(isbnInfo->back() == "/")
     {
//         ui->Failed_2->setText("Failed for ISBN: " + bookInfo->at(4));
//         ui->Failed_2->setVisible(true);
//         ui->Success_2->setVisible(false);
//         ui->Success->setVisible(false);
//         ui->Failed->setVisible(false);
     }


}
