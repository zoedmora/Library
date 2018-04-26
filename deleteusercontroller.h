#ifndef DELETEUSERCONTROLLER_H
#define DELETEUSERCONTROLLER_H

#include <QAbstractItemModel>
#include "deleteuser.h"
#include "mainwindow.h"
#include "databaseboundary.h"

class DeleteUserController : public QAbstractItemModel
{
    Q_OBJECT

public:
//Functions
    void run(MainWindow*, DatabaseBoundary*);

public:
    explicit DeleteUserController(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};

#endif // DELETEUSERCONTROLLER_H
