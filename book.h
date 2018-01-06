#ifndef BOOK_H
#define BOOK_H

#include <QString>


class Book
{
public:
    QString title;
    QString author;
    QString genre;
    QString publisher;
    QString quantity;
    QString ISBN;
    Book();
    Book(QString,QString,QString,QString, QString = "",QString = "");
};

#endif // BOOK_H
