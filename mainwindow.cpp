#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
#include <QCheckBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    logedIn = false;
    employeeLogedIn = false;
    onEditMode = false;
    onDeleteMode = false;
    ui->setupUi(this);

    //Signal and Slot Connection between main window and log-in window
    //QObject::connect(win, SIGNAL(logedIn()), this, SLOT(changeLogInLabel()));

    //Fill Main Window background with an image
//    QPixmap bkgnd("/Users/zoedmora/Qt/Projects/SeniorProject/books.jpg");
//    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
//    palette.setBrush(QPalette::Background, bkgnd);
//    this->setPalette(palette);

    //Configure white frame containing the search bar
    palette.setBrush(QPalette::Background, Qt::white);
    ui->whiteFrame->setAutoFillBackground(true);
    ui->whiteFrame->setPalette(palette);

    //Configure vertical layout to show the books found in a vertical fashion
    layoutForBookResults = new QVBoxLayout();
    ui->bookFrameBoundary->setLayout(layoutForBookResults);

    //Configure book frame under search bar
    palette.setBrush(QPalette::Background, Qt::white);
    ui->bookFrameBoundary->setAutoFillBackground(true);
    ui->bookFrameBoundary->setPalette(palette);
    ui->bookFrameBoundary->setVisible(false);

    //Hide top buttons that are only used once a user is loged in
    ui->addBookButton->hide();
    ui->editBookButton->hide();
    ui->deleteBookButton->hide();
    ui->addUserButton->hide();
    ui->payFeesButton->hide();
}

/**
 * @brief MainWindow::~MainWindow
 * Destrustor
 */
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::changeLogInButtonText(bool b)
{
    if(b)
        ui->logInButton->setText("Log Out");
    else
        ui->logInButton->setText("Log In");
}



//void MainWindow::on_searchButton_clicked()
/**
 * @brief MainWindow::deleteOldResults
 * Removes old book results from main window
 */
void MainWindow::deleteOldResults()
{
    //Delete previous books shown on the Main Window
    if(searchMade == true)
    {
        QLayoutItem *item = NULL;
        while ((item = ui->bookFrameBoundary->layout()->takeAt(0)) != 0)
        {
            delete item->widget();
        }
    }
}



/**
 * @brief MainWindow::getSearchCriteria
 * @return information from earch bar
 */
QStringList MainWindow::getSearchCriteria()
{
    QStringList criteria;

    //text in search bar  +   search option (ie. tittle, author, genre)
    return criteria << ui->searchBar->text() << ui->searchComboBox->currentText();
}

QWidget* MainWindow::getWhiteBackgroundWidget()
{
    return ui->whiteFrame;
}

/**
 * @brief MainWindow::showResultsOnScreen
 * @param list of books matching search criteria
 */
void MainWindow::showResultsOnScreen(QList<Book> list)
{
    int listSize = list.size();

    if(listSize > 0)
    {
        //alert that a search has been made
        searchMade = true;

        //clear the old stuuf
        bookResults.clear();
        deleteOldResults();

        //create one frame per book result
        for(int i = 0; i < list.size(); i++)
        {
            Frame* temp = new Frame();
            temp->findChild<QLabel*>("isbnValue")->setText(list.at(i).ISBN);                //temp->book->ISBN = list.at(i).ISBN; //((QLabel*) temp->children().at(2))->setText(list.at(i).ISBN);
            temp->findChild<QLabel*>("titleValue")->setText(list.at(i).title);              //temp->book->title = list.at(i).title; //((QLabel*) temp->children().at(0))->setText(list.at(i).tittle);
            temp->findChild<QLabel*>("authorValue")->setText(list.at(i).author);            //temp->book->author = list.at(i).author;   //((QLabel*) temp->children().at(1))->setText(list.at(i).author);
            temp->findChild<QLineEdit*>("quantityLineEdit")->setText(list.at(i).quantity);  //temp->book->quantity = list.at(i).quantity;
            temp->setBook(list.at(i).ISBN, list.at(i).title, list.at(i).author, list.at(i).quantity);

            //add each frame to layout
            layoutForBookResults->addWidget(temp);
            bookResults.append(temp);
        }

        //allow us to see results
        ui->bookFrameBoundary->setVisible(true);
    }
}

