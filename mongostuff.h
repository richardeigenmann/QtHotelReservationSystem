#pragma once

#include "reservation.h"
#include <mongocxx/client.hpp>
#include <mongocxx/database.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <string>
#include <vector>


class MongoStuff
{
public:
    MongoStuff();
    mongocxx::instance instance {}; // This should be done only once.
    mongocxx::database db;
    mongocxx::uri uri{"mongodb://localhost:27017"};
    mongocxx::client client{uri};

    void connectToDb();
    void addReservation(mongocxx::collection &collection, const Reservation &r);
    std::vector<Reservation> readAllReservations(mongocxx::collection &collection);
    bsoncxx::types::b_date read_date(const std::string &date, std::int32_t offset_from_utc);

};
