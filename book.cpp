#include "book.h"

Book::Book()
{

}

Book::Book(QString isbn, QString t, QString a, QString q, QString p, QString g)
{
    ISBN = isbn;
    title = t;
    author = a;
    quantity = q;
    publisher = p;
    genre = g;
}
