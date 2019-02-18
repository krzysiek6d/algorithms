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