QString MainWindow::getButtonText(QString s)
{
    return ui->logInButton->text();
}

void MainWindow::setLogInStatus(bool b)
{
    logedIn = b;
}

void MainWindow::setEmployeeLogInStatus(bool b)
{
    employeeLogedIn = b;
}

void MainWindow::unhideEmployeeUserButtons()
{
    ui->addBookButton->show();
    ui->editBookButton->show();
    ui->deleteBookButton->show();
    ui->addUserButton->show();
}

void MainWindow::unhideRegularUserButtons()
{
    ui->addUserButton->show();
    ui->payFeesButton->show();
}

void MainWindow::hideAllExtraButtons()
{
    ui->addBookButton->hide();
    ui->editBookButton->hide();
    ui->deleteBookButton->hide();
    ui->addUserButton->hide();
    ui->payFeesButton->hide();
}

void MainWindow::hideCheckBoxesFromFrames()
{
    for(int i = 0; i < bookResults.size(); i++)
    {
        bookResults.at(i)->findChild<QCheckBox*>("checkBox")->setVisible(false);
    }
}

void MainWindow::unhideCheckBoxesFromFrames()
{
    qDebug() << "Size of book results is: " << bookResults.size();
    for(int i = 0; i < bookResults.size(); i++)
    {
        //if(NULL != bookResults.at(i)->findChild<QCheckBox*>("checkBox"))
            bookResults.at(i)->findChild<QCheckBox*>("checkBox")->setVisible(true);
    }
}

void MainWindow::resetOnEditMode()
{
    qDebug() << "Reseting onEditMode";

    ui->editBookButton->setText("Edit");

    onEditMode = false;
    QLineEdit* quantityLine;
    QPalette palette = QPalette();
    palette.setColor(QPalette::Base,Qt::transparent);

    for(int i = 0; i < bookResults.size(); i++)
    {
        quantityLine = bookResults.at(i)->findChild<QLineEdit*>("quantityLineEdit");
        quantityLine->setReadOnly(true);
        quantityLine->setPalette(palette);

        bookResults.at(i)->findChild<QCheckBox*>("checkBox")->setChecked(false);
        bookResults.at(i)->findChild<QCheckBox*>("checkBox")->setVisible(false);
    }

    ui->searchBar->setPalette(palette); //transparent background
    palette.setColor(QPalette::Text, Qt::black);
    ui->searchBar->setPalette(palette); //black text
    ui->searchBar->setText("");
}

void MainWindow::resetOnDeleteMode()
{
    qDebug() << "Reseting onDeleteMode";

    ui->deleteBookButton->setText("Delete");

    onDeleteMode = false;
    QPalette palette = QPalette();
    palette.setColor(QPalette::Base, Qt::lightGray);

    for(int i = 0; i < bookResults.size(); i++)
    {
        bookResults.at(i)->setPalette(palette);
        bookResults.at(i)->findChild<QCheckBox*>("checkBox")->setChecked(false);
        bookResults.at(i)->findChild<QCheckBox*>("checkBox")->setVisible(false);
    }
}

