#include "viewtransactionscontroller.h"

ViewTransactionsController::ViewTransactionsController(QObject *parent)
    : QAbstractItemModel(parent)
{
}

void ViewTransactionsController::run(MainWindow* mw, DatabaseBoundary* dbb, LogedInUserData* liud)
{
    qDebug() << "Running View Transactions Controller";

    //User ID of who ever is logged in
    QString currentUser = liud->getLogedInUserName();

    //Window To Pay The Fees
    viewtransactionswindow* vtw = new viewtransactionswindow(currentUser);

    //Send current user to window
    vtw->currentUserLogedIn(currentUser);

    vtw->exec();


}

QVariant ViewTransactionsController::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex ViewTransactionsController::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex ViewTransactionsController::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int ViewTransactionsController::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int ViewTransactionsController::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant ViewTransactionsController::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
