

#include "Employee.h"
#include "Person.h"
#include <iostream>
#include <string>
using namespace std;


    string Employee::getOffice() {
        return office;
    }
    void Employee::setOffice(string office) {
        this->office = office;
    }
    double Employee::getSalary() {
        return salary;
    }
    void Employee::setSalary(double salary) {
        this->salary = salary;
    }


    string Employee::toString() {
        stringstream ss;
        cout<<Person::toString();
        ss<<"Office location is  = " << office <<endl;
        ss<<"Salary = " << salary<<endl;
        return ss.str();
    }
