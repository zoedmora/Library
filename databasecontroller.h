#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

class DatabaseController
{
public:
    QSqlDatabase db;

    DatabaseController();
    void connect();
    void disconnect();
};

#endif // DATABASECONTROLLER_H
