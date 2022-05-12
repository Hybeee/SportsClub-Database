#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <iomanip>

/**
 * Date class
 * Will be a member variable in the SportsClub class
 * Going to be used to compare members in the database
 */
class Date{
    int year;
    int month;
    int day;

public:
    /**Only constructor*/
    Date(int year = 0, int month = 0, int day = 0): year(year), month(month), day(day) {}

    /**getter methods for each member variable*/
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }

    /**setter methods for each member variable*/
    void setYear(int year) { this->year = year; }
    void setMonth(int month) { this->month = month; }
    void setDay(int day) { this->day = day; }

    /**function for comparing dates by the value of their 'year' variable*/
    /** @param rhs - the Date instance on the right-hand-side*/
    bool operator==(const Date& rhs) const {
        return (year == rhs.year) && (month == rhs.month) && (day == rhs.day);
    }

    ~Date() {}
};

/**function for printing 'Date' out to the standard output in the correct form*/
/**yyyy.mm.dd*/
std::ostream& operator<<(std::ostream& os, const Date& rhs);

/**function for reading 'Date' from standard input*/
/**yyyy.mm.dd*/
std::istream& operator>>(std::istream& is, Date& date);


#endif // DATE_H_INCLUDED
