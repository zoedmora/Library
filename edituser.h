#ifndef EDITUSER_H
#define EDITUSER_H

#include <QDialog>
#include <QWidget>
#include <QDebug>
#include <QStringList>

namespace Ui {
class EditUser;
}

class EditUser : public QDialog
{
    Q_OBJECT

public:
    explicit EditUser(QWidget *parent = 0);
    ~EditUser();
    void changeNameText(QString);
    void changeIDText(QString);
    void changePasswordText(QString);
    void changefNameText(QString);
    void changelNameText(QString);
    void changeAddressText(QString);
    void changeCityText(QString);
    void changeZipText(QString);
    void changeEmailText(QString);
    void changePhoneText(QString);
    void reject();
    void accept();

signals:
    void confirmChangesButtonWasClicked(QStringList*);

private:
    Ui::EditUser *ui;
    QStringList* userInformation;
};

#endif // EDITUSER_H
