#ifndef RESERVATIONDIALOG_H
#define RESERVATIONDIALOG_H

#include <QDialog>

namespace Ui {
    class ReservationDialog;
}

class ReservationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReservationDialog(QWidget *parent = nullptr);
    ~ReservationDialog();

private:
    Ui::ReservationDialog *ui;
};

#endif // RESERVATIONDIALOG_H
