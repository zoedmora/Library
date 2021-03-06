#include "databaseboundary.h"
#include <QString>
#include <QTime>

DatabaseBoundary::DatabaseBoundary(QObject *parent)
    : QAbstractItemModel(parent)
{
    connect();
    query =  QSqlQuery();
    //otherQuery = new QSqlQuery();
    queryString = QString();
}

void DatabaseBoundary::connect()
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

void DatabaseBoundary::disconnect()
{
    db.close();
}

QStringList DatabaseBoundary::queryUserInfo(QString userName)
{
    qDebug() << "Querying User Information";
    qDebug() << userName;
    queryString = "SELECT * FROM LibraryDB.User WHERE userName = '" + userName + "'";
    query.exec(queryString.toStdString().c_str());
    QStringList userInfo;
    qDebug() << query.lastQuery();

    while (query.next())
    {
        userInfo << query.value(0).toString();
        userInfo << query.value(1).toString();
        userInfo << query.value(2).toString();
        userInfo << query.value(3).toString();
        userInfo << query.value(4).toString();
        userInfo << query.value(5).toString();
        userInfo << query.value(6).toString();
        userInfo << query.value(7).toString();
        userInfo << query.value(8).toString();
        userInfo << query.value(9).toString();
    }

    if (query.numRowsAffected() > 0)
        qDebug() << "User found.";

    return userInfo;
}

QList<Book> DatabaseBoundary::runSelectQuery(QStringList criteria)
{
    qDebug() << "Running Select Query";


/* CREATE AND EXECUTE QUERY */
    //input from the user (ie. main window)
    QString name = criteria[0];
    QString fieldOfSearch = criteria[1];

    //forming the query string
    queryString = "SELECT * FROM LibraryDB.Book WHERE " + fieldOfSearch + " LIKE '%" + name + "%'";

    //saving this query so that we can keep track of the last search query executed
    latestSearchQuery = queryString;

    //executing query
    query.exec(queryString.toStdString().c_str());


/* TRAVERSE THROUGH THE RESULTS AND RECORD THEM */
    //create list to hold all the books returned
    QList<Book> listOfBooks;

    //add all results to the list
    while (query.next())
    {
        QString Id = query.value(0).toString();// + " " + query.value(1).toString();
        QString Title = query.value(1).toString();
        QString Author = query.value(2).toString();
        QString Quantity = query.value(3).toString();
        QString Genre = query.value(4).toString();
        QString Publisher = query.value(5).toString();

        listOfBooks.append(Book(Id, Title, Author, Quantity, Publisher, Genre));
        qDebug() << Id << "*" << Title << "*" << Author;
    }
    qDebug() << "Last query: " << query.lastQuery();


    if(query.numRowsAffected() > 0)
        qDebug() << "Lets print the top of the list to make sure we have it right: " << listOfBooks.first().title;


/* RETURN LIST */
    return listOfBooks;

}

void DatabaseBoundary::Add_Book(QStringList* bookInfo)
{
    qDebug() << "Checking if book is already inside?";
    /*QString*/ queryString = QString();
    QString ISBN = bookInfo->at(4);
    queryString = "SELECT * FROM LibraryDB.Book WHERE ISBN = '" + ISBN + "';";
    query.exec(queryString.toStdString().c_str());

    if(query.numRowsAffected() > 0)
    {
        queryString = "UPDATE LibraryDB.Book SET Quantity = Quantity + 1 WHERE ISBN = '" + ISBN + "';";

        /*QSqlQuery*/ query = QSqlQuery();

        qDebug() << "Query is: " << queryString;

        query.exec(queryString.toStdString().c_str());

        /*check if it worked */
        if(query.numRowsAffected() == 1)
        {
            qDebug() << "Letting user know that we have success.";
            bookInfo->append("*");
        }

        else
        {
            qDebug() << "The book has not been added.";
        }
    }

    else {
        qDebug() << "Adding book?";
        QString title = bookInfo->at(0);
        QString author = bookInfo->at(1);
        QString genre = bookInfo->at(2);
        QString publisher = bookInfo->at(3);
        QString ISBN = bookInfo->at(4);

        queryString = "INSERT INTO LibraryDB.Book(ISBN, Title, Author, Genre, Publisher)"
                      "VALUES('" + ISBN + "','" + title + "','" + author + "','" + genre + "','" + publisher + "')";

        /*QSqlQuery*/ query = QSqlQuery();

        qDebug() << "Query is: " << queryString;

        query.exec(queryString.toStdString().c_str());

        /*check if it worked */
        if(query.numRowsAffected() == 1)
        {
            qDebug() << "Letting user know that we have success.";
            bookInfo->append("*");
        }

        else
        {
            qDebug() << "The book has not been added.";
        }
    }
}

