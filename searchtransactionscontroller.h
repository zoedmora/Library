#ifndef SEARCHTRANSACTIONSCONTROLLER_H
#define SEARCHTRANSACTIONSCONTROLLER_H

#include <QAbstractItemModel>
#include "mainwindow.h"
#include "databaseboundary.h"
#include "searchtransactionswindow.h"

class SearchTransactionsController : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit SearchTransactionsController(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    //Functions
    void run(MainWindow*, DatabaseBoundary*);

private:
};

#endif // SEARCHTRANSACTIONSCONTROLLER_H
