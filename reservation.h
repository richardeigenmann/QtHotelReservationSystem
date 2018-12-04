#pragma once

#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <bsoncxx/builder/basic/array.hpp>
#include <bsoncxx/builder/stream/array.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/types.hpp>
#include <QDebug>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <iostream>

using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;
using bsoncxx::builder::basic::kvp;

class Reservation {
public:
    Reservation(const bsoncxx::types::b_date & startDate,
                const bsoncxx::types::b_date & endDate,
                const std::string & client,
                const int & numberOfGuests)
        : startDate(startDate),
          endDate(endDate),
          client(client),
          numberOfGuests(numberOfGuests) {
    }

    bsoncxx::types::b_date startDate;
    bsoncxx::types::b_date endDate;
    std::string client;
    int numberOfGuests;

    bsoncxx::document::value toBson() const {
        auto doc=bsoncxx::builder::basic::document{};
        // Note: the client is a std::string but the driver expects
        // c-style strings, particularly under Windows! It doesn't
        // convert automatically but silently drops the string! Beware!
        doc.append(
                    kvp("startDate" , startDate),
                    kvp("endDate", endDate),
                    kvp("client", client.c_str()),
                    kvp("numberOfGuests", numberOfGuests)
                    );
        return doc.extract();
    }

    static std::string format_time_and_date(bsoncxx::types::b_date & dt);

};
