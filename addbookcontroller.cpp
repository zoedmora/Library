#include "addbookcontroller.h"
#include "addbook.h"

addbookcontroller::addbookcontroller(QObject *parent)
    : QAbstractItemModel(parent)
{
}

void addbookcontroller::run(MainWindow* mw, DatabaseBoundary *dbb)
{
    qDebug() << "Running Add Book Controller";

    addbook* add_book = new addbook();
    add_book->show();

    QObject::connect(add_book, SIGNAL(okButtonWasClicked(QStringList*)), dbb, SLOT(Add_Book(QStringList*)));
}

QVariant addbookcontroller::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex addbookcontroller::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex addbookcontroller::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int addbookcontroller::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int addbookcontroller::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant addbookcontroller::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
