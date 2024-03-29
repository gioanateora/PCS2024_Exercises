//#pragma once // It works like header guards

#ifndef __RATIONAL_H // Header guards
#define __RATIONAL_H

#include <iostream>
#include <cmath>

using namespace std;

// Insert all your functions related to Rational class (both .cpp and .hpp) in a namespace to avoid clashes
namespace RationalLibrary{

struct Rational
{

    int numerator;
    int denominator;
    double d;

    Rational(int a, int b):
        numerator(a),
        denominator(b)
    {
        d = to_double();
    }

    Rational() = default; // Default constructor.

    // Overloading: compare the two following constructor. There must be a perfect match.
    // Otherwise the compiler returns an "ambiguous call" error
    //    Rational(int a, int b, int c)
    //    {
    //        numerator = a;
    //        denominator = b;
    //    }

    //    Rational(double a, double b, double c)
    //    {
    //        numerator = a;
    //        denominator = b;
    //    }

    // Method
    double to_double();

};

ostream& operator<<(ostream& os, const Rational &r);

Rational operator+(const Rational &r1, const Rational &r2);

double operator+(const double &r1, const Rational &r2);

Rational operator*(const Rational &r1, const Rational &r2);

}
#endif

