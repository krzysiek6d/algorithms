//
// Created by pawluch on 2/8/19.
//

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
using namespace ::testing;

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