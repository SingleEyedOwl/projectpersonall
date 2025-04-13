//
// Created by MarQuis Steward
//

#include "Person.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;



    Person::Person() {

    }
    Person::Person(string name, string address,string phoneNo,string email) {
        this->name = name;
        this->address = address;
        this->phoneNo=phoneNo;
        this->email=email;
    }
    string Person::getName() {
        return name;
    }
    void Person::setName(string name) {
        this->name = name;
    }
    string Person::getAddress() {
        return address;
    }
    void Person::setAddress(string address) {
        this->address = address;
    }
    string Person::getPhoneNo() {
        return phoneNo;
    }
    void Person::setPhoneNo(string phoneNo) {
        this->phoneNo = phoneNo;
    }
    string Person::getEmail() {
        return email;
    }
    void Person::setEmail(string email) {
        this->email = email;
    }
    string Person::toString() {
        stringstream ss;
        ss<<"Name = " <<name <<endl;
        ss<<"Address = " << address <<endl;
        ss<<"Phone Number = "<<phoneNo<<endl;
        ss<<"Email = " << email<<endl;
        return ss.str();

    }
