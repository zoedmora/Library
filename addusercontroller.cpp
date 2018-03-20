#include "addusercontroller.h"
#include <QPushButton>



void AddUserController::run(MainWindow* mw, DatabaseBoundary* dbb)
{
    qDebug() << "Running Add User Control";

    addnewuser* auw = new addnewuser();

    //connection between add user window and this database boundary class
    QObject::connect(auw, SIGNAL(confirmButtonWasClicked(QStringList*)), dbb, SLOT(addUserToDatabase(QStringList*)));

    auw->exec();
}


AddUserController::AddUserController(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant AddUserController::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex AddUserController::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex AddUserController::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int AddUserController::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int AddUserController::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant AddUserController::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
