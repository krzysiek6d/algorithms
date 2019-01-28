//
// Created by pawluch on 1/28/19.
//

#include <DynamicProgramming/fibonacci.hpp>
#include <gtest/gtest.h>

using namespace ::testing;

TEST(fibonacci, calculate)
{
    EXPECT_EQ(1u, alg::dp::fibonacci(0));
    EXPECT_EQ(1u, alg::dp::fibonacci(1));
    EXPECT_EQ(2u, alg::dp::fibonacci(2));
    EXPECT_EQ(3u, alg::dp::fibonacci(3));
    EXPECT_EQ(5u, alg::dp::fibonacci(4));
    EXPECT_EQ(8u, alg::dp::fibonacci(5));
    EXPECT_EQ(13u, alg::dp::fibonacci(6));
    EXPECT_EQ(21u, alg::dp::fibonacci(7));
}

TEST(fibonacci, calculate_2)
{
    EXPECT_EQ(1u, alg::dp::fibonacci_2(0));
    EXPECT_EQ(1u, alg::dp::fibonacci_2(1));
    EXPECT_EQ(2u, alg::dp::fibonacci_2(2));
    EXPECT_EQ(3u, alg::dp::fibonacci_2(3));
    EXPECT_EQ(5u, alg::dp::fibonacci_2(4));
    EXPECT_EQ(8u, alg::dp::fibonacci_2(5));
    EXPECT_EQ(13u, alg::dp::fibonacci_2(6));
    EXPECT_EQ(21u, alg::dp::fibonacci_2(7));
}