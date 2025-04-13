//
// Created by MarQuis Steward.
//

#include <iostream>
#include <sstream>
#include <string>
#include "Person.h"
#include "Student.h"
using namespace std;




    string Student::toString() {
        stringstream ss;
        cout<<Person::toString();
        ss<<"Class Status: "<< this->classStatus<<endl;
        return ss.str();
    }
    double gpa(double gpa){
       gpa = gpa;
    }
