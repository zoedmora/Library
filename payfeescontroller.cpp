#include "payfeescontroller.h"

PayFeesController::PayFeesController(QObject *parent)
    : QAbstractItemModel(parent)
{
}

void PayFeesController::run(MainWindow* mw, DatabaseBoundary* dbb, LogedInUserData* liud)
{   
    qDebug() << "Running Pay Fees Controller";

    //Window To Pay The Fees
    PayFeesWindow* pfw = new PayFeesWindow();

    //user Id of who ever is logged in
    QString currentUser = liud->getLogedInUserName();

    //qDebug() << "Person logged in is: " << currentUser;

    //balance user owns (pulling from user table fee column)
    double balance = dbb->getUserBalance(currentUser);

    //calculated balance SUM from userfees table
    double calcBalance = dbb->getBalanceFromUserFees(currentUser);


    //Tell Window How Much The Balance Is
    pfw->updateBalance(balance);

    pfw->currentUserLogedIn(currentUser);

    //Get db from dbb
    pfw->dbConnection(dbb->getDb());

    //Updating the database Fee column in the user
    QObject::connect(pfw, SIGNAL(OKButtonWasClicked(double, QString)), dbb, SLOT(updateUserFees(double, QString)));
    QObject::connect(pfw, SIGNAL(paymentButtonClicked(double,QString)), dbb, SLOT(updatePayHistory(double, QString)));

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
