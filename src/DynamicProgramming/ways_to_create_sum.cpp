//
// Created by pawluch on 1/30/19.
//

#include <algorithm>
#include "ways_to_create_sum.hpp"


namespace alg
{
    namespace dp
    {
        int ways_to_create_sum_recursive(std::vector<int> values, int sum)
        {
            if (sum==0)
                return 1;
            int num_of_ways = 0;
            if (sum > 0)
            {
                for (auto&& v: values)
                {
                    num_of_ways += ways_to_create_sum_recursive(values, sum - v);
                }
            }
            return num_of_ways;
        }


        int ways_to_create_sum(std::vector<int> values, int sum)
        {
            return 0;
        }
        ///////////////////////////////////////

        namespace detail
        {
            int ways_to_create_sum_order_does_not_matter_recursive(std::vector<int> values, int sum, int pos)
            {
                return 0;
            }
        }

        int ways_to_create_sum_order_does_not_matter_recursive(std::vector<int> values, int sum)
        {
            int pos = 0;
            return detail::ways_to_create_sum_order_does_not_matter_recursive(values, sum, pos);
        }

        int ways_to_create_sum_order_does_not_matter(std::vector<int> values, int sum)
        {
            return 0;
        }
        

        ////////////////////////////////////////


        int ways_to_create_sum_without_duplicates_recursive(std::vector<int> values, int sum)
        {
            if (sum==0)
                return 1;
            int num_of_ways = 0;
            if (sum > 0)
            {
                for (auto&& v: values)
                {
                    auto new_values = values;
                    auto to_remove = std::find(new_values.begin(), new_values.end(), v);
                    new_values.erase(to_remove);
                    num_of_ways += ways_to_create_sum_recursive(new_values, sum - v);
                }
            }
            return num_of_ways;
        }
        int ways_to_create_sum_without_duplicates(std::vector<int> values, int sum)
        {
            return 0;
        }
    }
}
