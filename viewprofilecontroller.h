#ifndef VIEWPROFILECONTROLLER_H
#define VIEWPROFILECONTROLLER_H
#include "mainwindow.h"
#include "databaseboundary.h"
#include "logedinuserdata.h"
#include "edituser.h"

#include <QAbstractItemModel>

class ViewProfileController : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit ViewProfileController(QObject *parent = nullptr);

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
    void run(MainWindow*, DatabaseBoundary*, LogedInUserData*);

private:
};

#endif // VIEWPROFILECONTROLLER_H
