#include "editbookcontroller.h"

EditBookController::EditBookController(QObject *parent)
    : QAbstractItemModel(parent)
{
}



void EditBookController::run(MainWindow* mw, DatabaseBoundary* dbb)
{
    qDebug() << "Running Edit Book Controller";

/* TURN ON/OFF EDIT MODE */
    //if user edited a book then return the list of books edited
    QList<Frame*>* booksToEdit = mw->switchEditMode();

    qDebug() << "Books to edit are: " << booksToEdit;

    if(NULL != booksToEdit  && booksToEdit->size() > 0)
        //update the database
        dbb->updateBookQuantity(booksToEdit);

}















QVariant EditBookController::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex EditBookController::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex EditBookController::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int EditBookController::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int EditBookController::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant EditBookController::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
