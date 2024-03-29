#include "src/Rational.hpp"
#include <iostream>
#include <cmath>
#include "src/Utils.hpp"

using namespace std;


int main()
{
    std::string s = ""; // This is the default value for type string
    RationalLibrary::Rational r;

    // What is the default value for int type? Run more than one time
    cout << "default for int: " << r << endl;

    RationalLibrary::Rational r1(1, 0);

    cout << "r1: " << r1 << endl;

    RationalLibrary::Rational r2(1, 2);
    RationalLibrary::Rational sum = r1 + r2;

    cout << "sum of 0.5 + inf: " << sum << endl;

    double d = r2.to_double() + 1.5; // Sum two double values
    double d1 = operator+(1.5, r2); // Equivalent syntax for calling  double + Rational. The + operator is a standard function.

    // Calling the constructor :
    //    Rational(const int &a,const int &b)
    //    {
    //        numerator = a;
    //        denominator = b;
    //    }

    // Step 1: Initialize parameters
    //    const int &a = 1;
    //    const int &b = 2;
    // Step 2: Initialize data member
    //    int numerator = a;
    //    int denominator = b;

    double d2 = NAN; // NAN and INFINITY are float-type defined in cmath - > See for example: https://en.cppreference.com/w/cpp/numeric/math/INFINITY
    cout << "Print NAN: " << d2 << endl;

    cout << "Call to foo(): " << RationalLibrary::foo(1) << endl;

    return 0;
}
