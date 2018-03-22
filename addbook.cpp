#include "addbook.h"
#include "ui_addbook.h"

addbook::addbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addbook)
{
    bookInfo = new QStringList;
    ui->setupUi(this);
}

addbook::~addbook()
{
    delete ui;
}

void addbook::accept()
{
     qDebug() << "Ok button was clicked.";
     bookInfo->clear();
     bookInfo->append(ui->Title_Field->text());
     bookInfo->append(ui->Author_Field->text());
     bookInfo->append(ui->Genre_Field->text());
     bookInfo->append(ui->Publisher_Field->text());
     bookInfo->append(ui->ISBN_Field->text());

     emit okButtonWasClicked(bookInfo);
}
