#include "checkbookcontroller.h"
#include "checkbook.h"
#include "logedinuserdata.h"

checkbookcontroller::checkbookcontroller(QObject *parent)
    : QAbstractItemModel(parent)
{
}

void checkbookcontroller::run(MainWindow* mw, DatabaseBoundary *dbb, LogedInUserData* liud)
{
    qDebug() << "Running Check Book Controller";

    qDebug() << "User logged in is: " + liud->getLogedInUserName();

    QString currentUser = liud->getLogedInUserName();

    checkbook* check_book = new checkbook(currentUser);
    check_book->show();

    //okbutton clicked
    QObject::connect(check_book, SIGNAL(confirmCheckButtonWasClicked(QString, QStringList*)), dbb, SLOT(checkOut_In(QString, QStringList*)));


}

QVariant checkbookcontroller::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex checkbookcontroller::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex checkbookcontroller::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int checkbookcontroller::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int checkbookcontroller::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant checkbookcontroller::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}


