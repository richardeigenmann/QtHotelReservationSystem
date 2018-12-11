#ifndef RESERVATIONDIALOG_H
#define RESERVATIONDIALOG_H

#include "tablemodel.h"
#include <QDialog>

namespace Ui {
    class ReservationDialog;
}

class ReservationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReservationDialog(QWidget *parent = nullptr, size_t row = 0, TableModel * model = nullptr);
    ~ReservationDialog();

private:
    Ui::ReservationDialog *ui;
    size_t row;
    TableModel * model;

private slots:
    void accept();
    void reject();

};

#endif // RESERVATIONDIALOG_H
