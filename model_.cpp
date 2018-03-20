#include "model_.h"

//Model_::Model_(Presenter_* p)
//{
//    presenter_m = p;

//    databaseBoundary = new DatabaseBoundary();
//}



//void Model_ ::doSearchQuery(QStringList inputs)
//{
//    qDebug() << "-------------------Making good progress";
//    //Presenter_* presenter = qobject_cast<Presenter_*>(sender());

//    databaseBoundary->runSelectQuery(inputs, presenter_m);
//}



//Model_::Model_



Model_::Model_(QObject *parent)
    : QAbstractItemModel(parent)
{
    databaseBoundary = new DatabaseBoundary();
}

QVariant Model_::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex Model_::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex Model_::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int Model_::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int Model_::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant Model_::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
