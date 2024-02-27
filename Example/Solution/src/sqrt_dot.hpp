#ifndef __sqrt_HPP__
#define __sqrt_HPP__

#include <math.h>
#include "Eigen/Eigen"

double dotProduct(const Eigen::VectorXd& v1,
                  const Eigen::VectorXd& v2)
{

    if(v1.size() != v2.size())
        throw std::runtime_error("Not compatible vectors.");

    return v1.transpose() * v2;
}

// Get the Square root of a number.
double squareRoot(const double a)
{
    const double b = sqrt(a);

    if (b != b) // NaN check
        return -1.0;
    else
        return b;
}

#endif // __sqrt_HPP__
