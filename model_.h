#ifndef MODEL__H
#define MODEL__H

#include <QAbstractItemModel>
#include "databaseboundary.h"

class Model_ : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit Model_(QObject *parent = nullptr);

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
    DatabaseBoundary* getDatabaseBoundary(){return databaseBoundary;}


public slots:
    //void doSearchQuery(QStringList);

private:
//Variables
    DatabaseBoundary* databaseBoundary;// = new DatabaseBoundary();
    //Presenter_* presenter_m;
};

#endif // MODEL__H
