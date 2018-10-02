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

    bsoncxx::document::view toBson() const {
        qWarning() << "Creating the builder";
        auto builder = bsoncxx::builder::stream::document{};
        qWarning() << "streaming to builder";
        bsoncxx::document::value docReservation = builder
            << "startDate" << startDate
            << "endDate" << endDate
            << "client" << client
            << "numberOfGuests" << numberOfGuests
            << bsoncxx::builder::stream::finalize;
        qWarning() << "Creating the view";
        bsoncxx::document::view view = docReservation.view();
        qWarning() << "The view has length() = underlying buffer of: " << view.length();
        qWarning() << "Retuning the view";
        return view;
    }
};
