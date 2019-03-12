//
// Created by pawluch on 3/7/19.
//

#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>

TEST(find_first_of, checks_any_of_element)
{
    std::vector<int> long_vector{ 7, 3, 1, 2, 3, 6, 1, 2, 3,10};
    std::vector<int> short_vector{ 8, 10, 6 };
    auto it = std::find_first_of(
            std::begin(long_vector), std::end(long_vector),
            std::begin(short_vector), std::end(short_vector)
    );
    auto dist = std::distance(std::begin(long_vector), it);
    std::cout <<
              "First element of short_vector in long_vector at position: "
              << dist
              << std::endl;
    EXPECT_EQ(5u, dist);
    EXPECT_EQ(6, *it);
}

TEST(find_end, checks_subsequences_found)
{
    std::vector<int> long_vector{ 7, 3, 1, 2, 3, 6, 1, 2, 3,10};
    std::vector<int> short_vector{ 1, 2, 3 };
    auto it = std::find_end(
            std::begin(long_vector), std::end(long_vector),
            std::begin(short_vector), std::end(short_vector)
    );
    auto dist = std::distance(std::begin(long_vector), it);
    std::cout <<
              "short_vector last appearance in long_vector at position: "
              << dist
              << std::endl;
    EXPECT_EQ(6u, dist);
    EXPECT_EQ(1, *it);
}

TEST(find_end, checks_subsequences_not_found)
{
    std::vector<int> long_vector{ 7, 3, 1, 2, 3, 6, 1, 2, 3,10};
    std::vector<int> short_vector{ 1, 3, 2 };
    auto it = std::find_end(
            std::begin(long_vector), std::end(long_vector),
            std::begin(short_vector), std::end(short_vector)
    );
    auto dist = std::distance(std::begin(long_vector), it);
    std::cout <<
              "short_vector last appearance in long_vector at position: "
              << dist
              << std::endl;
    EXPECT_EQ(10u, dist);
    EXPECT_EQ(long_vector.end(), it);
}

TEST(search, checks_subsequences_not_found)
{
    std::vector<int> long_vector{ 7, 3, 1, 2, 3, 6, 1, 2, 3,10};
    std::vector<int> short_vector{ 2, 1, 3 };
    auto it = std::search(
            std::begin(long_vector), std::end(long_vector),
            std::begin(short_vector), std::end(short_vector)
    );
    auto dist = std::distance(std::begin(long_vector), it);
    std::cout <<
              "short_vector appears in long_vector at position: "
              << dist
              << std::endl;
    EXPECT_EQ(10u, dist);
    EXPECT_EQ(long_vector.end(), it);
}

TEST(search, checks_subsequences_found)
{
    std::vector<int> long_vector{ 7, 3, 1, 2, 3, 6, 1, 2, 3,10};
    std::vector<int> short_vector{ 1, 2, 3 };
    auto it = std::search(
            std::begin(long_vector), std::end(long_vector),
            std::begin(short_vector), std::end(short_vector)
    );
    auto dist = std::distance(std::begin(long_vector), it);
    std::cout <<
              "short_vector appears in long_vector at position: "
              << dist
              << std::endl;
    EXPECT_EQ(2u, dist);
    EXPECT_EQ(1, *it);
}


TEST(any_of, should_return_true_if_any_element_exists)
{
    std::vector<int> v{1,2,3,4,5};
    EXPECT_TRUE(std::any_of(v.begin(), v.end(), [](const int& v){ return v==3;}));
}

TEST(any_of, should_return_false_on_empty)
{
    std::vector<int> v{};
    EXPECT_FALSE(std::any_of(v.begin(), v.end(), [](const int& v){ return v==3;}));
}

TEST(all_of, should_return_true_on_empty)
{
    std::vector<int> v{};
    EXPECT_TRUE(std::all_of(v.begin(), v.end(), [](const int& v){ return v==3;}));
}

TEST(none_of, should_return_true_on_empty)
{
    std::vector<int> v{};
    EXPECT_TRUE(std::none_of(v.begin(), v.end(), [](const int& v){ return v==3;}));
}