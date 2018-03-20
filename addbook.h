#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QDialog>
#include <QDebug>
#include <QStringList>

namespace Ui {
class addbook;
}

class addbook : public QDialog
{
    Q_OBJECT

public:
    explicit addbook(QWidget *parent = 0);
    ~addbook();
    void accept();//overriding

signals:
    void okButtonWasClicked(QStringList*);

private:
    Ui::addbook *ui;
    QStringList* bookInfo;
};

#endif // ADDBOOK_H
