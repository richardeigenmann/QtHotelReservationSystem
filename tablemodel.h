#pragma once

#include <QAbstractTableModel>
#include <QVariant>
#include <vector>
#include "reservation.h"

class TableModel : public  QAbstractTableModel{
    Q_OBJECT

public:
    TableModel(QObject *parent=0);
    int rowCount(const QModelIndex&) const;
    int columnCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &index, int role= Qt::DisplayRole) const;
    Reservation getRow(const size_t row);
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    void setReservations(const std::vector<Reservation> & reservations);
    Reservation getReservation(const QModelIndex &index, int role= Qt::DisplayRole) const;
private:
    std::vector<Reservation> myReservations{};
};
