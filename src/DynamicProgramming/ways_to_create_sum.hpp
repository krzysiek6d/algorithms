//
// Created by pawluch on 1/30/19.
//

#ifndef ALGORITHMS_WAYS_TO_CREATE_SUM_HPP
#define ALGORITHMS_WAYS_TO_CREATE_SUM_HPP
#include <vector>
namespace alg
{
    namespace dp
    {
        int ways_to_create_sum_recursive(std::vector<int> values, int sum);
        int ways_to_create_sum(std::vector<int> values, int sum);

        int ways_to_create_sum_order_does_not_matter_recursive(std::vector<int> values, int sum);
        int ways_to_create_sum_order_does_not_matter(std::vector<int> values, int sum);

        int ways_to_create_sum_without_duplicates_recursive(std::vector<int> values, int sum);
        int ways_to_create_sum_without_duplicates(std::vector<int> values, int sum);
    }
}


#endif //ALGORITHMS_WAYS_TO_CREATE_SUM_HPP
