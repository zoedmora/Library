#include "view.h"
#include <QPushButton>

View::View(QObject *parent)
    : QAbstractItemModel(parent)
{
    mainWindow = new MainWindow;

    QObject::connect(mainWindow->findChild<QPushButton*>("pushButton"), SIGNAL(clicked()), this, SIGNAL(pushButtonClicked()));//Push Button
}

void View::executeMainWindow()
{
    mainWindow->show();
}


















QModelIndex View::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex View::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int View::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int View::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant View::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
