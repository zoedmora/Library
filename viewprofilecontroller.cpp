#include "viewprofilecontroller.h"


void ViewProfileController::run(MainWindow *mw, DatabaseBoundary *dbb, LogedInUserData *liud)
{
    qDebug() << "Running View Profile Controller";

    EditUser* eu = new EditUser();
    QString userName = liud->getLogedInUserName();

    // Pre-filling in all the textboxes in the Edit User Window with current information.
    QStringList userInfo = dbb->queryUserInfo(userName);
    eu->changeNameText(userInfo.at(1));
    eu->changeAddressText(userInfo.at(5));
    eu->changeCityText(userInfo.at(6));
    eu->changeEmailText(userInfo.at(7));
    eu->changefNameText(userInfo.at(3));
    eu->changeIDText(userInfo.at(0));
    eu->changelNameText(userInfo.at(4));
    eu->changePasswordText(userInfo.at(2));
    eu->changePhoneText(userInfo.at(9));
    eu->changeZipText(userInfo.at(8));

    QObject::connect(eu, SIGNAL(confirmChangesButtonWasClicked(QStringList*)), dbb, SLOT(editUserDatabase(QStringList*)));

    eu->exec();
}


ViewProfileController::ViewProfileController(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant ViewProfileController::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex ViewProfileController::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex ViewProfileController::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int ViewProfileController::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int ViewProfileController::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant ViewProfileController::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
