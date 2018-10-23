#pragma once

#include <QAbstractTableModel>
#include <QVariant>

class TableModel : public  QAbstractTableModel{
    Q_OBJECT

public:
    TableModel(QObject *parent=0);
    int rowCount(const QModelIndex&) const;
    int columnCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &index, int role= Qt::DisplayRole) const ;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
};
