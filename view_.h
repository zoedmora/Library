#ifndef VIEW__H
#define VIEW__H

#include <QAbstractItemModel>
#include <QDebug>
#include "mainwindow.h"
#include "loginwindow.h"
#include "addnewuser.h"
#include "payfeeswindow.h"
#include "edituser.h"
#include "deleteuser.h"

class View_ : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit View_(QObject *parent = nullptr);
    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    // Basic functionality:
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;



public:
//Functions
    void executeMainWindow();
    MainWindow* getMainWindow();//{return mainWindow;}
    LogInWindow* getLogInWindow();//{return logInWindow;}
    addnewuser* getAddUserWindow(); //{return addUserWindow;}
    PayFeesWindow* getPayFeesWindow();//{return payFeesWindow;}
    EditUser* getEditUserWindow();
    DeleteUser* getDeleteUserWindow();
    void hey(){qDebug() << "Its me!!!!!!!!!!!!!!!!!!!!!";}

signals:
    //void testSignal();
    void searchButtonClicked();
    void logInButtonClicked();
    void editButtonClicked();
    void deleteButtonClicked();
    void addUserButtonClicked();
    void payFeesButtonClicked();
    void addBookButtonClicked();
    void viewProfileButtonClicked();
    void deleteUserButtonClicked();
    void viewTransactionsButtonClicked();
    void searchTransactionsButtonClicked();
    void checkBookButtonClicked();


private:
//Variables
    MainWindow* mainWindow;
    LogInWindow* logInWindow;
    addnewuser* addUserWindow;
    PayFeesWindow* payFeesWindow;
    EditUser* editUserWindow;
    DeleteUser* deleteUserWindow;
};

#endif // VIEW__H
