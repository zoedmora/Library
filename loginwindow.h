#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QDebug>
#include <QStringList>
//#include "mainwindow.h"

namespace Ui {
class LogInWindow;
}

class LogInWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LogInWindow(QWidget *parent = 0);
    ~LogInWindow();
    bool isLogedIn(){return logedIn;}
    void setLogedInStatus(bool);
    bool isEmployeeAccount(){return employeeAccount;}
    void reject();//this is an overriding method we are doing
    void accept();//overriding


signals:
    void okButtonWasClicked(QStringList*);
    void sendUserName(QString);

public slots:
    //void on_buttonBox_accepted();
    void practice();

private:
//Variables
    Ui::LogInWindow *ui;
    bool logedIn;
    QStringList* userInfo;
    bool employeeAccount;
};

#endif // LOGINWINDOW_H
