//
// Created by MarQuis Steward.
//

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <sstream>
#include <string>
#include "Person.h"
using namespace std;

class Student :public Person {
private:
    string classStatus;

public:
    Student() {

    }
    Student(string name, string address,string phoneNo,string email,string classStatus):Person(name,address,phoneNo,email) {
        this->classStatus = classStatus;
    }
    string toString();
};


#endif //STUDENT_H
