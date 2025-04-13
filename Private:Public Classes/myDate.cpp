//
// Created by MarQuis Steward.
//

#include "myDate.h"
#include <iostream>
#include <sstream>
#include <string>
#include "Person.h"
#include "Student.h"
using namespace std;

    myDate::myDate(int day, int month, int year) {
        this->year = year;
        this->month = month;
        this->day = day;
    }
    int  myDate::getYear() {
        return year;
    }
    void  myDate::setYear(int year) {
        this->year = year;
    }
    int  myDate::getMonth() {
        return month;
    }
    void myDate::setMonth(int month) {
        this->month = month;
    }
    int  myDate::getDay() {
        return day;
    }
    void  myDate::setDay(int day) {
        this->day = day;
    }
    string  myDate::toString() {
        cout<<month<<"/"<<day<<"/"<<year<<endl;
    }

