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

    v->executeMainWindow();

    //MainWindow w;
    //w.show();
    //writing a comment before I push to see what happens
    return a.exec();
}
