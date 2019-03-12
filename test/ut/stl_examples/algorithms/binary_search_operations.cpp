//
// Created by pawluch on 3/7/19.
//

#include <gtest/gtest.h>
#include <algorithm>
#include <vector>

TEST(lower_bound, should_return_an_iterator_pointing_to_first_element_in_range_that_is_not_less_than_value)
{
    std::vector<int> v{6,7,8,1,4,5};
    std::sort(v.begin(), v.end()); // std::lower_bound works on sorted
    auto it = std::lower_bound(v.begin(), v.end(), 2);
    EXPECT_EQ(4, *it);
}

TEST(lower_bound, should_return_an_iterator_pointing_to_first_element_in_range_that_is_not_less_than_value2)
{
    std::vector<int> v{1, 2, 3, 4, 4, 5, 6};
    auto it = std::lower_bound(v.begin(), v.end(), 4);
    EXPECT_EQ(4, *it);
}

TEST(upper_bound, should_return_an_iterator_pointing_to_first_element_in_range_that_is_greater_than_value)
{
    std::vector<int> v{6,7,8,1,4,5};
    std::sort(v.begin(), v.end()); // works on sorted
    auto it = std::upper_bound(v.begin(), v.end(), 2);
    EXPECT_EQ(4, *it);
}

TEST(upper_bound, should_return_an_iterator_pointing_to_first_element_in_range_that_is_greater_than_value2)
{
    std::vector<int> v{1, 2, 3, 4, 4, 5, 6};
    auto it = std::upper_bound(v.begin(), v.end(), 4);
    EXPECT_EQ(5, *it);
}

TEST(equal_range, is_a_mix_of_lower_bound_and_upper_bound)
{
    std::vector<int> v{1, 2, 3, 4, 4, 5, 6};
    auto it_pair = std::equal_range(v.begin(), v.end(), 4);
    std::vector<int> equal_range_v(it_pair.first, it_pair.second);
    std::vector<int> expected = {4, 4};
    EXPECT_EQ(expected, equal_range_v);
}