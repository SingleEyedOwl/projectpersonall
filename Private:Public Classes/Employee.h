

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Person.h"
#include "Student.h"
#include "myDate.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Employee :public Person {
private :
    string office;
    double salary;
    myDate dateHired;
public :
    Employee() {

    }
    Employee(string name, string address, string phoneNo,string email, string office, double salary,myDate datehired):Person(name, address, phoneNo, email)
    {

        this->office = office;
        this->salary = salary;
        this->dateHired=datehired;
    }
    string getOffice();
    void setOffice(string office);
    double getSalary();
    void setSalary(double salary);


    string toString();
};

#endif //EMPLOYEE_H
