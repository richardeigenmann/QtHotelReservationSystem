#include "tablemodel.h"
#include <string>
#include <iostream>
#include <sstream>

TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}


int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return myReservations.size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 4;
}



QVariant TableModel::data(const QModelIndex &index, int role) const {
    Q_UNUSED(role);
    std::stringstream ss;
    ss << "row: " << index.row()<< " col: " << index.column();
    if ( index.row() < 0 || static_cast<size_t> (index.row()) >= myReservations.size()){
        return QObject::tr("Bad Index");
    }
    Reservation r = myReservations.at(index.row());
    switch (index.column()) {
    case 0 : return QString::fromStdString(r.client);
    case 1 : return QString::fromStdString(Reservation::format_time_and_date(r.startDate));
    case 2 : return QString::fromStdString(Reservation::format_time_and_date(r.endDate));
    case 3 : return QString::number(r.numberOfGuests);
    default:  return QVariant(QObject::tr("undef"));
    }
    //return QVariant(QString::fromStdString( ss.str()));
}


Reservation TableModel::getRow(const size_t row) {
    return myReservations.at(row);
}


QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    Q_UNUSED(section);
    Q_UNUSED(orientation);
    Q_UNUSED(role);
    if ( role == Qt::DisplayRole ) {
        if ( orientation == Qt::Horizontal ) {
            switch (section) {
            case 0 : return QVariant(QObject::tr("Name"));
            case 1 : return QVariant(QObject::tr("Arrival Date"));
            case 2 : return QVariant(QObject::tr("Departure Date"));
            case 3 : return QVariant(QObject::tr("Guests"));
            default:  return QVariant(QObject::tr("undef"));
            }
        }
    }
    return QVariant();
}

void TableModel::setReservations(const std::vector<Reservation> & reservations) {
    emit layoutAboutToBeChanged();
    myReservations = reservations;
    //changePersistentIndex();
    emit layoutChanged();
}

Reservation TableModel::getReservation(const QModelIndex &index, int role) const {
    return myReservations.at(index.row());
}
