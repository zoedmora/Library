#ifndef PRESENTER_H
#define PRESENTER_H

#include <QAbstractItemModel>
#include "model.h"
#include "view.h"

class Presenter : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit Presenter(QObject *parent = nullptr);

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    //Variables
        View* view_p;
        Model* model_p;

public:
//Functions
    Presenter(View*, Model*); //Constructor

public slots:
    void testSlot();  // Charles' Test Slot
    void test();
};

#endif // PRESENTER_H
