#include "databasecontroller.h"
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>


DatabaseController::DatabaseController(){}




void DatabaseController::connect()
{
//    QSqlDatabase db = QSqlDatabase::database();

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("librarydb.cbaysurp13ui.us-west-1.rds.amazonaws.com");
    db.setDatabaseName("LibraryDB");
    db.setUserName("CECS491A");
    db.setPassword("CECS491A");

    if(!db.open())
    {
        qDebug() << db.lastError();
        //QMessageBox::critical(this, "Error", db.lastError().text());
    }
    else
    {
        qDebug() << "Connection Successful";
    }
}

void DatabaseController::disconnect()
{
    db.close();
}
