#include "deletebookcontroller.h"

DeleteBookController::DeleteBookController(QObject *parent)
    : QAbstractItemModel(parent)
{
}

void DeleteBookController::run(MainWindow* mw, DatabaseBoundary* dbb)
{
    qDebug() << "Running Delete Book Controller";

    /*  GET CRITERIA FROM MAIN WINDOW  */
    QStringList* booksToDelete = mw->switchDeleteMode();

    if(NULL != booksToDelete && booksToDelete->size() > 0)
    {
        qDebug() << "The stringlist is: ";
        for(int i = 0; i < booksToDelete->size(); i++)
        {
            qDebug() << booksToDelete->at(i);
        }


        /*  CALL THE DELETE QUERY  */
        //this deletes it from the database only
        dbb->runDeleteQuery(booksToDelete);


        /*  THEN CALL THE SEARCH QUERY FOR THE SAME BOOKS AGAIN SO THAT
         *  THE MAIN WINDOW UPDATES WITH THE NEWEST BOOKLIST */
        QList<Book> queryResults = dbb->runLastSelectQuery();


        /*  PUT INFORMATION FROM DATABASE ONTO THE WINDOW  */
        mw->showResultsOnScreen(queryResults);
    }
}





















QVariant DeleteBookController::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex DeleteBookController::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex DeleteBookController::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int DeleteBookController::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int DeleteBookController::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant DeleteBookController::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
