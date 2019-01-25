//
// Created by pawluch on 1/25/19.
//

#include <gtest/gtest.h>
#include <sorting/bubbleSort.hpp>

using namespace ::testing;

TEST(BubbleSort, sort)
{
    std::vector<int> x{1, 2, 3, 1, 3, 4, 4, 1, 3, 1};
    alg::sorting::bubble_sort(x.begin(), x.end());

    std::vector<int> expected={1, 1, 1, 1, 2, 3, 3, 3, 4, 4};
    EXPECT_EQ(expected, x);
}

TEST(BubbleSort, oneElement)
{
    std::vector<int> x{1};
    alg::sorting::bubble_sort(x.begin(), x.end());

    std::vector<int> expected={1};
    EXPECT_EQ(expected, x);
}


TEST(BubbleSort, noElements)
{
    std::vector<int> x{};
    alg::sorting::bubble_sort(x.begin(), x.end());

    std::vector<int> expected={};
    EXPECT_EQ(expected, x);
}

TEST(BubbleSort, twoElementsInOrder)
{
    std::vector<int> x{1, 2};
    alg::sorting::bubble_sort(x.begin(), x.end());

    std::vector<int> expected={1, 2};
    EXPECT_EQ(expected, x);
}

TEST(BubbleSort, twoElementsRandomized)
{
    std::vector<int> x{2, 1};
    alg::sorting::bubble_sort(x.begin(), x.end());

    std::vector<int> expected={1, 2};
    EXPECT_EQ(expected, x);
}

TEST(BubbleSort, twoElementsAreEqual)
{
    std::vector<int> x{2, 2};
    alg::sorting::bubble_sort(x.begin(), x.end());

    std::vector<int> expected={2, 2};
    EXPECT_EQ(expected, x);
}