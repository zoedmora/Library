#ifndef DELETEUSER_H
#define DELETEUSER_H

#include <QDialog>

namespace Ui {
class DeleteUser;
}

class DeleteUser : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteUser(QWidget *parent = 0);
    QString getSearch();
    void changeNameText(QString);
    void changefNameText(QString);
    void changelNameText(QString);
    void changeAddressText(QString);
    void changeCityText(QString);
    void changeZipText(QString);
    void changeEmailText(QString);
    void changePhoneText(QString);
    void showButton();
    void reject();
    void accept();
    ~DeleteUser();

signals:
    void searchButtonWasClicked(QStringList*);
    void confirmButtonWasClicked(QStringList*);

private slots:
    void on_searchButton_clicked();

private:
    Ui::DeleteUser *ui;
    QStringList* idToSearch;
};

#endif // DELETEUSER_H
