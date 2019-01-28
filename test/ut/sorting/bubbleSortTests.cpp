//
// Created by pawluch on 1/25/19.
//

#include <gtest/gtest.h>
#include <sorting/bubbleSort.hpp>
#include <chrono>

using namespace ::testing;

TEST(BubbleSort, sort)
{
    std::vector<int> x{1, 2, 3, 1, 3, 4, 4, 1, 3, 1};

    auto start = std::chrono::system_clock::now();
    alg::sorting::bubble_sort(x.begin(), x.end());
    auto end = std::chrono::system_clock::now();
    auto elapsed = end - start;
    std::cout << elapsed.count() << '\n';

    auto start2 = std::chrono::system_clock::now();
    alg::sorting::bubble_sort2(x.begin(), x.end());
    auto end2 = std::chrono::system_clock::now();
    auto elapsed2 = end2 - start2;
    std::cout << elapsed2.count() << '\n';

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