#pragma once

#include <QMainWindow>
#include "mongostuff.h"
#include <memory>

#include "tablemodel.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::unique_ptr<MongoStuff> mongoStuff;
    TableModel model;

private slots:
    void on_insertButton_clicked();

    void on_connectButton_clicked();

    void on_readButton_clicked();

private:
    Ui::MainWindow *ui;
};

