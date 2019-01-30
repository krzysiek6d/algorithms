//
// Created by pawluch on 1/24/19.
//

#include <gtest/gtest.h>
#include <sorting/mergeSort.hpp>

using namespace ::testing;

TEST(MergeSort, sort)
{
//    std::vector<int> x{1, 2, 3, 1, 3, 4, 4, 1, 3, 1};
//    alg::sorting::mergeSort(x.begin(), x.end());
//
//    std::vector<int> expected={1, 1, 1, 1, 2, 3, 3, 3, 4, 4};
//    EXPECT_EQ(expected, x);
}

TEST(MergeSort, merge1)
{
    std::vector<int> x{4, 4}; // sorted
    std::vector<int> y{1, 1, 3}; // sorted
    alg::sorting::detail::merge(x.begin(), x.end(), y.begin(), y.end());

    std::vector<int> expected_p1 = {1, 1}, expected_p2 = {3, 4, 4};
    EXPECT_EQ(expected_p1, x);
    EXPECT_EQ(expected_p2, y);
}


TEST(MergeSort, merge2)
{
    std::vector<int> x{1, 1, 1, 3}; // sorted
    std::vector<int> y{1, 1, 4}; // sorted
    alg::sorting::detail::merge(x.begin(), x.end(), y.begin(), y.end());

    std::vector<int> expected_p1 = {1, 1, 1, 1}, expected_p2 = {1, 3, 4};
    EXPECT_EQ(expected_p1, x);
    EXPECT_EQ(expected_p2, y);
}

TEST(MergeSort, merge3)
{
    std::vector<int> x{1, 1, 5, 6}; // sorted
    std::vector<int> y{1, 4, 7}; // sorted
    alg::sorting::detail::merge(x.begin(), x.end(), y.begin(), y.end());

    std::vector<int> expected_p1 = {1, 1, 1, 4}, expected_p2 = {5, 6, 4};
    EXPECT_EQ(expected_p1, x);
    EXPECT_EQ(expected_p2, y);
}