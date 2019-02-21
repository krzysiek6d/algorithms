//
// Created by pawluch on 2/21/19.
//

#include <gtest/gtest.h>
#include <DynamicProgramming/knapsack.hpp>

TEST(knapsack, rec1)
{
    using weight = int;
    using value = int;
    std::vector<std::pair<weight, value>> items;
    items.emplace_back(std::make_pair(1, 5));
    EXPECT_EQ(5, alg::recursive::knapsack(items, 1));
}

TEST(knapsack, rec2)
{
    using weight = int;
    using value = int;
    std::vector<std::pair<weight, value>> items;
    items.emplace_back(std::make_pair(1, 5));
    items.emplace_back(std::make_pair(2, 3));
    items.emplace_back(std::make_pair(4, 5));
    items.emplace_back(std::make_pair(2, 3));
    items.emplace_back(std::make_pair(5, 2));
    EXPECT_EQ(16, alg::recursive::knapsack(items, 10));
}