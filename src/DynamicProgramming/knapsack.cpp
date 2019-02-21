//
// Created by pawluch on 1/29/19.
//

#include <iostream>
#include "knapsack.hpp"
namespace alg
{
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

    namespace dp
    {
        int knapsack(std::vector<std::pair<int, int>> items, int sizeOfKnapsack)
        {
            std::vector<std::vector<int>> dp(sizeOfKnapsack+1, std::vector<int>(items.size()+1));

            for (int i = 1; i <= sizeOfKnapsack; i++)
            {
                for (int j = 1; j <= (int)items.size(); j++)
                {
                    int currentWeight = items[j-1].first;
                    int currentValue  = items[j-1].second;
                    if (currentWeight > i)
                    {
                        dp[i][j] = dp[i][j-1];
                    }
                    else {
                        int temp1 = currentValue + dp[i - currentWeight][j - 1]; //take element
                        int temp2 = dp[i][j - 1]; // omit element
                        dp[i][j] = std::max(temp1, temp2);

                    }
                }
            }
            // printing backwards - works :)
//            int value = dp[sizeOfKnapsack][items.size()];
//            int knapsackSize = sizeOfKnapsack;
//            for (int i = items.size(); i >0 && value > 0; i--)
//            {
//                if (value == dp[sizeOfKnapsack][i-1])
//                    continue;
//                else
//                {
//                    std::cout << "item (" << items[i-1].first << ", " << items[i-1].second << ")" << std::endl;
//                    value = value - items[i-1].second;
//                    knapsackSize = knapsackSize - items[i-1].first;
//                }
//            }
            return dp[sizeOfKnapsack][items.size()];
        }
    }
}