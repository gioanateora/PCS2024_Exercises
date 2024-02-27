#ifndef __sqrt_test_HPP__
#define __sqrt_test_HPP__

#include "sqrt_dot.hpp"
#include <gtest/gtest.h>

TEST(DotTest, DotProductSameSizeVector) {
    Eigen::VectorXd v1(3);
    Eigen::VectorXd v2(3);

    v1 << 1.0, 2.0, 3.0;
    v2 << 1.0, 1.0, 1.0;

    ASSERT_EQ(6.0, dotProduct(v1, v2));
}

TEST(DotTest, DotProductDifferentSizeVector)
{

    Eigen::VectorXd v1(3);
    Eigen::VectorXd v2(4);

    v1 << 1.0, 2.0, 3.0;
    v2 << 1.0, 1.0, 1.0, 1.0;

    EXPECT_THROW(dotProduct(v1, v2), std::runtime_error);
}

TEST(SquareRootTest, PositiveNos)
{
    ASSERT_EQ(6, squareRoot(36.0));
    ASSERT_EQ(18.0, squareRoot(324.0));
    ASSERT_EQ(25.4, squareRoot(645.16));
    ASSERT_EQ(0, squareRoot(0.0));
}

TEST(SquareRootTest, NegativeNos)
{
    ASSERT_EQ(-1.0, squareRoot(-15.0));
    ASSERT_EQ(-1.0, squareRoot(-0.2));
}

#endif // __sqrt_test_HPP__
