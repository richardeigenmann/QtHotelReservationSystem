#include "reservationdialog.h"
#include "ui_reservationdialog.h"

ReservationDialog::ReservationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReservationDialog)
{
    ui->setupUi(this);
}

ReservationDialog::~ReservationDialog()
{
    delete ui;
}
