#include "view_.h"
#include <QPushButton>

View_::View_(QObject *parent)
    : QAbstractItemModel(parent)
{
    mainWindow = new MainWindow;
    logInWindow = new LogInWindow;
    addUserWindow = new addnewuser;
    deleteUserWindow = new DeleteUser;
    this->setObjectName("Yo Mamma----------------------------------");

    QObject::connect(mainWindow->findChild<QPushButton*>("searchButton"), SIGNAL(clicked()), this, SIGNAL(searchButtonClicked()));//Search Button
    QObject::connect(mainWindow->findChild<QPushButton*>("logInButton"), SIGNAL(clicked()), this, SIGNAL(logInButtonClicked()));//Log In Button
    QObject::connect(mainWindow->findChild<QPushButton*>("editBookButton"), SIGNAL(clicked()), this, SIGNAL(editButtonClicked()));//Edit Button
    QObject::connect(mainWindow->findChild<QPushButton*>("deleteBookButton"), SIGNAL(clicked()), this, SIGNAL(deleteButtonClicked()));//Delete Button
    QObject::connect(mainWindow->findChild<QPushButton*>("addUserButton"), SIGNAL(clicked()), this, SIGNAL(addUserButtonClicked()));//Add User Button
    QObject::connect(mainWindow->findChild<QPushButton*>("payFeesButton"), SIGNAL(clicked()), this, SIGNAL(payFeesButtonClicked()));//Pay Fees Button
    QObject::connect(mainWindow->findChild<QPushButton*>("addBookButton"), SIGNAL(clicked()), this, SIGNAL(addBookButtonClicked())); //Add book
    QObject::connect(mainWindow->findChild<QPushButton*>("viewProfileButton"), SIGNAL(clicked()), this, SIGNAL(viewProfileButtonClicked())); //View Profile Button
    QObject::connect(mainWindow->findChild<QPushButton*>("deleteUserButton"), SIGNAL(clicked()), this, SIGNAL(deleteUserButtonClicked())); //View Profile Button
    QObject::connect(mainWindow->findChild<QPushButton*>("viewTransactionsButton"), SIGNAL(clicked()), this, SIGNAL(viewTransactionsButtonClicked())); // View Transactions Button
    QObject::connect(mainWindow->findChild<QPushButton*>("searchTransactionsButton"), SIGNAL(clicked()), this, SIGNAL(searchTransactionsButtonClicked())); // Search Transactions Button
}


void View_::executeMainWindow()
{
    mainWindow->show();
}

MainWindow* View_::getMainWindow(){return mainWindow;}

LogInWindow* View_::getLogInWindow(){return logInWindow;}

addnewuser* View_::getAddUserWindow(){return addUserWindow;}

PayFeesWindow* View_::getPayFeesWindow(){return payFeesWindow;}

EditUser* View_::getEditUserWindow(){return editUserWindow;}

DeleteUser* View_::getDeleteUserWindow(){return deleteUserWindow;}














QVariant View_::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex View_::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex View_::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int View_::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int View_::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant View_::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
