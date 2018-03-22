#ifndef LOGIN_LOGOUTCONTROL_H
#define LOGIN_LOGOUTCONTROL_H

#include <QAbstractItemModel>
#include "loginwindow.h"
#include "mainwindow.h"
#include <QStringList>
#include <QDialogButtonBox>
#include "databaseboundary.h"
#include "logedinuserdata.h"

class LogIn_LogOutControl : public QAbstractItemModel
{
    Q_OBJECT

private:
//Variables

public:
//Functions
    void run(MainWindow*, DatabaseBoundary*, LogedInUserData*);

public slots:
    //void checkCredentials(QStringList);




public:
    explicit LogIn_LogOutControl(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;





};

#endif // LOGIN_LOGOUTCONTROL_H