void DatabaseBoundary::addBookScanner(QStringList* isbnInfo)
{
      qDebug() << "Adding book with scanner?";
      QString isbn = isbnInfo->at(0);
      queryString = "UPDATE LibraryDB.Book SET Quantity = Quantity + 1 WHERE ISBN = '" + isbn + "';";

      /*QSqlQuery*/ query = QSqlQuery();

      qDebug() << "Query is: " << queryString;

      query.exec(queryString.toStdString().c_str());

      /*check if it worked */
      if(query.numRowsAffected() == 1)
      {
        qDebug() << "Letting user know that we have success.";
        isbnInfo->append("*");
      }

      else
      {
        qDebug() << "The book has not been added.";
      }
}

void DatabaseBoundary::checkOut_In(QString userName, QStringList* isbnInfo)
{
     qDebug() << "Checking In/Out book";
     QString isbn = isbnInfo->at(0);
     QString date = QDate::currentDate().toString();
     QString status_in = "in";
     QString status_out = "out";
     QString title;
     QString id;
     /*QSqlQuery*/ query = QSqlQuery();

     queryString = "SELECT idUser FROM LibraryDB.User WHERE userName= '" + userName + "';";

     qDebug() << "Query is: " << queryString;

     query.exec(queryString.toStdString().c_str());

     while (query.next())
     {
         id = query.value(0).toString();
     }

     queryString = "SELECT Title FROM LibraryDB.Book WHERE ISBN= '" + isbn+ "';";

     qDebug() << "Query is: " << queryString;

     query.exec(queryString.toStdString().c_str());

     while (query.next())
     {
         title = query.value(0).toString();
     }

     queryString = "SELECT count(*) FROM LibraryDB.TransactionHistory WHERE (userName = '" + userName + "'AND bookTitle = '" + title +"')";
     qDebug() << "Query is: " << queryString;
     query.exec(queryString.toStdString().c_str());
     query.next();

     //2 results means book is returned by user, can "check out same book again"
     if(query.value(0).toInt() % 2 == 0 )
     {
         //Check if book is in stock
         queryString = "SELECT Quantity FROM LibraryDB.Book WHERE Title = '" + title + "';";
         qDebug() << "Query is: " << queryString;
         query.exec(queryString.toStdString().c_str());
         query.next();

         if(query.value(0).toInt() > 0)
         {
             qDebug() << "Check out.";
             queryString = "INSERT INTO LibraryDB.TransactionHistory(idUser, userName, bookTitle, transactionType, date)"
                                        "VALUES('"+ id + "','" + userName + "','" + title + "','" + status_out + "','" + date + "')";
             qDebug() << "Query is: " << queryString;
             query.exec(queryString.toStdString().c_str());

             queryString = "UPDATE LibraryDB.Book SET Quantity = Quantity - 1 WHERE ISBN = '" + isbn + "';";
             qDebug() << "Query is: " << queryString;
             query.exec(queryString.toStdString().c_str());

             /*check if it worked */
             if(query.numRowsAffected() == 1)
             {
               qDebug() << "Letting user know that we have success.";
               isbnInfo->append("*");
             }
             else
             {
               qDebug() << "Check Out Failed.";
             }
         }

         else
         {
             qDebug() << "Failed quantity is 0. Cannot check out.";
             isbnInfo->append("X");
         }
     }
     else if (query.value(0).toInt() % 2 == 1)
     {

         qDebug() << "Check In.";
         queryString = "INSERT INTO LibraryDB.TransactionHistory(idUser, userName, bookTitle, transactionType, date)"
                                        "VALUES('"+ id + "','" + userName + "','" + title + "','" + status_in + "','" + date + "')";
         qDebug() << "Query is: " << queryString;
         query.exec(queryString.toStdString().c_str());
         queryString = "UPDATE LibraryDB.Book SET Quantity = Quantity + 1 WHERE ISBN = '" + isbn + "';";
         qDebug() << "Query is: " << queryString;
         query.exec(queryString.toStdString().c_str());
         /*check if it worked */
         if(query.numRowsAffected() == 1)
         {
            qDebug() << "Letting user know that we have success.";
            isbnInfo->append("/");
         }
         else
         {
            qDebug() << "Check In Failed.";
         }
     }
}

