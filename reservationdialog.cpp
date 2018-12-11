#include "reservationdialog.h"
#include "ui_reservationdialog.h"
#include <QDebug>
#include <ctime>

ReservationDialog::ReservationDialog(QWidget *parent, size_t row, TableModel * model) :
    QDialog(parent),
    row(row),
    model(model),
    ui(new Ui::ReservationDialog)
{
    auto clickedReservation = model->getRow(row);
    qWarning () << clickedReservation.client.c_str();
    ui->setupUi(this);
    ui->clientText->appendPlainText(QString::fromStdString(clickedReservation.client));
    auto in_time_t = std::chrono::system_clock::to_time_t(clickedReservation.startDate);
    ui->arrivalDate->setDate(QDate::fromString(std::ctime(&in_time_t)));
}

ReservationDialog::~ReservationDialog()
{
    delete ui;
}

void ReservationDialog::accept() {
    qWarning() << "Accept clicked row: " << row;
    QDialog::accept(); // to close the dialog and return 1
}
void ReservationDialog::reject() {
    qWarning() << "Reject clicked";
    QDialog::reject(); // to close the dialog and return 0
}
