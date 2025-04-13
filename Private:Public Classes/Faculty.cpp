
#include "Faculty.h"
#include "Employee.h"
#include <iostream>
#include <string>




    int Faculty::getOffice_hours() {
        return office_hours;
    }
    void Faculty::setOffice_hours(int office_hours) {
        this->office_hours = office_hours;
    }
    string Faculty::toString() {
        stringstream ss;
        cout<<Employee::toString();
        ss<<"Office Hours end at = " << office_hours<<endl;
        return ss.str();
    }