//     queryString = "INSERT INTO LibraryDB.CheckIn_Out(userName, ISBN, Date, Status)"
//                           "VALUES('" + userName + "','" + isbn + "','" + date + "','" + status_in + "')";



//     qDebug() << "Query is: " << queryString;

//     query.exec(queryString.toStdString().c_str());

//     /*check if it worked */
//     if(query.numRowsAffected() == 1)
//     {
//       qDebug() << "Letting user know that we have success.";
//       isbnInfo->append("*");
//     }

void DatabaseBoundary::editUserDatabase(QStringList *userInfo)
{
    qDebug() << "Reached DB Boundary for editing user.";

    QString id = userInfo->at(0);
    QString password = userInfo->at(1);
    QString accountName = userInfo->at(2);
    QString fName = userInfo->at(3);
    QString lName = userInfo->at(4);
    QString address = userInfo->at(5);
    QString city = userInfo->at(6);
    QString zip = userInfo->at(7);
    QString email = userInfo->at(8);
    QString phone = userInfo->at(9);

    // Form query string
    queryString = "UPDATE LibraryDB.User SET first_name = '" + fName + "', last_name = '" + lName + "', password = '" +
            password + "', userName = '" + accountName + "', address = '" + address + "', city = '" + city + "', zip = '" +
            zip + "', email = '" + email + "', phone = '" + phone + "', idUser = '" + id + "' WHERE idUser = '" + id + "';";

    query = QSqlQuery();
    query.exec(queryString.toStdString().c_str());

    if(query.numRowsAffected() == 1)
    {
        qDebug() << "Letting user know that we have success.";
    }

    else
    {
        qDebug() << "The user has not been added.";
    }
}

void DatabaseBoundary::searchUserDatabase(QStringList* userID)
{
    qDebug() << "Reach DB Boundary for searching users via ID.";

    QString id = userID->at(0);

    queryString = "SELECT * FROM LibraryDB.User WHERE idUser = '" + id + "'";
    query.exec(queryString.toStdString().c_str());
    qDebug() << query.lastQuery();

    while (query.next())
    {
        userID->append(query.value(0).toString());
        userID->append(query.value(1).toString());
        userID->append(query.value(2).toString());
        userID->append(query.value(3).toString());
        userID->append(query.value(4).toString());
        userID->append(query.value(5).toString());
        userID->append(query.value(6).toString());
        userID->append(query.value(7).toString());
        userID->append(query.value(8).toString());
        userID->append(query.value(9).toString());
    }

    if (query.numRowsAffected() > 0)
        qDebug() << "User found.";

}

void DatabaseBoundary::deleteUserInDatabase(QStringList *userID)
{
    qDebug() << "Deleting User in Database";

    QString id = userID->at(0);

    queryString = "DELETE FROM LibraryDB.User WHERE idUser = " + id + ";";
    query = QSqlQuery();
    query.exec(queryString.toStdString().c_str());

    if(query.numRowsAffected() == 1)
    {
        qDebug() << "Letting user know that we have success.";
    }

    else
    {
        qDebug() << "The user has not been added.";
    }
}

