#ifndef SEARCHFORBOOKCONTROL_H
#define SEARCHFORBOOKCONTROL_H

#include <QAbstractItemModel>
#include "mainwindow.h"
#include <QVector>
#include "databaseboundary.h"

class SearchForBookControl : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit SearchForBookControl(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;


//Variables

    //QList<Book> queryResults;
    int numberOfResults;

//Functions
    //SearchForBookControl();      //Constructor
    void run(MainWindow*, DatabaseBoundary*);
    void setDatabaseSearchResults(QList<Book>);

signals:
    //zzzvoid searchForBooks(QStringList);

private:

};

#endif // SEARCHFORBOOKCONTROL_H
