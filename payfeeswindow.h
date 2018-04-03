#ifndef PAYFEESWINDOW_H
#define PAYFEESWINDOW_H

#include <QDialog>
#include <QDebug>
#include <QStringList>
#include <logedinuserdata.h>

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
    void setBalance(QString);

signals:
    void OKButtonWasClicked(QString*);

private:
    Ui::PayFeesWindow *ui;
    QString* paymentAmount;

};

#endif // PAYFEESWINDOW_H