void DatabaseBoundary::searchUserName(int userID)
{
    //Getting username with their id and emitting a signal back to searchTransactionsWindow
    queryString = "SELECT userName from User WHERE idUser like '" + QString::number(userID) + "'";
    query = QSqlQuery();
    query.exec(queryString.toStdString().c_str());
    query.next();
    QString userName = query.value(0).toString();
    emit SendUserNameToWindow(userName);
}

void DatabaseBoundary::addUserToDatabase(QStringList* userInfo)
{
    qDebug() << "Reached DB Boundary for adding user.";

    QString id = userInfo->at(0);
    QString password = userInfo->at(1);
    QString accountName = userInfo->at(2);
    QString fName = userInfo->at(3);
    QString lName = userInfo->at(4);
    QString address = userInfo->at(5);
    QString city = userInfo->at(6);
    QString zip = userInfo->at(7);
    QString email = userInfo->at(8);
    QString phone = userInfo->at(9);

    // Form query string
    queryString = "INSERT INTO LibraryDB.User (userName, idUser, password, first_name, last_name,"
                  " address, city, email, zip, phone) VALUES ('" + accountName + "', '" + id + "', '" +
                  password + "', '" + fName + "', '" + lName + "', '" + address + "', '" + city + "', '" +
                  email + "', '" + zip + "', '" + phone + "');";

    query = QSqlQuery();
    query.exec(queryString.toStdString().c_str());

    if(query.numRowsAffected() == 1)
    {
        qDebug() << "Letting user know that we have success.";
    }

    else
    {
        qDebug() << "The user has not been added.";
    }
}

double DatabaseBoundary::getUserBalance(QString currentUser)
{
    //Getting balance SUM from UserFess Table
    queryString = "SELECT SUM(Amount) FROM UserFees WHERE userName LIKE '" + currentUser + "'";
    query = QSqlQuery();
    query.exec(queryString.toStdString().c_str());
    query.next();
    double balance = query.value(0).toDouble();


    queryString = "UPDATE LibraryDB.User SET fee= '" + QString::number(balance) + "' WHERE userName = '" + currentUser + "'";
    query = QSqlQuery();
    query.exec(queryString.toStdString().c_str());


   //Getting balance from User table fees column
   queryString = "SELECT fee FROM LibraryDB.User WHERE userName = '" + currentUser + "'";
   query = QSqlQuery();
   query.exec(queryString.toStdString().c_str());
   query.next();

   qDebug() << "Fee is: " << query.value(0).toDouble();

   double fee = query.value(0).toDouble();

   return fee;
}

void DatabaseBoundary::updateUserFees(double balance, QString userName)
{
     //Updating balance to db
     qDebug() << "Reached DB Boundary for paying fees amounting to: " << balance;

     queryString = "UPDATE LibraryDB.User SET fee= '" + QString::number(balance) + "' WHERE userName = '" + userName + "'";
     query = QSqlQuery();
     query.exec(queryString.toStdString().c_str());
}

double DatabaseBoundary::getTotalPayment(QString currentUser)
{
    //Getting total payment amount of current user
    queryString = "SELECT SUM(paidAmount) FROM PayHistory WHERE userName LIKE '" + currentUser + "'";
    query = QSqlQuery();
    query.exec(queryString.toStdString().c_str());
    query.next();
    double totalPayment = query.value(0).toDouble();
    return totalPayment;
}

void DatabaseBoundary::updatePayHistory(double paidAmount, QString userName, QString date)
{
    //Inserting payments into PayHistory Table
    queryString = "INSERT INTO LibraryDB.PayHistory (userName, paidAmount, date) VALUES ('" + userName + "', '" + QString::number(paidAmount) + "', '" + date + "')";
    query = QSqlQuery();
    query.exec(queryString.toStdString().c_str());
}

