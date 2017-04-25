#include "Date.h"
#include <ctime>

class Date {
    unsigned int date;
    unsigned int month;
    unsigned int year;

    Date() {
        this->date = 0;
        this->month = 0;
        this->year = 0;
    }

    Date(unsigned int date, unsigned int month, unsigned int year) {
        this->date = date;
        this->month = month;
        this->year = year;
    }

    Date(const Date &original) {
        this->date = original.date;
        this->month = original.month;
        this->year = original.year;
    }

    unsigned int getDate() {
        return date;
    }

    void setDate(unsigned int date) {
        this->date = date;
    }

    unsigned int getMonth() {
        return month;
    }

    void setDate(unsigned int month) {
        this->month = month;
    }

    unsigned int getYear() {
        return year;
    }

    void setYear(unsigned int year) {
        this->year = year;
    }

    static Date getInstance() {
        time_t t = time(0);
        struct tm *now = localtime(&t);
        return new Date(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    }

    static unsigned int getDaysInMonth(unsigned int month, unsigned int year) {
        int numDays = 0;
        switch (month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                numDays = 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                numDays = 30;
                break;
            case 2:
                if (((year % 4 == 0) && !(year % 100 == 0)) || (year % 400 == 0))
                    numDays = 29;
                else
                    numDays = 28;
                break;
        }
        return numDays;
    }

    bool isValid() {
        if (year < 0 || month < 1 || month > 12 || days < 1 || days > getDaysInMonth(month, year))
            return false;
        return true;
    }

    void validate() {
        if (isValid())
            return;
        int numDays = getDaysInMonth(month, year);
        days -= numDays;
        month = month == 12 ? 1 : month + 1;
        validate();
    }

    Date operator+(unsigned int days) {
        Date new_date = new Date();
        new_date.setDate(this->date + d.date);
        new_date.setMonth(this->month + d.month);
        new_date.setYear(this->year + d.year);
        new_date.validate();
        return new_date;
    }
}
