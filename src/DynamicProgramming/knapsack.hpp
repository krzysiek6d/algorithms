//
// Created by pawluch on 1/29/19.
//

#ifndef ALGORITHMS_KNAPSACK_HPP
#define ALGORITHMS_KNAPSACK_HPP

#include <vector>
namespace alg
{
    namespace dp
    {
        int knapsack(std::vector<std::pair<int, int>> items, int sizeOfKnapsack);
    }
    
    namespace recursive
    {
        int knapsack(std::vector<std::pair<int, int>> items, int sizeOfKnapsack);
    }
}


#endif //ALGORITHMS_KNAPSACK_HPP
