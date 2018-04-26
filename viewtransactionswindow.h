#ifndef VIEWTRANSACTIONSWINDOW_H
#define VIEWTRANSACTIONSWINDOW_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

namespace Ui {
class viewtransactionswindow;
}

class viewtransactionswindow : public QDialog
{
    Q_OBJECT

public:
    explicit viewtransactionswindow(QString userName, QWidget *parent = 0);
    ~viewtransactionswindow();
    void accept();
    void reject();
    void currentUserLogedIn(QString user){logedInUser = user;}
    void dbConnection(QSqlDatabase database){db = database;}

signals:
    void OKButtonWasClicked(double, QString);

private:
    Ui::viewtransactionswindow *ui;
    QString logedInUser;
    QSqlDatabase db;
};

#endif // VIEWTRANSACTIONSWINDOW_H