QList<Frame*>* MainWindow::switchEditMode()
{
    qDebug() << "Changing Edit Mode";

    if(bookResults.size() <= 0)
    {
        qDebug() << "Getting out";
        return NULL;
    }

    QPalette palette = QPalette();
    QLineEdit* temp;
    QList<Frame*>* booksToEdit = new QList<Frame*>;
    onEditMode = !onEditMode;

    //change text on button
    if(onEditMode)
        ui->editBookButton->setText("Finish Editing");
    else
        ui->editBookButton->setText("Edit");

    //change the attributes of the frame and its children
    for(int i = 0; i < bookResults.size(); i++)
    {
        temp = bookResults.at(i)->findChild<QLineEdit*>("quantityLineEdit");

        if(onEditMode)
        {
            temp->setReadOnly(false);
            palette.setColor(QPalette::Base/*Highlight*/,Qt::yellow);
        }
        else
        {
            temp->setReadOnly(true);
            palette.setColor(QPalette::Base,Qt::transparent);

            //make sure search bar is regualar.  it would not be regular if user tried searching a book while in edit mode
            ui->searchBar->setPalette(palette); //transparent background
            QPalette searBarPalette = QPalette();
            searBarPalette.setColor(QPalette::Text, Qt::black);
            ui->searchBar->setPalette(searBarPalette); //black text
            ui->searchBar->setText("");

            //check to see if this checkbox is checked
            //if it is then update the database with these results
            if(bookResults.at(i)->findChild<QCheckBox*>("checkBox")->isChecked())
            {
                //if this frame is checked, then let me know
                qDebug() << "This guy is checked: " << bookResults.at(i)->book->ISBN;

                //update the frames quantity
                bookResults.at(i)->book->quantity = bookResults.at(i)->getQuantity();
                qDebug() << "Quantity is : " << bookResults.at(i)->getQuantity();

                //add to the list of edited books
                booksToEdit->append(bookResults.at(i));

                //lastly, uncheck the checkbox
                bookResults.at(i)->findChild<QCheckBox*>("checkBox")->setChecked(false);
            }
        }
        temp->setPalette(palette);
    }

    //show the changes
    if(onEditMode)
        unhideCheckBoxesFromFrames();
    else
        hideCheckBoxesFromFrames();

    return booksToEdit;
}

void MainWindow::giveSearchWarning()
{
    QPalette palette = QPalette();
    palette.setColor(QPalette::Text/*Highlight*/,Qt::red);
    ui->searchBar->setPalette(palette);
    palette.setColor(QPalette::Base/*Highlight*/,Qt::yellow);
    ui->searchBar->setPalette(palette);
    ui->searchBar->setText("PLEASE FINISH EDITING FIRST.  THEN TRY AGAIN.");

}

QStringList* MainWindow::switchDeleteMode()
{
    qDebug() << "Deleting book now";

    if(bookResults.size() <= 0)
    {
        qDebug() << "Getting Out";
        return NULL;
    }

    QPalette palette = QPalette();
    QStringList* booksToDelete = new QStringList();
    QList<int> indexToDeleteFrame;
    onDeleteMode = !onDeleteMode;


    //change text on button
    if(onDeleteMode)
    {
        ui->deleteBookButton->setText("Finish Deleting");
        unhideCheckBoxesFromFrames();
    }
    else
    {
        ui->deleteBookButton->setText("Delete");
        hideCheckBoxesFromFrames();
    }

    qDebug() << "Size of book results: " << bookResults.size();
    //change the attributes of the frame and its children
    for(int i = 0; i < bookResults.size(); i++)
    {
        qDebug() << "Loop: " << i;

        if(onDeleteMode)
        {
            palette.setColor(QPalette::Base, Qt::red);
            bookResults.at(i)->setPalette(palette);
            palette.setColor(QPalette::Base, Qt::transparent);
            bookResults.at(i)->getQuantityLineEdit()->setPalette(palette);
        }
        else
        {
            palette.setColor(QPalette::Base, Qt::lightGray);
            bookResults.at(i)->setPalette(palette);
            //palette.setColor(QPalette::Base, Qt::transparent);
            //bookResults.front()->getQuantityLineEdit()->setPalette(palette);

            //check to see if frame is checked
            if(bookResults.at(i)->findChild<QCheckBox*>("checkBox")->isChecked())
            {
                //if this frame is checked, then let me know
                qDebug() << "This guy is checked: " << bookResults.at(i)->book->ISBN;

                //add to the list of edited books
                booksToDelete->append(bookResults.at(i)->book->ISBN);

                //add to the index list so we can know wich frames to delete
                indexToDeleteFrame.append(i);
            }
        }
    }

    //show the changes
    if(!onDeleteMode)
    {
        //delete selected frames from the main window so that the user can no longer see them
        for(int k = indexToDeleteFrame.size() - 1; -1 < k; k--)
        {
            qDebug() << "K is: " << k;
                //then delete from layout
            qDebug() << "Will be deleting index: " << indexToDeleteFrame.at(k);
                delete ui->bookFrameBoundary->layout()->takeAt(indexToDeleteFrame.at(k))->widget();
                //bookResults.removeAt(k);
        }
    }

    qDebug() << "End of Delete Book";
    return booksToDelete;
}
