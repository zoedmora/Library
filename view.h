#ifndef VIEW_H
#define VIEW_H

#include <QAbstractItemModel>
#include "mainwindow.h"""

class View : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit View(QObject *parent = nullptr);

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

public:
//Functions
    void executeMainWindow();

signals:
    void pushButtonClicked();
    void testClick();
    void brianTestClicked();


private:
//Variables
    MainWindow* mainWindow;
};

#endif // VIEW_H
