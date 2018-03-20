#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
//#include "loginwindow.h"
#include <QGroupBox>
#include <QRadioButton>
#include <QLabel>
#include "book.h"
//#include "databaseboundary.h"
#include <QStringList>
#include <QList>
#include <QVBoxLayout>
#include "frame.h"


QT_BEGIN_NAMESPACE
class QComboBox;
class QDialogButtonBox;
class QGridLayout;
class QGroupBox;
class QLabel;
class QPushButton;
class QRadioButton;
QT_END_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

//Variables
    //LogInWindow* win = new LogInWindow();
    bool logedIn;
    bool searchMade;
    bool employeeLogedIn;
    bool onEditMode;
    bool onDeleteMode;
    double centerPointForWhiteFrame_Y;
    double centerPointForWhiteFrame_X;
    double originalHeightForWhiteFrame;
    QVBoxLayout* layoutForBookResults;
    QList<Frame*> bookResults;

//Functions
    ~MainWindow();
    QStringList getSearchCriteria();
    QWidget* getWhiteBackgroundWidget();
    QList<Frame*> getBookResults(){return bookResults;}
    void showResultsOnScreen(QList<Book>);
    void deleteOldResults();
    QString getButtonText(QString);
    QString setButtonText(QString);
    void changeLogInButtonText(bool);
    bool isLogedIn(){return logedIn;}
    void setLogInStatus(bool);
    void unhideEmployeeUserButtons();
    void unhideRegularUserButtons();
    void hideAllExtraButtons();
    bool isEmployeeLogedIn(){return employeeLogedIn;}
    void setEmployeeLogInStatus(bool);
    void hideCheckBoxesFromFrames();
    void unhideCheckBoxesFromFrames();
    bool isOnEditMode(){return onEditMode;}
    bool isOnDeleteMode(){return onDeleteMode;}
    void resetOnEditMode();
    void resetOnDeleteMode();
    void giveSearchWarning();
    QList<Frame*>* switchEditMode();
    QStringList* switchDeleteMode();
    void doingGood(){qDebug() << "Oh yeah.$$$$$$$$$$$$";}


signals:


private slots:


    //void on_deleteBookButton_clicked();

private:

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
