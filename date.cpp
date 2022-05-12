/**
 *
 * \file date.h
 *
 */

#include "date.h"

std::ostream& operator<<(std::ostream& os, const Date& rhs){
    return os << rhs.getYear() << "."
              << std::setfill('0') << std::setw(2) << rhs.getMonth() << "."
              << std::setfill('0') << std::setw(2) << rhs.getDay();
}



std::istream& operator>>(std::istream& is, Date& rhs){
    int year, month, day;
    char c;

    is >> year >> c >> month >> c >> day;

    rhs.setYear(year);
    rhs.setMonth(month);
    rhs.setDay(day);

    return is;
}
