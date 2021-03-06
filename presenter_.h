#ifndef PRESENTER__H
#define PRESENTER__H

#include <QAbstractItemModel>
#include <QDebug>
#include "view_.h"
#include "model_.h"
#include "searchforbookcontrol.h"
#include "login_logoutcontrol.h"
#include "editbookcontroller.h"
#include "deletebookcontroller.h"
#include "addusercontroller.h"
#include "payfeescontroller.h"
#include "addbookcontroller.h"
#include "viewprofilecontroller.h"
#include "deleteusercontroller.h"
#include "viewtransactionscontroller.h"
#include "searchtransactionscontroller.h"
#include "checkbookcontroller.h"

class Presenter_ : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit Presenter_(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
//Variables
    View_* view_p;
    Model_* model_p;
    SearchForBookControl* searchForBookControl;
    LogIn_LogOutControl * logIn_LogOutControl;
    EditBookController * editBookController;
    DeleteBookController* deleteBookController;
    AddUserController* addUserController;
    PayFeesController* payFeesController;
    addbookcontroller* addBookController;
    ViewProfileController* viewProfileController;
    ViewTransactionsController* viewTransactionsController;
    SearchTransactionsController* searchTransactionsController;
    DeleteUserController* deleteUserController;
    checkbookcontroller* checkBookController;

public:
//Functions
    Presenter_(View_*, Model_*); //Constructor
    SearchForBookControl* getSearchForBookControl(){return searchForBookControl;}
    AddUserController* getAddUserController(){return addUserController;}
signals:


public slots:
    void search();
    void logIn_logOut();
    void editBooks();
    void deleteBooks();
    void addUser();
    void payFees();
    void addBooks();
    void viewProfile();
    void viewTransactions();
    void searchTransactions();
    void deleteUser();
    void checkBook();

};

#endif // PRESENTER__H
