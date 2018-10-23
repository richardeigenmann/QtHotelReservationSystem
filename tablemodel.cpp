#include "tablemodel.h"
#include <string>
#include <iostream>
#include <sstream>

TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    this->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    this->setHeaderData(1, Qt::Horizontal, QObject::tr("First name"));
    this->setHeaderData(2, Qt::Horizontal, QObject::tr("Last name"));
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 2;
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 3;
}



QVariant TableModel::data(const QModelIndex &index, int role) const {
    Q_UNUSED(role);
    std::stringstream ss;
    ss << "row: " << index.row()<< " col: " << index.column();
    return QVariant(QString::fromStdString( ss.str()));
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
            default:  return QVariant(QObject::tr("undef"));
            }
        }
    }
    return QVariant();
}
