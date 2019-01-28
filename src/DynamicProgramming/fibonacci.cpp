//
// Created by pawluch on 1/28/19.
//

#include "fibonacci.hpp"
#include <vector>

namespace alg
{
    namespace dp
    {
        uint32_t fibonacci(uint32_t n) // todo - memo cache size can be constant - 2
        {
            auto memo = std::vector<uint32_t >(n + 2, 0); // n + 2 : in case of n=0 assigning to memo[1] should be valid
            memo[0] = 1;
            memo[1] = 1;
            for (uint32_t i = 2; i <= n; i++)
            {
                memo[i] = memo[i-1] + memo[i-2];
            }
            return memo[n];
        }
    }
}
