#include "reservation.h"

std::string Reservation::format_time_and_date(bsoncxx::types::b_date & dt)
{
    //auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(dt);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}
