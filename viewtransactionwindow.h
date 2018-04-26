#ifndef VIEWTRANSACTIONWINDOW_H
#define VIEWTRANSACTIONWINDOW_H

#include <QDialog>

namespace Ui {
class viewTransactionWindow;
}

class viewTransactionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit viewTransactionWindow(QWidget *parent = 0);
    ~viewTransactionWindow();

private:
    Ui::viewTransactionWindow *ui;
};

#endif // VIEWTRANSACTIONWINDOW_H
