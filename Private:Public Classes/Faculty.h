
#ifndef FACULTY_H
#define FACULTY_H
#include "Employee.h"
#include "Person.h"
#include "Student.h"
#include "myDate.h"
#include <iostream>
#include <sstream>
#include <string>

class Faculty :public Employee {
private :
    int office_hours;
public:
    Faculty() {
    }
    Faculty(string name, string address,string phoneNo,string email, string office, double salary,myDate datehired,
            int office_hours):Employee(name, address,phoneNo,email, office, salary,datehired)
    {
        this->office_hours = office_hours;
    }
    int getOffice_hours();
    void setOffice_hours(int office_hours);
    string toString();
};


#endif //FACULTY_H
