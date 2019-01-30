//
// Created by pawluch on 1/30/19.
//
#include <gtest/gtest.h>
#include <DynamicProgramming/ways_to_create_sum.hpp>

using namespace ::testing;


TEST(num_of_ways_to_sum_with_duplcates, tc1_recursive)
{
    std::vector<int> values{1};
    auto num_of_ways = alg::dp::ways_to_create_sum_recursive(values, 1);
    EXPECT_EQ(1, num_of_ways);
}

TEST(num_of_ways_to_sum_with_duplcates, tc2_recursive)
{
    std::vector<int> values{1, 2};
    auto num_of_ways = alg::dp::ways_to_create_sum_recursive(values, 1);
    EXPECT_EQ(1, num_of_ways);
}
TEST(num_of_ways_to_sum_with_duplcates, tc3_recursive)
{
    std::vector<int> values{1, 2};
    auto num_of_ways = alg::dp::ways_to_create_sum_recursive(values, 2);
    EXPECT_EQ(2, num_of_ways);
}

TEST(num_of_ways_to_sum_with_duplcates, tc4_recursive)
{
    std::vector<int> values{1, 2, 3};
    auto num_of_ways = alg::dp::ways_to_create_sum_recursive(values, 3); /// [1,1,1], [1,2], [2.1], [3]
    EXPECT_EQ(4, num_of_ways);
}

TEST(num_of_ways_to_sum_with_duplcates, tc5_recursive)
{
    std::vector<int> values{1, 2, 3};
    auto num_of_ways = alg::dp::ways_to_create_sum_recursive(values, 4); /// [1,1,1,1], [1,1,2], [1,2,1], [2,1,1], [2,2], [3,1], [1,3]
    EXPECT_EQ(7, num_of_ways);
}

//////////////////////////////
TEST(num_of_ways_to_sum_without_duplcates, tc1_recursive)
{
    std::vector<int> values{1};
    auto num_of_ways = alg::dp::ways_to_create_sum_without_duplicates_recursive(values, 1);
    EXPECT_EQ(1, num_of_ways);
}

TEST(num_of_ways_to_sum_without_duplcates, tc2_recursive)
{
    std::vector<int> values{1, 2};
    auto num_of_ways = alg::dp::ways_to_create_sum_without_duplicates_recursive(values, 1);
    EXPECT_EQ(1, num_of_ways);
}
TEST(num_of_ways_to_sum_without_duplcates, tc3_recursive)
{
    std::vector<int> values{1, 2};
    auto num_of_ways = alg::dp::ways_to_create_sum_without_duplicates_recursive(values, 2);
    EXPECT_EQ(1, num_of_ways);
}

TEST(num_of_ways_to_sum_without_duplcates, tc4_recursive)
{
    std::vector<int> values{1, 2, 3};
    auto num_of_ways = alg::dp::ways_to_create_sum_without_duplicates_recursive(values, 3); /// [2.1], [3], [1,2]
    EXPECT_EQ(3, num_of_ways);
}

TEST(num_of_ways_to_sum_without_duplcates, tc5_recursive)
{
    std::vector<int> values{1, 2, 3};
    auto num_of_ways = alg::dp::ways_to_create_sum_without_duplicates_recursive(values, 4); /// [2,2], [3,1], [1,3]
    EXPECT_EQ(3, num_of_ways);
}

//////////////////////////////////////////////////
//TEST(num_of_ways_to_sum_with_duplcates, tc1)
//{
//    std::vector<int> values{1};
//    auto num_of_ways = alg::dp::ways_to_create_sum(values, 1);
//    EXPECT_EQ(1, num_of_ways);
//}