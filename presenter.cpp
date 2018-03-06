#include "presenter.h"
#include "view.h"
#include <QDebug>

Presenter::Presenter(View* v, Model* m)
{
    view_p = v;
    model_p = m;
}

void::Presenter::testSlot()
{
    // Enter in what the presenter should do here.
    qDebug() << "Charles Testing";
}

void::Presenter::test()
{
    qDebug() << "Steven Testing";
}

void::Presenter::brianTest()
{
    qDebug() << "Brian Testing";
}

void::Presenter::zoedTesting()
{
    qDebug() << "Zoed Testing";
}

















Presenter::Presenter(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QModelIndex Presenter::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex Presenter::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int Presenter::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int Presenter::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant Presenter::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
