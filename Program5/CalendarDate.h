#ifndef CALENDAR_DATE
#define CALENDAR_DATE

#include <iostream>
using namespace std;

/*
 * Camden Harris
 * Spring 2024, CS212, William Iverson
 * 04/15/2024
 * Program 3
 * Calendar Date Data Structure
 */

class CalendarDate {
    
    int month, day, year;

    public:
        // main constructor for date
        CalendarDate(int m, int d, int y) {
            month = m;
            day = d;
            year = y;
        }

        // returns a string in the MM/DD/YYYY format (e.g 1/1/1970)
        string ToString() { return (to_string(month) + "/" + to_string(day) + "/" + to_string(year)); }

        // prefix ++ operator, adds one to year
        const CalendarDate& operator++() {
            ++(this->year);
            return *this;
        }

        // postfix ++ operator, adds one to year 
        const CalendarDate operator++(int) {
            CalendarDate temp(*this);
            ++(this->year);
            return temp;
        }

        // less than comparison operator
        bool operator<(const CalendarDate& other) const {
            if (year != other.year) return year < other.year;
            if (month != other.month) return month < other.month;
            return day < other.day;
        }

        // << operator, used to print long date (e.g January, 1, 1970)
        friend ostream& operator<<(ostream& os, const CalendarDate& date) {
            string month_string;
            switch(date.month) {
                case 1: month_string = "January"; break;
                case 2: month_string = "February"; break;
                case 3: month_string = "March"; break;
                case 4: month_string = "April"; break;
                case 5: month_string = "May"; break;
                case 6: month_string = "June"; break;
                case 7: month_string = "July"; break;
                case 8: month_string = "August"; break;
                case 9: month_string = "September"; break;
                case 10: month_string = "October"; break;
                case 11: month_string = "November"; break;
                case 12: month_string = "December"; break;
            }

            return os << month_string << ", " << to_string(date.day) << ", " << to_string(date.year);
        }

        int hashCode() {
            return day + (month * 31) + (year * 366);
        }
};

#endif
