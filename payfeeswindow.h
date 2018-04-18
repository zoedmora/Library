#ifndef PAYFEESWINDOW_H
#define PAYFEESWINDOW_H

#include <QDialog>
#include <QDebug>
#include <QStringList>
#include <logedinuserdata.h>
#include <QTableView>
#include <QString>
#include <QSqlDatabase>
#include <QSqlTableModel>

namespace Ui {
class PayFeesWindow;
}

class PayFeesWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PayFeesWindow(QWidget *parent = 0);
    ~PayFeesWindow();
    void accept();
    void reject();
    void currentUserLogedIn(QString user){logedInUser = user;}
    void dbConnection(QSqlDatabase database){db = database;}
    QSqlDatabase getDb(){return db;}


signals:
    void OKButtonWasClicked(double, QString);
    void paymentButtonClicked(double, QString);


public slots:
    void updateBalance(double);

private:
    Ui::PayFeesWindow *ui;
    double balance;
    QString logedInUser;
    QSqlDatabase db;

};

#endif // PAYFEESWINDOW_H
