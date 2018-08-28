#pragma once

#include <QMainWindow>
#include "mongostuff.h"
#include <memory>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //MongoStuff mg{};
    std::unique_ptr<MongoStuff> mongoStuff;

private slots:
    void on_insertButton_clicked();

    void on_connectButton_clicked();

    void on_readButton_clicked();

private:
    Ui::MainWindow *ui;
    //MongoStuff mg;
};

