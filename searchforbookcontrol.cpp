 #include "searchforbookcontrol.h"
#include "frame.h"
#include <QVBoxLayout>

//SearchForBookControl::SearchForBookControl()
//{
//}

void SearchForBookControl::run(MainWindow* mw, DatabaseBoundary* dbb)
{
    qDebug() << "Running Search For Book Control";
/* ONLY PROCEED IF EDIT MODE IS NOT ACTIVE */
   if(!mw->isOnEditMode())
   {
        /* DELETE OLD RESULTS SHOWN ON SCREEN */
        mw->deleteOldResults();


        /* GET SEARCH CRITERIA INFORMATION */
        QStringList searchCriteria = mw->getSearchCriteria();
        qDebug() << "This is what we were returned: " << searchCriteria[0] << " and " << searchCriteria[1];


        /* SEARCH FOR BOOKS IN DATABASE */
        QList<Book> queryResults = dbb->runSelectQuery(searchCriteria);//emit searchForBooks(searchCriteria);


        /* PUT INFORMATION FROM DATABASE ONTO THE WINDOW */
        mw->showResultsOnScreen(queryResults);
   }

/* ELSE TELL THE USER TO FININSH EDITING FIRST AND TRY AGAIN */
   else
   {
        mw->giveSearchWarning();
   }

}














SearchForBookControl::SearchForBookControl(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant SearchForBookControl::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex SearchForBookControl::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex SearchForBookControl::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int SearchForBookControl::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int SearchForBookControl::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant SearchForBookControl::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
