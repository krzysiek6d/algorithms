//
// Created by pawluch on 3/7/19.
//
#include <gtest/gtest.h>
#include <algorithm>
TEST(fill, fills_range)
{
    std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::fill(v.begin(), v.end(), -1);
    for (auto elem : v) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
    std::vector<int> expected(10, -1);
    EXPECT_EQ(expected, v);
}

TEST(fill_n, fills_range)
{
    std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::fill_n(v.begin(), 5, -1);
    for (auto elem : v) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
    std::vector<int> expected{ -1, -1, -1, -1, -1, 5, 6, 7, 8, 9 };
    EXPECT_EQ(expected, v);
}

TEST(fill_n, DISABLED_should_have_prealocated_memory)
{
    std::vector<int> v{};
    std::fill_n(v.begin(), 5, -1);
}

TEST(fill_n, can_use_back_inserter_when_collection_is_not_initialized)
{
    std::vector<int> v{1, 2};
    std::fill_n(std::back_inserter(v), 5, -1);
    std::vector<int> expected{1, 2, -1, -1, -1, -1, -1 };
    EXPECT_EQ(expected, v);
}


TEST(generate, from_function_on_range)
{
    std::vector<int> v{9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
    std::generate(v.begin(), v.end()-5, [n = 0] () mutable { return n++; });
    for (auto elem : v) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
    std::vector<int> expected{ 0, 1, 2, 3, 4, 9, 9, 9, 9, 9 };
    EXPECT_EQ(expected, v);
}

TEST(iter_swap, should_swap_elements_under_iter)
{
    std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    auto it_to_2 = std::find(std::begin(v), std::end(v), 2);
    auto it_to_6 = std::find(std::begin(v), std::end(v), 6);
    std::vector<int> e{ 1, 6, 3, 4, 5, 2, 7, 8, 9, 10 };
    std::iter_swap(it_to_2, it_to_6);
    EXPECT_EQ(e,v);
}


TEST(remove_copy_if, should_copy_matched_values_into_new_vector)
{
    std::vector<int> input = {1, 3, 4, 5, 8, 7, 3, 2};
    std::vector<int> out = {};
    std::remove_copy_if(input.begin(), input.end(), std::back_inserter(out), [](const int& value) { return value%2 == 0;});
    std::vector<int> expected_out = { 1, 3, 5, 7, 3 };
    std::vector<int> expected_input = {1, 3, 4, 5, 8, 7, 3, 2};
    EXPECT_EQ(expected_out, out);
    EXPECT_EQ(expected_input, input);
}
