#include "logedinuserdata.h"

LogedInUserData::LogedInUserData(QObject *parent)
    : QAbstractItemModel(parent)
{
    userName = "no loged in user";
}

void LogedInUserData::saveUserName(QString name)
{
    qDebug() << "Persistantly saving username: " << name;
    userName = name;
}





QVariant LogedInUserData::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex LogedInUserData::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex LogedInUserData::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int LogedInUserData::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int LogedInUserData::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant LogedInUserData::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
