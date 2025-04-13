
#ifndef STAFF_H
#define STAFF_H
#include "Employee.h"
#include "Person.h"
#include "Student.h"
#include "myDate.h"
#include <iostream>
#include <sstream>
#include <string>

class Staff :public Employee {
private :
    string title;
public :
    Staff();
    Staff(string name, string address,string phoneNo,string email, string office, double salary,myDate datehired,
          string title):Employee(name, address,phoneNo,email, office, salary,datehired)
    {
        this->title = title;
    }
    string getTitle();
    void setTitle(string title);
    string toString();
    };



#endif //STAFF_H
