//
// Created by pawluch on 3/7/19.
//

#include <gtest/gtest.h>
#include <algorithm>
#include <vector>

TEST(partition, should_return_partition_point)
{
    std::vector<int> v{ 1,5,6,1,3,6,1,8,4,32,5,3 };
    auto partition_point = std::partition(
            std::begin(v), std::end(v),
            [](const auto& item) {
                return item % 3 == 0;
            }
    );
    EXPECT_TRUE(std::all_of(v.begin(), partition_point, [](const int& v){ return v%3==0;}));
    EXPECT_TRUE(std::all_of(partition_point, v.end(), [](const int& v){ return v%3!=0;}));
}

TEST(is_partitioned, should_return_true_if_partitioned)
{
    std::vector<int> v{3,6,0,  1,2,4,5,7};
    EXPECT_TRUE(std::is_partitioned(v.begin(), v.end(), [](const int& v){ return v%3==0;}));
}

TEST(partial_sort, should_sort_on_range)
{
    std::vector<int> v{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
    std::partial_sort(v.begin(), v.begin() + 4, v.end());
    std::vector<int> e{ 0, 1, 2, 3, 8, 7, 6, 9, 5, 4 };
    EXPECT_EQ(e,v);
}

TEST(partial_sort_copy, should_sort_on_range)
{
    std::vector<int> v{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
    std::vector<int> out(4);
    std::partial_sort_copy(v.begin(), v.end(), out.begin(), out.end());
    std::vector<int> e{ 0, 1, 2, 3 };
    EXPECT_EQ(e,out);
}

TEST(nth_element, reorders)
{
    std::vector<int> v{6, 8, 7, 2, 8, 7, 0, 9, 3};
    std::nth_element(v.begin(), v.begin()+3, v.end(), std::greater<int>());
    std::cout << "The third largest element is " << v[2] << '\n';
}


