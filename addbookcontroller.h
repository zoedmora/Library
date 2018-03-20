#ifndef ADDBOOKCONTROLLER_H
#define ADDBOOKCONTROLLER_H

#include <QAbstractItemModel>
#include "loginwindow.h"
#include "mainwindow.h"
#include <QStringList>
#include <QDialogButtonBox>
#include "databaseboundary.h"


class addbookcontroller : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit addbookcontroller(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;


public:
    void run(MainWindow*, DatabaseBoundary*);
};

#endif // ADDBOOKCONTROLLER_H
