#include <QApplication>
#include "view_.h"
#include "presenter_.h"
#include "model_.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    View_* v = new View_();
    Model_* m = new Model_();
    Presenter_* p = new Presenter_(v, m);

    //For Search Button
    QObject::connect(v,SIGNAL(searchButtonClicked()), p, SLOT(search()));

    //For Log In Button
    QObject::connect(v, SIGNAL(logInButtonClicked()), p, SLOT(logIn_logOut()));

    //For Edit Book Button
    QObject::connect(v, SIGNAL(editButtonClicked()), p, SLOT(editBooks()));

    //For Delete Book Button
    QObject::connect(v, SIGNAL(deleteButtonClicked()), p, SLOT(deleteBooks()));



    //QObject::connect(v,SIGNAL(testSignal()), p, SLOT(testReceiver()));

    v->executeMainWindow();

    return a.exec();
}
