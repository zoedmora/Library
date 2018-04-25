#include "payfeescontroller.h"

PayFeesController::PayFeesController(QObject *parent)
    : QAbstractItemModel(parent)
{
}

void PayFeesController::run(MainWindow* mw, DatabaseBoundary* dbb, LogedInUserData* liud)
{   
    qDebug() << "Running Pay Fees Controller";

    //User ID of who ever is logged in
    QString currentUser = liud->getLogedInUserName();

    //Window To Pay The Fees
    PayFeesWindow* pfw = new PayFeesWindow(currentUser);

    //Send current user to window
    pfw->currentUserLogedIn(currentUser);

    //Getting balance and total payment of current user
    double balance = dbb->getUserBalance(currentUser);
    double totalPayment = dbb->getTotalPayment(currentUser);

    //Send balance and total payment to window
    pfw->updateBalance(balance, totalPayment);

    //Get db from dbb
    pfw->dbConnection(dbb->getDb());

    //Updating the database Fee column in the user
    QObject::connect(pfw, SIGNAL(OKButtonWasClicked(double, QString)), dbb, SLOT(updateUserFees(double, QString)));
    QObject::connect(pfw, SIGNAL(paymentButtonClicked(double,QString, QString)), dbb, SLOT(updatePayHistory(double, QString, QString)));

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
