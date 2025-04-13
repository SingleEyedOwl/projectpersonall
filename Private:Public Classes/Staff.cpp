//
// Created by MarQuis Steward.
//
#include "Employee.h"
#include <iostream>
#include <string>

#include "Staff.h"



    string Staff::getTitle() {
        return title;
    }
    void Staff::setTitle(string title) {
        this->title = title;
    }

    string Staff::toString() {
        stringstream ss;
        cout<<Employee::toString();
        ss<<" Title = " << title<<endl;
        return ss.str();
    }
