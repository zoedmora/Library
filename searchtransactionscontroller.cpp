#include "searchtransactionscontroller.h"

SearchTransactionsController::SearchTransactionsController(QObject *parent)
    : QAbstractItemModel(parent)
{
}

void SearchTransactionsController::run(MainWindow* mw, DatabaseBoundary* dbb)
{
    qDebug() << "Running Search Transactions Controller";

    //Window To Pay The Fees
    SearchTransactionsWindow* stw = new SearchTransactionsWindow();

    //Connecting Signals to Slots
    QObject::connect(stw, SIGNAL(OKButtonWasClicked(int)), dbb, SLOT(searchUserName(int)));
    QObject::connect(dbb, SIGNAL(SendUserNameToWindow(QString)), stw, SLOT(setCurrentUser(QString)));

    stw->exec();


}

QVariant SearchTransactionsController::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex SearchTransactionsController::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex SearchTransactionsController::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int SearchTransactionsController::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int SearchTransactionsController::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant SearchTransactionsController::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
