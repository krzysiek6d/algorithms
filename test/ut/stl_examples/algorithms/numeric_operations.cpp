//
// Created by pawluch on 3/7/19.
//

#include <gtest/gtest.h>
#include <algorithm>
#include <numeric>

TEST(iota, should_increase)
{
    std::vector<int> v{0,0,0,0,0};
    std::iota(v.begin(), v.end(), 0);
    std::vector<int> e{0,1,2,3,4};
    EXPECT_EQ(e,v);
}

TEST(iota, should_increase_starting_from2)
{
    std::vector<int> v{0,0,0,0,0};
    std::iota(v.begin(), v.end(), 2);
    std::vector<int> e{2,3,4,5,6};
    EXPECT_EQ(e,v);
}

TEST(iota, should_increase_starting_from2_and_do_not_take_values_from_initial_container)
{
    std::vector<int> v{0,2,0,2,0};
    std::iota(v.begin(), v.end(), 2);
    std::vector<int> e{2,3,4,5,6};
    EXPECT_EQ(e,v);
}


