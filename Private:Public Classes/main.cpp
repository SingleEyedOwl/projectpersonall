#include <iostream>
#include "Student.h"
#include "myDate.h"
#include "Employee.h"
#include "Faculty.h"
#include "Staff.h"
using namespace std;


void studentProfile(string stuName);
void staffProfile(string staffName);
void facultyProfile(string facultyName);
void menu();
int main()
{
    string name, staffName, facultyName;
    menu();
     char choice = 'x';
     cin >> choice;
     int option;
    while (choice != 'q'){
        switch (choice) {
            case 'a':
            case 'A':
                    cout << "Please enter students name: ";
                    cin >> name;
                    studentProfile(name);
                cout << "Please selection another option" << endl;
                cin >> choice;
                break;

            case 'b':
            case 'B':
                cout << "Do you want to create a Staff member or Faculty member? (1 or 2):  ";
                cin >> option;
               while (option != 1 && option != 2){
                   cout << "Please try again : ";
                   cin >> option;
               }
               if (option == 1){
                    cout << "Input Staff members name: ";
                    cin >> staffName;
                    staffProfile(staffName);
                    cin >> option;
               }else{
                    cout << "Input Faculty members name: ";
                    cin >> facultyName;
                   facultyProfile(facultyName);
                   cin >> option;
               }
            case 'c':
            case 'C':
                cout << "Thank you have a good day :)";
                break;
        }

    }


    return 0;
}


void menu(){
cout << "A) Create student" << endl;
cout << "B) Create To create an employee" << endl;
cout << "C) Quit" << endl;
}

void studentProfile(string stuName){
    string address, phoneNumber, email, classStatus;
    double gpa;
    cout << "Please enter the students address: ";
    cin>> ws;
    getline(cin, address);
    cout << "Please enter students phone number: ";
    cin >> phoneNumber;
    cout<< "Please enter students class status: ";
    cin >> classStatus;
    cout << "Please Enter the students email: ";
    cin >> email;
    cout << "Please enter student gpa: ";
    cin >> gpa;

    Student s(stuName, address,phoneNumber, email, classStatus);
    s.toString();
    cout << "Class: " << classStatus << endl << "GPA is: " << gpa << endl;
    cout << "=========================" << endl;
    menu();
}

void staffProfile(string staffName){
    string address, number, email, officeLocation, title;
    double salary;
    int month, day, year;
    cout << "Please input address: ";
    cin>> ws;
    getline(cin, address);
    cout << "Please input phone number: ";
    cin >> number;
    cout << "Please input email: ";
    cin >> email;
    cout << "Please enter the office location: ";
    cin>> ws;
    getline(cin, officeLocation);
    cout << "Please enter employee title: ";
    cin >> title;
    cout << "Please enter the date hired in 00 00 00 form (no need for / or -): ";
    cin >> month;
    cin >> day;
    cin >> year;
    myDate d(day, month, year);
    cout << "Please enter salary of employee: ";
    cin >> salary;
    Staff staff1(staffName, address, number, email, officeLocation,salary,d,title );
    staff1.toString();
    cout << "Date hired: "<< d.toString();
    cout << "=========================" << endl;
    menu();
}

void facultyProfile(string facultyName){
    string address, number, officeLocation, email;
    double salary;
    int month, day, year, officeHours;
    cout << "Please enter address: ";
    cin>> ws;
    getline(cin, address);
    cout << "Please enter your phone number: ";
    cin >> number;
    cout << "Please enter email: ";
    cin >> email;
    cout << "Please enter office location: ";
    cin>> ws;
    getline(cin, officeLocation);
    cout << "Please enter when office hours end: ";
    cin >> officeHours;
    cout << "Please enter salary: ";
    cin >> salary;
    cout << "Please enter date hired in 00 form (no - or / needed):  ";
    cin >> day;
    cin >> month;
    cin >> year;
    myDate d2(day, month, year);
    Faculty f1(facultyName, address, number, email, officeLocation, salary, d2, officeHours);
    f1.toString();
    cout << "Office hours end: " << f1.getOffice_hours() << endl;
     cout << "Date hired: " << d2.toString() << endl;
    cout << "=========================" << endl;
    menu();

}