#include "frame.h"
#include "ui_frame.h"

Frame::Frame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Frame)
{
    book = new Book();
    ui->setupUi(this);
    ui->checkBox->setVisible(false);
}

Frame::~Frame()
{
    delete ui;
}

void Frame::setBook(QString isbn, QString t, QString a, QString q, QString p, QString g)
{
    book->ISBN = isbn;
    book->title = t;
    book->author = a;
    book->quantity = q;
    book->publisher = p;
    book->genre = g;
}

QString Frame::getQuantity()
{
    return ui->quantityLineEdit->text();
}

QLineEdit* Frame::getQuantityLineEdit()
{
    return ui->quantityLineEdit;
}
