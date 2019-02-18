#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

template <template <typename,typename> class Container, typename T, typename Allocator>
T pop_me(Container<T, Allocator>& v)
{
    std::pop_heap(v.begin(), v.end());
    auto value = v.back();
    v.pop_back();
    return value;
}


TEST(stl_heap, get_max)
{
    std::vector<int> v {1,2,3,4,5,6,7,8,9};
    std::make_heap(v.begin(), v.end());
    while(v.size())
    {
        auto max = *std::max_element(v.begin(), v.end());
        auto value = pop_me(v);
        EXPECT_EQ(max, value);
    }
}

TEST(stl_heap, heap_balancing_after_pop)
{
    std::vector<int> v {1,2,3,4,5,6,7,8,9};
    std::make_heap(v.begin(), v.end());

    std::vector<int> after_pop9 = {8, 5, 7, 4, 1, 6, 3, 2};
    std::vector<int> after_pop8 = {7, 5, 6, 4, 1, 2, 3};
    std::vector<int> after_pop7 = {6, 5, 3, 4, 1, 2};

    pop_me(v);
    EXPECT_EQ(after_pop9, v);

    pop_me(v);
    EXPECT_EQ(after_pop8, v);

    pop_me(v);
    EXPECT_EQ(after_pop7, v);
}

TEST(stl_heap, make_heap)
{
    std::vector<int> v{5, 3, 2, 8, 7};
    std::make_heap(v.begin(), v.end());

    /*
     1.
        5

     2.
           5
         3

     3.
           5
         3   2

     4.
           8
         5   2
       3

     5.

           8
         7   2
        3 5

     */


    std::vector<int> expected_heap{8, 7, 2, 3, 5};
    EXPECT_EQ(expected_heap, v);
}


TEST(stl_heap, sort_heap)
{
    std::vector<int> v{5, 3, 2, 8, 7};
    std::make_heap(v.begin(), v.end());
    std::sort_heap(v.begin(), v.end());
    std::vector<int> expected_heap{2, 3, 5, 7, 8};
    EXPECT_EQ(expected_heap, v);
}

TEST(stl_heap, sort_heap_on_none_heap_can_lead_to_non_sorted)
{
    std::vector<int> v{5, 3, 2, 8, 7};
    std::sort_heap(v.begin(), v.end());

    std::vector<int> properly_sorted_data{2, 3, 5, 7, 8};
    EXPECT_NE(properly_sorted_data, v);
}