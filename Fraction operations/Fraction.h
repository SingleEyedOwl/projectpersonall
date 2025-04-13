#pragma once
#include <iostream>
#include <exception>
#include <stdexcept>

template<class T>
class Fraction
{
private:
    T numer;
    T denom;

    int gcd(T a, T b);
    void reduce2(T x, T y);

public:
    Fraction();
    Fraction(T num);
    Fraction(double dec);
    Fraction(T num, T den);

    Fraction<T> Add(const Fraction<T>& obj) const;
    void Add(const Fraction<T>& obj, const Fraction<T>& obj1);
    Fraction<T> Subtract(const Fraction<T>& obj) const;
    void Subtract(const Fraction<T>& obj, const Fraction<T>& obj1) ;
    Fraction<T> Multiply(const Fraction<T>& obj) const;
    void Multiply(const Fraction<T>& obj, const Fraction<T>& obj1);
    Fraction<T> Divide(const Fraction<T>& obj) const;
    void Divide(const Fraction<T>& obj, const Fraction<T>& obj1);

    void Input(std::istream& input = std::cin);
    void Print(std::ostream& output = std::cout);

    Fraction<T> operator+ (const Fraction<T>& OBJ) const;
    Fraction<T> operator- (const Fraction<T>& OBJ) const;
    Fraction<T> operator*(const Fraction<T>& OBJ) const;
    Fraction<T> operator/(const Fraction<T>& OBJ) const;

    Fraction<T>& operator+=(const Fraction<T>& OBJ);
    Fraction<T>& operator-=(const Fraction<T>& OBJ);
    Fraction<T>& operator*=(const Fraction<T>& OBJ);
    Fraction<T>& operator/=(const Fraction<T>& OBJ);

    Fraction<T>& operator++();
    Fraction<T> operator++(int);

    Fraction<T>& operator--();
    Fraction<T> operator--(int);

    bool operator== (const Fraction<T>& OBJ) const;
    bool operator!= (const Fraction<T>& OBJ) const;
    bool operator< (const Fraction<T>& OBJ) const;
    bool operator> (const Fraction<T>& OBJ) const;
    bool operator<= (const Fraction<T>& OBJ) const;
    bool operator>= (const Fraction<T>& OBJ) const;

    Fraction<T> operator- ();
    Fraction<T> operator~ ();
    
    friend std::ostream& operator<< (std::ostream& output, Fraction<T>& OBJ);
    friend std::istream& operator>> (std::istream& input, Fraction<T>& OBJ);
};


