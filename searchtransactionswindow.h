#ifndef SEARCHTRANSACTIONSWINDOW_H
#define SEARCHTRANSACTIONSWINDOW_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class SearchTransactionsWindow;
}

class SearchTransactionsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SearchTransactionsWindow(QWidget *parent = 0);
    ~SearchTransactionsWindow();
    void accept();
    void reject();
    void open();
    void dbConnection(QSqlDatabase database){db = database;}

signals:
    void OKButtonWasClicked(int);

public slots:
    void setCurrentUser(QString);

private:
    Ui::SearchTransactionsWindow *ui;
    QSqlDatabase db;
    QString currentUser;
    QSqlTableModel saveModel;
};

#endif // SEARCHTRANSACTIONSWINDOW_H
