
#include <iostream>
#include <cctype>
#include "Fraction.h"

using namespace std;

void menu()
{
    cout << "a) a + b" << endl;
    cout << "b) a - b" << endl;
    cout << "c) a * b" << endl;
    cout << "d) a / b" << endl;
    cout << "e) a += b" << endl;
    cout << "f) a -= b" << endl;
    cout << "g) a *= b" << endl;
    cout << "h) a /= b" << endl;
    cout << "i) a == b" << endl;
    cout << "j) a != b" << endl;
    cout << "k) a > b" << endl;
    cout << "l) a < b" << endl;
    cout << "m) a >= b" << endl;
    cout << "n) a <= b" << endl;
    cout << "o) ++a" << endl;
    cout << "p) a++" << endl;
    cout << "q) --a" << endl;
    cout << "r) a--" << endl;
    cout << "s) -a" << endl;
    cout << "t) ~a" << endl;
    cout << "q) Quit" << endl;
}

#include <array>

int main() 
{

    std::array<int, 5> myArray;

    Fraction<int> a;
    Fraction<int> b;

    char choice = 'x';
    while(choice != 'q')
    {
        menu();
        cout << "Value of a: ";
        a.Print();
        cout << "Value of b: ";
        b.Print();
        cout << "Please select a letter: ";

        cin >> choice;

        switch(std::tolower(choice))
        {
            case 'a':
                (a + b).Print();
                break;
            case 'b':
                (a - b).Print();
                break;
            case 'c':
                (a * b).Print();
                break;
            case 'd':
                (a / b).Print();
                break;
            case 'e':
                (a += b).Print();
                break;
            case 'f':
                (a -= b).Print();
                break;
            case 'g':
                (a *= b).Print();
                break;
            case 'h':
                (a /= b).Print();
                break;
            case 'i':
                cout << (a == b) << '\n';
                break;
            case 'j':
                cout << (a != b) << '\n';
                break;
            case 'k':
                cout << (a > b) << '\n';
                break;
            case 'l':
                cout << (a < b) << '\n';
                break;
            case 'm':
                cout << (a >= b) << '\n';
                break;
            case 'n':
                cout << (a <= b) << '\n';
                break;
            case 'o':
                ++a;
                a.Print();
                break;
            case 'p':
                a++;
                a.Print();
                break;
            case 'q':
                --a;
                a.Print();
                break;
            case 'r':
                a--;
                a.Print();
                break;
            case 's':
                (-a).Print();
                break;
            case 't':
                (~a).Print();
                break;
            case 'Q':
                cout << "Good Bye! :)" << endl;
                choice = 'q';
                break;
            default:
                cout << "Invalid choice." << endl;
                cout << "Please reselect: "<<endl;
        }

    }



    return 0;
}

