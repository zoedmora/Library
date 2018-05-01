#ifndef CHECKBOOK_H
#define CHECKBOOK_H

#include <QDialog>
#include <QDialog>
#include <QDebug>
#include <QStringList>

namespace Ui {
class checkbook;
}

class checkbook : public QDialog
{
    Q_OBJECT

public:
    explicit checkbook(QWidget *parent = 0);
    ~checkbook();
    void accept();//overriding

signals:
    void confirmCheckButtonWasClicked(QStringList*);

private:
    Ui::checkbook *ui;
    QStringList* isbnInfo;
};

#endif // CHECKBOOK_H
