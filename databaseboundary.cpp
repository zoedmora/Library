#include "databaseboundary.h"
#include <QString>

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
    queryString = "SELECT * FROM LibraryDB.Book WHERE " + fieldOfSearch + "='" + name + "'";

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

void DatabaseBoundary::Add_Book(QStringList* bookInfo)
{
    qDebug() << "Adding book?";
    QString title = bookInfo->at(0);
    QString author = bookInfo->at(1);
    QString genre = bookInfo->at(2);
    QString publisher = bookInfo->at(3);
    QString ISBN = bookInfo->at(4);

    /*QString*/ queryString = QString();
    queryString = "INSERT INTO LibraryDB.Book(ISBN, Title, Author, Genre, Publisher)"
                  "VALUES('" + ISBN + "','" + title + "','" + author + "','" + genre + "','" + publisher + "')";

    /*QSqlQuery*/ query = QSqlQuery();

    qDebug() << "Query is: " << queryString;

    query.exec(queryString.toStdString().c_str());

    /*check if it worked */
    if(query.numRowsAffected() == 1)
    {
        qDebug() << "Letting user know that we have success.";
    }

    else
    {
        qDebug() << "The user has not been added.";
    }

}

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

void DatabaseBoundary::payUserFees(QString* paymentAmount)
{
     qDebug() << "Reached DB Boundary for paying fees.";

     //qDebug() << "payment amount: " << *paymentAmount;

     int paymentAmountInt = paymentAmount->toInt();
     int balanceInt = balance.toInt();
     int result = balanceInt - paymentAmountInt;
     if(result < 0){
         qDebug() << "paying too much!";
     }
     else {
         QString resultString = QString::number(result);
         //qDebug() << "result: " << resultString;
         queryString = "UPDATE LibraryDB.User SET fee= '" + resultString + "' WHERE userName = '" + userName + "'";
         query = QSqlQuery();
         query.exec(queryString.toStdString().c_str());
     }
}

QString DatabaseBoundary::getUserBalance(QString currentUser)
{
   queryString = "SELECT fee FROM LibraryDB.User WHERE userName = '" + currentUser + "'";
   query = QSqlQuery();
   query.exec(queryString.toStdString().c_str());
   query.next();
   QString fee = query.value(0).toString();
   userName = currentUser;
   balance = fee;
   return fee;
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
        queryString = "UPDATE LibraryDB.Book SET Quantity = '" + quantity + "' WHERE idBook = '" + bookId + "'";
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
    queryString = "DELETE FROM LibraryDB.Book WHERE idBook = ";

    //loop through all the books and delete them
    for(int i = 0; i < criteria->size(); i++)
    {
        //queryString += "'" + criteria->at(i) + "'";
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
