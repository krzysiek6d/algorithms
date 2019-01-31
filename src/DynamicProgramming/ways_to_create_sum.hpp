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
        enum class AlgorithmType
        {
            DynamicProgramming,
            Recursive
        };
        enum class RepetitionType
        {
            WithRepetition,
            WithoutRepetition
        };
        enum class CombinatoricsType
        {
            Variations,
            Combinations
        };

        int ways_to_create_sum(std::vector<int> values, int sum,
                               AlgorithmType algorithmType,
                               CombinatoricsType combinatoricsType, RepetitionType repetitionType);
    }
}


#endif //ALGORITHMS_WAYS_TO_CREATE_SUM_HPP
