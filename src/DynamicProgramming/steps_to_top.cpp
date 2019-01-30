//
// Created by pawluch on 1/29/19.
//

#include "steps_to_top.hpp"

namespace alg
{
    namespace dp
    {
        int num_of_ways_to_reach_the_top(int height, const std::vector<int>& allowed_jumps)
        {
            std::vector<int> dp(height+1, 0);
            dp[0] = 1;

            for (int current_height = 1; current_height <= height; current_height++)
            {
                int numOfWays = 0;
                for(auto&& jump: allowed_jumps)
                {
                    if (current_height - jump >= 0)
                    {
                        numOfWays += dp[current_height - jump];
                    }
                }
                dp[current_height] = numOfWays;
            }
            return dp[height];
        }
    }
}
