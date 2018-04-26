#include "presenter_.h"
#include "view_.h"
#include "frame.h"


Presenter_::Presenter_(View_* v, Model_* m)
{
    view_p = v;
    model_p = m;
    searchForBookControl = new SearchForBookControl();
    logIn_LogOutControl = new LogIn_LogOutControl();
    editBookController = new EditBookController();
    deleteBookController = new DeleteBookController();
    addUserController = new AddUserController();
    payFeesController = new PayFeesController();
    addBookController = new addbookcontroller();
    viewProfileController = new ViewProfileController();
    viewTransactionsController = new ViewTransactionsController();
    searchTransactionsController = new SearchTransactionsController();
}

/**
 * @brief Presenter_::search
 * Gets called when search button is clicked in the Main Window
 */
void Presenter_::search()
{
/* RECORD THE SENDER THAT ACTIVATED THIS FUNCTION */

//    View_* view = qobject_cast<View_*>(sender());
//    qDebug() << "Sender is: " << view->objectName() << "<-";
//    qDebug() << "Presenter: testing...   testing...";

    qDebug() << "Presenter can see that SEARCH button was clicked";
/* CREATE AND RUN THE CONTROLLER FOR SEARCHING THE DATABASE FOR A BOOK */
    searchForBookControl->run(view_p->getMainWindow(), model_p->getDatabaseBoundary());
}

/**
 * @brief Presenter_::logIn_logOut
 * Gets called when the log in/ log out button is clicked
 */
void Presenter_::logIn_logOut()
{
    qDebug() << "Presenter can see that LOG IN / LOG OUT button was clicked.";
/* CREATE AND RUN THE CONTROLLER FOR LOGING IN OR LOGING OUT */
    logIn_LogOutControl->run(view_p->getMainWindow(), model_p->getDatabaseBoundary(), model_p->getLogedInUserData());
}

void Presenter_::editBooks()
{
    qDebug() << "Presenter can see that EDIT button was clicked.";
/* CREATE AND RUN THE CONTROLLER FOR EDITING BOOKS */
    editBookController->run(view_p->getMainWindow(), model_p->getDatabaseBoundary());
}

void Presenter_::deleteBooks()
{
    qDebug() << "Presenter can see that DELETE button was clicked.";
    /* CREATE AND RUN THE CONTROLLER FOR EDITING BOOKS */
    deleteBookController->run(view_p->getMainWindow(), model_p->getDatabaseBoundary());
}

void Presenter_::addUser()
{
    qDebug() << "Presenter can see that AddUser button was clicked.";
    /* CREATE AND RUN THE CONTROLLER FOR ADDING USERS */
    addUserController->run(view_p->getMainWindow(), model_p->getDatabaseBoundary());
}

void Presenter_::payFees()
{
    qDebug() << "Presenter can see that PAY FEES button was clicked.";
    /* CREATE AND RUN THE CONTROLLER FOR PAYING FEES */
    payFeesController->run(view_p->getMainWindow(), model_p->getDatabaseBoundary(), model_p->getLogedInUserData());
}

void Presenter_::addBooks()
{
    qDebug() << "Presenter can see that ADD button was clicked.";
    /* CREATE AND RUN THE CONTROLLER FOR ADDING BOOK */
    addBookController->run(view_p->getMainWindow(), model_p->getDatabaseBoundary());
}

void Presenter_::viewProfile()
{
    qDebug() << "Presenter can see that EDIT button was clicked.";
    /* CREATE AND RUN THE CONTROLLER FOR EDITING PROFILE */
    viewProfileController->run(view_p->getMainWindow(), model_p->getDatabaseBoundary(), model_p->getLogedInUserData());
}

void Presenter_::viewTransactions()
{
    qDebug() << "Presenter can see that View Transactions button was clicked.";
    /* CREATE AND RUN THE CONTROLLER FOR EDITING PROFILE */
    viewTransactionsController->run(view_p->getMainWindow(), model_p->getDatabaseBoundary(), model_p->getLogedInUserData());
}

void Presenter_::searchTransactions()
{
    qDebug() << "Presenter can see that Search Transactions button was clicked.";
    /* CREATE AND RUN THE CONTROLLER FOR EDITING PROFILE */
    searchTransactionsController->run(view_p->getMainWindow(), model_p->getDatabaseBoundary());
}
















Presenter_::Presenter_(QObject *parent)
    : QAbstractItemModel(parent){}


QVariant Presenter_::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex Presenter_::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex Presenter_::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int Presenter_::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int Presenter_::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant Presenter_::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