void DatabaseBoundary::isUserAndPwdInDatabase(QStringList* nameAndPwd)
{
    qDebug() << "About to see if the following are in the database: " << nameAndPwd->at(0) << nameAndPwd->at(1);

/* CREATE AND EXECUTE QUERY */
    //input from the user
    QString userName = nameAndPwd->at(0);//->front();  nameAndPwd->pop_front();
    QString password = nameAndPwd->at(1);//front(); nameAndPwd->pop_front();

    //forming the query string
    /*QString*/ queryString = QString();
    queryString = "SELECT * FROM LibraryDB.User WHERE userName = '" + userName + "' AND password = '" + password + "'";

    //executing query
    /*QSqlQuery*/ query = QSqlQuery();
    query.exec(queryString.toStdString().c_str());


/* RETURN SUCCESS OR FAILURE */
    if(query.numRowsAffected() == 1)
    {
        qDebug() << "Letting user know that we have success.";
        nameAndPwd->append("*");

        //this is to let the Log-In Window know that this was an employer
        //because employers have to have a username that starts with "_"
        if(userName.at(0)  == "_")
        {
            nameAndPwd->append("_");
            qDebug() << "The log in was from an employer";
        }
    }
}

void DatabaseBoundary::updateBookQuantity(QList<Frame*>* books)
{
    qDebug() << "Updating book quantities.  These many where affected: " << books->size();

    QString bookId;
    QString quantity;

    for(int i = 0; i < books->size(); i++)
    {
        /* CREATE AND EXECUTE QUERY */
        //input from user (ie.main window)
        bookId = books->at(i)->book->ISBN;
        quantity = books->at(i)->book->quantity;

        //forming the query string
        queryString = QString();
        queryString = "UPDATE LibraryDB.Book SET Quantity = '" + quantity + "' WHERE ISBN = '" + bookId + "'";
        //UPDATE `LibraryDB`.`Book` SET `Quantity`='2' WHERE `idBook`='0';

        qDebug() << "Printing the query string: " << queryString;
        //executong query
        query = QSqlQuery();
        query.exec(queryString.toStdString().c_str());
    }

    qDebug() << "Last query: " << query.lastQuery();

    if(query.numRowsAffected() > 0)
        qDebug() << "Number of rows affected: " << query.numRowsAffected();
}

void DatabaseBoundary::runDeleteQuery(QStringList* criteria)
{
    qDebug() << "Running Delete Query From Database Boundary";

    /*  CREATE AND EXECUTE QUERY  */
    QString queryString;

    //forming query string
    queryString = "DELETE FROM LibraryDB.Book WHERE ISBN = ";

    //loop through all the books and delete them
    for(int i = 0; i < criteria->size(); i++)
    {
        //queryString += "'" + criteria->at(i) + "'";
        qDebug() << "Query is: " << queryString + "'" + criteria->at(i) + "'";
        query.exec((queryString + "'" + criteria->at(i) + "'").toStdString().c_str());
    }

}

QList<Book> DatabaseBoundary::runLastSelectQuery()
{
    /*  EXECUTE LAST SEARCH QUERY WE HAVE SAVED  */
    query.exec(latestSearchQuery.toStdString().c_str());


    /* TRAVERSE THROUGH THE RESULTS AND RECORD THEM */
        //create list to hold all the books returned
        QList<Book> listOfBooks;

        //add all results to the list
        while (query.next())
        {
            QString Id = query.value(0).toString();// + " " + query.value(1).toString();
            QString Title = query.value(1).toString();
            QString Author = query.value(2).toString();
            QString Quantity = query.value(3).toString();
            /*needs more*/ //need to add the publisher and the genre and stuff

            listOfBooks.append(Book(Id, Title, Author, Quantity));
            qDebug() << Id << "*" << Title << "*" << Author;
        }
        qDebug() << "Last query: " << query.lastQuery();


        if(query.numRowsAffected() > 0)
            qDebug() << "Lets print the top of the list to make sure we have it right: " << listOfBooks.first().title;


    /* RETURN LIST */
        return listOfBooks;
}

QVariant DatabaseBoundary::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex DatabaseBoundary::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex DatabaseBoundary::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int DatabaseBoundary::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int DatabaseBoundary::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant DatabaseBoundary::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
