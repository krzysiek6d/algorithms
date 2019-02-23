//
// Created by pawluch on 1/24/19.
//

#include <gtest/gtest.h>
#include <sorting/mergeSort.hpp>
#include <algorithm>

using namespace ::testing;


TEST(MergeSort, merge1)
{
    std::vector<int> x{4, 4}; // sorted
    std::vector<int> y{1, 1, 3}; // sorted
    auto mergedArray = alg::sorting::detail::merge(x.begin(), x.end(), y.begin(), y.end());

    std::vector<int> expected = {1, 1, 3, 4, 4};
    for (auto i = 0u; i < expected.size(); i++)
    {
        EXPECT_EQ(expected[i], *mergedArray[i]);
    }
}


TEST(MergeSort, merge2)
{
    std::vector<int> x{1, 1, 1, 3}; // sorted
    std::vector<int> y{1, 1, 4}; // sorted
    auto mergedArray = alg::sorting::detail::merge(x.begin(), x.end(), y.begin(), y.end());

    std::vector<int> expected = {1, 1, 1, 1, 1, 3, 4};
    for (auto i = 0u; i < expected.size(); i++)
    {
        EXPECT_EQ(expected[i], *mergedArray[i]);
    }
    std::sort(x.begin(), x.end());
}

TEST(MergeSort, merge3)
{
    std::vector<int> x{1, 1, 5, 6}; // sorted
    std::vector<int> y{1, 4, 7}; // sorted
    auto mergedArray = alg::sorting::detail::merge(x.begin(), x.end(), y.begin(), y.end());

    std::vector<int> expected = {1, 1, 1, 4, 5, 6, 7};
    for (auto i = 0u; i < expected.size(); i++)
    {
        EXPECT_EQ(expected[i], *mergedArray[i]);
    }
}

TEST(MergeSort, relocate1)
{
    std::vector<int> x{1, 1, 5, 6}; // sorted
    std::vector<int> y{1, 4, 7}; // sorted
    alg::sorting::detail::relocateValues(x.begin(), x.end(), y.begin(), y.end(), alg::sorting::detail::merge(x.begin(), x.end(), y.begin(), y.end()));

    std::vector<int> exp_x = {1, 1, 1, 4};
    std::vector<int> exp_y = {5, 6, 7};
    EXPECT_EQ(exp_x, x);
    EXPECT_EQ(exp_y, y);
}

TEST(MergeSort, sort)
{
    std::vector<int> x{1, 4, 7, 1, 1, 1, 4, 7, 5, 6};
    alg::sorting::mergeSort(x.begin(), x.end());

    std::vector<int> exp_x = {1, 1, 1, 1, 4, 4, 5, 6, 7, 7 };
    EXPECT_EQ(exp_x, x);
}

struct my_noncopyable_struct
{
    my_noncopyable_struct(const my_noncopyable_struct&) = delete;
    my_noncopyable_struct operator=(const my_noncopyable_struct&) = delete;

    my_noncopyable_struct(my_noncopyable_struct&&) = default;
    my_noncopyable_struct& operator=(my_noncopyable_struct&&) = default;

    my_noncopyable_struct(int value) : value(value)
    {
    }
    bool operator<(const my_noncopyable_struct& r)
    {
        return value < r.value;
    }
    bool operator==(const my_noncopyable_struct& r) const
    {
        return value == r.value;
    }
    int value;
};

TEST(MergeSort, sort_non_copyable)
{
    std::vector<my_noncopyable_struct> x;
    x.emplace_back(6);
    x.emplace_back(3);
    x.emplace_back(4);
    x.emplace_back(1);
    alg::sorting::mergeSort(x.begin(), x.end());

    std::vector<my_noncopyable_struct> exp_x;
    exp_x.emplace_back(1);
    exp_x.emplace_back(3);
    exp_x.emplace_back(4);
    exp_x.emplace_back(6);
    EXPECT_EQ(exp_x, x);
}