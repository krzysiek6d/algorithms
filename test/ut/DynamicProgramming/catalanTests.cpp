//
// Created by pawluch on 1/28/19.
//

#include <DynamicProgramming/catalan.hpp>
#include <gtest/gtest.h>

using namespace ::testing;

TEST(catalan, calculate)
{
    EXPECT_EQ(1u, alg::dp::catalan(0));
    EXPECT_EQ(1u, alg::dp::catalan(1));
    EXPECT_EQ(2u, alg::dp::catalan(2));
    EXPECT_EQ(5u, alg::dp::catalan(3));
    EXPECT_EQ(14u, alg::dp::catalan(4));
    EXPECT_EQ(42u, alg::dp::catalan(5));
    EXPECT_EQ(132u, alg::dp::catalan(6));
    EXPECT_EQ(429u, alg::dp::catalan(7));
}