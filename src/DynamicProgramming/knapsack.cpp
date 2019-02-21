//
// Created by pawluch on 1/29/19.
//

#include "knapsack.hpp"
namespace alg
{
    namespace dp
    {

        int knapsack(std::vector<std::pair<int, int>> items, int sizeOfKnapsack)
        {
            return {};
        };
    }
    namespace recursive
    {
        namespace detail {
            int knapsack(std::vector<std::pair<int, int>> items, int sizeofKnapsack, int pos) {
                if (sizeofKnapsack == 0 || pos == 0)
                    return 0;
                else
                {
                    int result = 0;
                    int currentWeight = items[pos-1].first;
                    int currentValue  = items[pos-1].second;

                    if (currentWeight > sizeofKnapsack)
                    {
                        result = knapsack(items, sizeofKnapsack, pos - 1); // omit element
                    }
                    else
                    {
                        int temp1 = currentValue + knapsack(items, sizeofKnapsack - currentWeight, pos-1); //take element
                        int temp2 = knapsack(items, sizeofKnapsack, pos-1); // omit element
                        result = std::max(temp1, temp2);
                    }
                    return result;
                }
            }
        }

        int knapsack(std::vector<std::pair<int, int>> items, int sizeOfKnapsack)
        {
            return detail::knapsack(items, sizeOfKnapsack, items.size());
        }
    }
}