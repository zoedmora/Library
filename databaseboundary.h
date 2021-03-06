#ifndef DATABASEBOUNDARY_H
#define DATABASEBOUNDARY_H

#include <QAbstractItemModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QList>
#include "book.h"
#include <QSqlError>
#include <QString>
#include "frame.h"
#include "logedinuserdata.h"


class DatabaseBoundary : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit DatabaseBoundary(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;


//Functions
    void connect();
    void disconnect();
    QList<Book> runSelectQuery(QStringList);
    void updateBookQuantity(QList<Frame*>*);
    void runDeleteQuery(QStringList*);
    QList<Book> runLastSelectQuery();
    QStringList queryUserInfo(QString);
    double getUserBalance(QString);
    QSqlDatabase getDb(){return db;}
    double getTotalPayment(QString);


signals:
    void sendBalanceToPayWindow(QString);

public slots:
    void isUserAndPwdInDatabase(QStringList*);
    void addUserToDatabase(QStringList*);
    void Add_Book(QStringList*);
    void updateUserFees(double, QString);
    void editUserDatabase(QStringList*);
    void addBookScanner(QStringList*);
    void updatePayHistory(double, QString, QString);
    void searchUserName(int);
    void deleteUserInDatabase(QStringList*);
    void searchUserDatabase(QStringList*);
    void checkOut_In(QString, QStringList*);

private:
//Variables
    QSqlDatabase db;
    QSqlQuery query;
    QString queryString;//query string
    QString latestSearchQuery;

signals:
    void SendUserNameToWindow(QString);


};

#endif // DATABASEBOUNDARY_H
