//Zoed
#include "mainwindow.h"
#include <QApplication>
#include "view.h"
#include "model.h"
#include "presenter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Model* m = new Model();
    View* v = new View();
    Presenter* p = new Presenter(v, m);


    // Charles Testing Slots
    QObject::connect(v,SIGNAL(pushButtonClicked()), p, SLOT(testSlot()));

    // Steven Test
    QObject::connect(v,SIGNAL(testClick()), p, SLOT(test()));

    // Brians Test
    QObject::connect(v,SIGNAL(brianTestClicked()), p, SLOT(brianTest()));

    // Zoed Test
    QObject::connect(v,SIGNAL(zoedTestClicked()), p, SLOT(zoedTesting()));


    v->executeMainWindow();

    //MainWindow w;
    //w.show();
    //something else
    return a.exec();
}
