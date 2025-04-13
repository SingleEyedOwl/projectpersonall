

#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Person {
private:
    string name, address;
    string phoneNo;
    string email;
public :
    Person();
    Person(string name, string address,string phoneNo,string email);
    string getName();
    void setName(string name);
    string getAddress();
    void setAddress(string address);
    string getPhoneNo();
    void setPhoneNo(string phoneNo);
    string getEmail();
    void setEmail(string email);
    string toString();
};

#endif //UNTITLED3_PERSON_H
