#ifndef PAYFEESWINDOW_H
#define PAYFEESWINDOW_H

#include <QDialog>
#include <QDebug>
#include <QStringList>

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

signals:
    void OKButtonWasClicked(QStringList*);

private:
    Ui::PayFeesWindow *ui;
    QStringList* userFees;

};

#endif // PAYFEESWINDOW_H
