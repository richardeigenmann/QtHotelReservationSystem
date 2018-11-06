#include "mainwindow.h"
#include "reservation.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <mongocxx/collection.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <bsoncxx/builder/basic/array.hpp>
#include <mongocxx/exception/exception.hpp>
#include <QDebug>
#include <QTextCursor>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>



using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;
using bsoncxx::builder::basic::kvp;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mongoStuff = std::make_unique<MongoStuff>();

    ui->tableView->setModel(&model);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_insertButton_clicked() {
    qWarning("About to insert 4 reservations");
    try {
        Reservation firstBooking{ mongoStuff->read_date("2018-8-1",0), mongoStuff->read_date("2018-8-3",0), "George Clooney", 2 };
        Reservation secondBooking{ mongoStuff->read_date("2018-8-6",0), mongoStuff->read_date("2018-8-9",0), "George Clooney", 3 };
        Reservation thirdBooking{ mongoStuff->read_date("2018-8-12",0), mongoStuff->read_date("2018-8-18",0), "George Clooney", 1 };
        Reservation fourthBooking{ mongoStuff->read_date("2018-8-2",0), mongoStuff->read_date("2018-8-7",0), "George Clooney", 2 };
        qWarning("Created the reservation objects");
        mongocxx::collection collection = mongoStuff->db["reservations"];
        qWarning("Got the collection");
        mongoStuff->addReservation(collection, firstBooking);
        //mongoStuff->addReservation(collection, secondBooking);
        //mongoStuff->addReservation(collection, thirdBooking);
        //mongoStuff->addReservation(collection, fourthBooking);
        qWarning("Inserted 1 reservations");
    }  catch (const mongocxx::exception &ex) {
        qWarning() << "Hit an exception..." << ex.what();
    }
}



void MainWindow::on_connectButton_clicked()
{
    qWarning() << "connectButton clicked";
    mongoStuff->connectToDb();
}

std::string return_current_time_and_date()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}


void MainWindow::on_readButton_clicked()
{
    qWarning("Read Button Clicked");
    try {
        mongocxx::collection collection = mongoStuff->db["reservations"];
        qWarning("Got the collection");
        auto reservations = mongoStuff->readAllReservations(collection);
        model.setReservations(reservations);
        for ( auto r : reservations ) {
            ui->textEdit->append (QString::fromStdString(r.client));
            ui->textEdit->append (QString::fromStdString(Reservation::format_time_and_date(r.startDate)) );
            ui->textEdit->append (QString::fromStdString(Reservation::format_time_and_date(r.endDate)) );
            ui->textEdit->append (QString::number(r.numberOfGuests) );

        }
    }  catch (const mongocxx::exception &ex) {
        qWarning() << "Hit an exception..." << ex.what();
    }
}
