#include "deleteusercontroller.h"

void DeleteUserController::run(MainWindow *mw, DatabaseBoundary *dbb)
{
    qDebug() << "Running Delete User Controller";

    DeleteUser* duw = new DeleteUser();

    // QObject::connect(duw->findChild<QPushButton*>("searchButton"), SIGNAL(clicked()), this, SIGNAL(deleteUserButtonClicked()));

    QObject::connect(duw, SIGNAL(searchButtonWasClicked(QStringList*)), dbb, SLOT(searchUserDatabase(QStringList*)));
    QObject::connect(duw, SIGNAL(confirmButtonWasClicked(QStringList*)), dbb, SLOT(deleteUserInDatabase(QStringList*)));
    duw->exec();
}

DeleteUserController::DeleteUserController(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant DeleteUserController::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex DeleteUserController::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex DeleteUserController::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int DeleteUserController::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int DeleteUserController::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant DeleteUserController::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
