#include "mongostuff.h"
#include <QDebug>
#include <QString>
#include "mongocxx/instance.hpp"
#include <mongocxx/exception/exception.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/client.hpp>
#include <bsoncxx/view_or_value.hpp>
#include <sstream>
#include <iomanip>

MongoStuff::MongoStuff()
{
    qWarning() << "Constructing MongoStuff";
}


void MongoStuff::connectToDb() {
    qWarning() << "Connecting to the mongodb server...\n";
    try {
        db = client["local"];
        qWarning() << "got db...\n";
    }  catch (const mongocxx::exception &ex) {
        qWarning() << "Hit an exception: " << ex.what();
    }
}

void MongoStuff::addReservation(mongocxx::collection & collection,  const Reservation & r) {
    qWarning() << "Inserting a reservation";
    auto bson = r.toBson();
    qWarning() << "Got the bson object";
    bsoncxx::document::view view = bson.view();
    qWarning() << "The view has length() = underlying buffer of: " << view.length();
    qWarning() << "Retuning the view";

    try {

        //bsoncxx::builder::stream::document d{};
        //d << "hello" << "world";
        bsoncxx::stdx::optional<mongocxx::result::insert_one> result = collection.insert_one(view);


        qWarning() << "Insert done";
    }  catch (const mongocxx::exception &ex) {
        qWarning() << "Hit an exception: " << ex.what();
    }
}

std::vector<Reservation> MongoStuff::readAllReservations(mongocxx::collection & collection) {
    qWarning() << "Reading all reservations";

    //bsoncxx::stdx::optional<mongocxx::result::find> result = collection.find();

    std::vector<Reservation> reservations {};
    qWarning("before find");
    mongocxx::cursor cursor = collection.find({});
    qWarning("after find");
    for(auto c : cursor) {
        qWarning("iterating cursor");
        auto sd_view = c["startDate"].get_date();
        qWarning("parsed date");
        auto ed_view = c["endDate"].get_date();
        qWarning("parsed date");
        auto guests_view = c["numberOfGuests"].get_int32();
        qWarning("parsed guests");

        auto docClient = c["client"];
        qWarning("Got client doc");
        qWarning() << QString::number( static_cast<int>(docClient.type()));
        auto view = docClient.get_utf8().value;
        qWarning("got client view");
        std::string name = view.to_string();
        qWarning("parsed name");

        Reservation r {sd_view,ed_view,name,guests_view};
        //qWarning() << QString::fromStdString(name);
        reservations.push_back(r);
    }
    return reservations;
}

/**
* @brief Convert a Y-m-d to a bsoncxx date
* @see https://stackoverflow.com/questions/42148535/mongodb-query-across-a-date-range
*/
bsoncxx::types::b_date MongoStuff::read_date(const std::string& date, std::int32_t offset_from_utc) {
    std::tm utc_tm{};
    std::istringstream ss{ date };

    // Read time into std::tm.
    ss >> std::get_time(&utc_tm, "%Y-%m-%d");

    // Convert std::tm to std::time_t.
    std::time_t utc_time = std::mktime(&utc_tm);

    // Convert std::time_t std::chrono::systemclock::time_point.
    std::chrono::system_clock::time_point time_point =
            std::chrono::system_clock::from_time_t(utc_time);

    return bsoncxx::types::b_date{ time_point +
                std::chrono::hours{ offset_from_utc } };
}
