#ifndef ADDNEWUSER_H
#define ADDNEWUSER_H

#include <QDialog>
#include <QWidget>
#include <QDebug>
#include <QStringList>

namespace Ui {
class addnewuser;
}

class addnewuser : public QDialog
{
    Q_OBJECT

public:
    explicit addnewuser(QWidget *parent = 0);
    ~addnewuser();
    void reject();
    void accept();

signals:
    void confirmButtonWasClicked(QStringList*);

private:
    Ui::addnewuser *ui;
    QStringList* userInformation;
};

#endif // ADDNEWUSER_H
