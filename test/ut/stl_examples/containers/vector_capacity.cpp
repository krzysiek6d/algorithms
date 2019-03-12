//
// Created by pawluch on 3/6/19.
//
#include <gtest/gtest.h>
#include <vector>


TEST(test_vector, capacity)
{
    std::vector<int> v{};
    EXPECT_EQ(0u, v.capacity());

    v.emplace_back(1);
    EXPECT_EQ(1u, v.capacity());
    EXPECT_EQ(1u, v.size());

    v.emplace_back(2);
    EXPECT_EQ(2u, v.capacity());
    EXPECT_EQ(2u, v.size());

    v.emplace_back(3);
    EXPECT_EQ(4u, v.capacity());
    EXPECT_EQ(3u, v.size());

    v.emplace_back(4);
    EXPECT_EQ(4u, v.capacity());
    EXPECT_EQ(4u, v.size());

    v.emplace_back(5);
    EXPECT_EQ(8u, v.capacity());
    EXPECT_EQ(5u, v.size());
}