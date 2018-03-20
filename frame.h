#ifndef FRAME_H
#define FRAME_H

#include <QFrame>
#include "book.h"
#include <QLineEdit>

namespace Ui {
class Frame;
}

class Frame : public QFrame
{
    Q_OBJECT

public:
    explicit Frame(QWidget *parent = 0);
    ~Frame();
    void setBook(QString, QString, QString, QString, QString = "", QString = "");

//Variables
    Book* book;

//Functions
    QString getQuantity();
    QLineEdit* getQuantityLineEdit();

private:
    Ui::Frame *ui;
};

#endif // FRAME_H
