//
// Created by pawluch on 1/29/19.
//

#include <gtest/gtest.h>
#include <DynamicProgramming/steps_to_top.hpp>

using namespace ::testing;

TEST(stepToTop, tc1)
{
    auto actual = 0;
    actual = alg::dp::num_of_ways_to_reach_the_top(1, {1,2});
    EXPECT_EQ(1, actual);

    actual = alg::dp::num_of_ways_to_reach_the_top(2, {1,2});
    EXPECT_EQ(2, actual);

    actual = alg::dp::num_of_ways_to_reach_the_top(3, {1,2});
    EXPECT_EQ(3, actual);

    actual = alg::dp::num_of_ways_to_reach_the_top(4, {1,2});
    EXPECT_EQ(5, actual);

    actual = alg::dp::num_of_ways_to_reach_the_top(5, {1,2});
    EXPECT_EQ(8, actual);
}
