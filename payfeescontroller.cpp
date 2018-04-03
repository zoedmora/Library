#include "payfeescontroller.h"

PayFeesController::PayFeesController(QObject *parent)
    : QAbstractItemModel(parent)
{
}

void PayFeesController::run(MainWindow* mw, DatabaseBoundary* dbb, LogedInUserData* liud)
{
    qDebug() << "Running Pay Fees Controller";

    PayFeesWindow* pfw = new PayFeesWindow();

    QObject::connect(pfw, SIGNAL(OKButtonWasClicked(QString*)), dbb, SLOT(payUserFees(QString*)));

    QString currentUser = liud->getLogedInUserName();

    //qDebug() << "Person logged in is: " << currentUser;

    QString balance = dbb->getUserBalance(currentUser);

    //qDebug() << "Balance is: $" << balance;

    pfw->setBalance(balance);

    pfw->exec();

}


QVariant PayFeesController::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex PayFeesController::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex PayFeesController::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int PayFeesController::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int PayFeesController::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant PayFeesController::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
