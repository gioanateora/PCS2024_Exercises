#include "Rational.hpp"

namespace RationalLibrary{
double Rational::to_double()
{
    return double(numerator) / denominator;
}


ostream& operator<<(ostream& os, const Rational &r)
{
    if(r.numerator == 0 && r.denominator == 0)
        os << NAN;
    else if(r.denominator == 0)
        os << INFINITY;
    else
        ((os << r.numerator) << "/") << r.denominator;
    return os;
}

Rational operator+(const Rational &r1, const Rational &r2)
{
    Rational r(r2.numerator * r1.denominator + r1.numerator * r2.denominator, r2.denominator * r1.denominator);
    return r;
}

double operator+(const double &r1, const Rational &r2)
{
    return double(r2.numerator) / r2.denominator + r1;
}

Rational operator*(const Rational &r1, const Rational &r2)
{
    Rational r(r2.numerator *  r1.numerator , r2.denominator * r1.denominator);
    return r;
}
}