template<class T>
int Fraction<T>::gcd(T a, T b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

template<class T>
void Fraction<T>::reduce2(T x, T y)
{
    int d;
    int temp_num = 0;
    int temp_den = 0;
    d = gcd(x, y);

    numer = x / d;
    denom = y / d;

    if (denom < 0)   //flips the negative from the denom to the numer
    {
        temp_num = 0 - numer;
        temp_den = 0 - denom;
        if (temp_den == 1)
        {
            std::cout << "Reduces to: " << temp_num << std::endl;
        }
        else {
            std::cout << "Reduces to: " << temp_num << "/" << temp_den << std::endl;
        }
    }
    else {
        if (denom == 1)
        {
            std::cout << "Reduces to: " << numer << std::endl;
        }
        else {
            std::cout << "Reduces to: " << numer << "/" << denom << std::endl;
        }
    }
}

template<class T>
Fraction<T>::Fraction() : numer(0), denom(1) {}
template<class T>
Fraction<T>::Fraction(T num) : numer(num), denom(1) {}
template<class T>
Fraction<T>::Fraction(double dec) : numer(dec * 100000), denom(100000) {}
template<class T>
Fraction<T>::Fraction(T num, T den) : numer(num), denom(den) {}

template<class T>
Fraction<T> Fraction<T>::Add(const Fraction<T>& obj) const
{
    if (obj.denom == 0 || denom == 0)
    {
        throw exception("Cannot divide by 0");
    }

    int new_num = numer * obj.denom +
        obj.numer * denom;
    int new_den = denom * obj.denom;
    Fraction<T> newFrac(new_num, new_den);
    return newFrac;
}


template<class T>
void Fraction<T>::Add(const Fraction<T>& obj, const Fraction<T>& obj1) {
    if (obj.denom == 0 || obj1.denom == 0)
    {
        throw exception("Cannot divide by 0");
    }

    int new_num = obj1.numer * obj.denom +
        obj.numer * obj1.denom;
    int new_den = obj1.denom * obj.denom;

    numer = new_num;
    denom = new_den;
}

template<class T>
Fraction<T> Fraction<T>::Subtract(const Fraction<T>& obj) const {
    if (obj.denom == 0 || denom == 0)
    {
        throw exception("Cannot divide by 0");
    }

    int new_num = numer * obj.denom -
        obj.numer * denom;
    int new_den = denom * obj.denom;
    Fraction<T> newFrac(new_num, new_den);
    return newFrac;
}

template<class T>
void Fraction<T>::Subtract(const Fraction<T>& obj, const Fraction<T>& obj1) {
    if (obj.denom == 0 || obj1.denom == 0)
    {
        throw exception("Cannot divide by 0");
    }

    int new_num = obj.numer * obj1.denom -
        obj1.numer * obj.denom;
    int new_den = obj.denom * obj1.denom;
    numer = new_num;
    denom = new_den;
}

template<class T>
Fraction<T> Fraction<T>::Multiply(const Fraction<T>& obj) const {
    if (obj.denom == 0 || denom == 0)
    {
        throw exception("Cannot divide by 0");
    }

    int new_num = numer * obj.numer;
    int new_den = denom * obj.denom;
    Fraction<T> newFrac(new_num, new_den);
    return newFrac;

}

template<class T>
void Fraction<T>::Multiply(const Fraction<T>& obj, const Fraction<T>& obj1) {
    if (obj.denom == 0 || obj1.denom == 0)
    {
        throw exception("Cannot divide by 0");
    }

    int new_num = obj.numer * obj1.numer;
    int new_den = obj.denom * obj1.denom;
    numer = new_num;
    denom = new_den;
}

template<class T>
Fraction<T> Fraction<T>::Divide(const Fraction<T>& obj) const {
    if (obj.denom == 0 || denom == 0)
    {
        throw exception("Cannot divide by 0");
    }

    int new_num = numer * obj.denom;
    int new_den = denom * obj.numer;
    Fraction<T> newFrac(new_num, new_den);
    return newFrac;
}

template<class T>
void Fraction<T>::Divide(const Fraction<T>& obj, const Fraction<T>& obj1) {
    if (obj.denom == 0 || obj1.denom == 0)
    {
        throw exception("Cannot divide by 0");
    }

    int new_num = obj.numer * obj1.denom;
    int new_den = obj.denom * obj1.numer;
    numer = new_num;
    denom = new_den;
}

template<class T>
void Fraction<T>::Input(std::istream& input)
{
    int num, den = 0;

    std::cout << "Enter the numer: ";
    input >> num;
    std::cout << "Enter the denom: ";
    input >> den;

    while (den == 0)
    {
        std::cout << "Cannot divide by 0" << endl;
        std::cout << "Enter the denom: ";
        input >> den;
    }

    numer = num;
    denom = den;
}

template<class T>
void Fraction<T>::Print(std::ostream& output)
{
    if (denom == 0)
    {
        throw std::exception("Cannot divide by 0");
    }
    else {

        reduce2(numer, denom);

        if (denom == 1)
        {
            output << numer << "\n";
        }
        else
        {
            output << numer << "/" << denom << "\n";
        }
    }

}
template<class T>
Fraction<T> Fraction<T>::operator+ (const Fraction<T>& OBJ) const
{
    return Add(OBJ);
}
template<class T>
Fraction<T> Fraction<T>::operator- (const Fraction<T>& OBJ) const
{
    return Subtract(OBJ);
}
template<class T>
Fraction<T> Fraction<T>::operator*(const Fraction<T>& OBJ) const
{
    return Multiply(OBJ);
}
template<class T>
Fraction<T> Fraction<T>::operator/(const Fraction<T>& OBJ) const
{
    return Divide(OBJ);
}
template<class T>
Fraction<T>& Fraction<T>::operator+= (const Fraction<T>& OBJ)
{
    Add(*this, OBJ);
    return *this;
}
template<class T>
Fraction<T>& Fraction<T>::operator-=(const Fraction<T>& OBJ)
{
    Subtract(*this, OBJ);
    return *this;
}
template<class T>
Fraction<T>& Fraction<T>::operator*=(const Fraction<T>& OBJ)
{
    Multiply(*this, OBJ);
    return *this;
}
template<class T>
Fraction<T>& Fraction<T>::operator/=(const Fraction<T>& OBJ)
{
    Divide(*this, OBJ);
    return *this;
}
template<class T>
Fraction<T>& Fraction<T>::operator++ ()
{
    numer += denom;
    return *this;
}
template<class T>
Fraction<T> Fraction<T>::operator++(int)
{
    Fraction<T> New_Frac(numer, denom);

    ++New_Frac;

    //New_Frac.print();
    return New_Frac;
}
template<class T>
Fraction<T>& Fraction<T>::operator--()
{
    if (numer < denom)
    {
        throw std::exception("Cannot decrement - numerator is less than the denominator");
    }

    numer -= denom;
    return *this;
}
template<class T>
Fraction<T> Fraction<T>::operator--(int)
{
    Fraction<T> New_Frac(numer, denom);

    --New_Frac;

    return New_Frac;
}

template<class T>
bool Fraction<T>::operator== (const Fraction<T>& OBJ) const
{
    int temp1 = numer * OBJ.denom;
    int temp2 = OBJ.numer * denom;
    return (temp1 == temp2);
}
template<class T>
bool Fraction<T>::operator!= (const Fraction<T>& OBJ) const
{
    return !(*this == OBJ);
}
template<class T>
bool Fraction<T>::operator< (const Fraction<T>& OBJ) const
{
    int temp1 = numer * OBJ.denom;
    int temp2 = OBJ.numer * denom;
    return (temp1 < temp2);
}
template<class T>
bool Fraction<T>::operator> (const Fraction<T>& OBJ) const
{
    int temp1 = numer * OBJ.denom;
    int temp2 = OBJ.numer * denom;
    return (temp1 > temp2);
}
template<class T>
bool Fraction<T>::operator<= (const Fraction<T>& OBJ) const
{
    int temp1 = numer * OBJ.denom;
    int temp2 = OBJ.numer * denom;
    return (temp1 <= temp2);
}
template<class T>
bool Fraction<T>::operator>= (const Fraction<T>& OBJ) const
{
    int temp1 = numer * OBJ.denom;
    int temp2 = OBJ.numer * denom;
    return (temp1 >= temp2);
}

template<class T>
Fraction<T> Fraction<T>::operator- ()
{
    return Fraction(-numer, denom);
}
template<class T>
Fraction<T> Fraction<T>::operator~ ()
{
    if (numer < 0)
    {
        numer = -numer;
        denom = -denom;
    }

    return Fraction<T>(denom, numer);
}

template<class T>
std::ostream& operator<< (std::ostream& output, Fraction<T>& OBJ) {

    OBJ.Print(output);

    return output;
}

template<class T>
std::istream& operator>> (std::istream& input, Fraction<T>& OBJ)
{
    OBJ.Input(input);

    return input;
}
