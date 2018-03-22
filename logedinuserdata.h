#ifndef LOGEDINUSERDATA_H
#define LOGEDINUSERDATA_H

#include <QAbstractItemModel>
#include <QDebug>
#include <QString>

class LogedInUserData : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit LogedInUserData(QObject *parent = nullptr);

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
    QString getLogedInUserName(){return userName;}
    void setLogedInUserName(QString user){userName = user;}

public slots:
    void saveUserName(QString);

private:
    //variables
    QString userName;

};

#endif // LOGEDINUSERDATA_H
