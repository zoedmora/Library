#include "login_logoutcontrol.h"
#include <QPushButton>



void LogIn_LogOutControl::run(MainWindow* mw, DatabaseBoundary* dbb, LogedInUserData* liud)
{
    qDebug() << "Running Log In Control";
    //qDebug() << "Person loged in is: " << liud->getLogedInUserName();

    LogInWindow* liw = new LogInWindow();

    //connection between log in window and this database boundary class
    QObject::connect(liw, SIGNAL(okButtonWasClicked(QStringList*)), dbb, SLOT(isUserAndPwdInDatabase(QStringList*)));

    //connection between log in window and this loged in user data class
    QObject::connect(liw, SIGNAL(sendUserName(QString)), liud, SLOT(saveUserName(QString)));

/* IF LOGED OUT (meaning button says loged in), OPEN CONFIMATION WINDOW */
    if(mw->isLogedIn() == false)
    {
        /* COMFIRM CREDENTIALS */
        //Open the Log In Window.  The log in window ask the user for infomation and does the verification.
        liw->exec();


        /* IF LOGGIN IS SUCCESSFUL */
        if(liw->isLogedIn() == true)
        {
            mw->setLogInStatus(true);
            mw->changeLogInButtonText(true);

            //un-hide the buttons that the user needs to see
            if(liw->isEmployeeAccount())
            {
                mw->unhideEmployeeUserButtons();
                mw->setEmployeeLogInStatus(true);
            }
            else
            {
                mw->unhideRegularUserButtons();
            }
        }
    }


/* ELSE IF USER IS ALREADY LOGED IN, THEN SIMPLY LOG OUT */
    else
    {
        mw->changeLogInButtonText(false);
        mw->setLogInStatus(false);
        mw->setEmployeeLogInStatus(false);
        mw->hideAllExtraButtons();

        //incase user was still on edit mode or delete mode, reset it to false
        if(mw->isOnEditMode())
            mw->resetOnEditMode();
        else if (mw->isOnDeleteMode())
            mw->resetOnDeleteMode();
    }

    qDebug() << "Triple Checking That The Username Stays Persistant: " << liud->getLogedInUserName();
}












LogIn_LogOutControl::LogIn_LogOutControl(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant LogIn_LogOutControl::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex LogIn_LogOutControl::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex LogIn_LogOutControl::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int LogIn_LogOutControl::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int LogIn_LogOutControl::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant LogIn_LogOutControl::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
