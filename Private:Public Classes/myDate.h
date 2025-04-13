
#ifndef UMYDATE_H
#define MYDATE_H
#include <iostream>
#include <sstream>
#include <string>
#include "Person.h"
#include "Student.h"
using namespace std;

class myDate {
private:
    int year;
    int month;
    int day;
public :
    myDate()
    {
    }
    myDate(int year, int month, int day);
    int getYear();
    void setYear(int year);
    int getMonth();
    void setMonth(int month);
    int getDay();
    void setDay(int day);
    string toString();
};


#endif //MYDATE_H
