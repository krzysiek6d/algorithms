//
// Created by pawluch on 3/6/19.
//

#include <gtest/gtest.h>
#include <vector>
#include <list>
namespace iterators
{
    template <typename It>
    void bubble_sort(It begin, It end)
    {
        if (begin == end)
            return;

        auto actual = begin;
        auto next = std::next(begin);
        bool changed = true;
        while(changed)
        {
            changed = false;
            while(next != end)
            {
                if (*actual > *next)
                {
                    changed = true;
                    std::swap(*actual, *next);
                }
                actual = std::next(actual);
                next = std::next(next);
            }
            actual = begin;
            next = std::next(actual);
        }
    }
}

TEST(bubble_sort, should_not_crash_with_empty_data)
{
    std::vector<int> v{};
    iterators::bubble_sort(v.begin(), v.end());
}

TEST(bubble_sort, should_sort)
{
    std::vector<int> v{1,3,5,6,3,3,0,-1,4};
    iterators::bubble_sort(v.begin(), v.end());
    std::vector<int> expected{-1,0,1,3,3,3,4,5,6};
    EXPECT_EQ(expected,v);
}

TEST(bubble_sort, should_sort_on_list)
{
    std::list<int> v{1,3,5,6,3,3,0,-1,4};
    iterators::bubble_sort(v.begin(), v.end());
    std::list<int> expected{-1,0,1,3,3,3,4,5,6};
    EXPECT_EQ(expected,v);
}