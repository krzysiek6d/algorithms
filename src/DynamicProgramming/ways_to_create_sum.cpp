//
// Created by pawluch on 1/30/19.
//

#include <algorithm>
#include <stdexcept>
#include "ways_to_create_sum.hpp"


namespace alg
{
    namespace dp
    {
        namespace vartiations_withRepetition_Recursive {
            int ways_to_create_sum(std::vector<int> values, int sum) {
                if (sum == 0)
                    return 1;
                int num_of_ways = 0;
                if (sum > 0) {
                    for (auto &&v: values) {
                        num_of_ways += ways_to_create_sum(values, sum - v);
                    }
                }
                return num_of_ways;
            }
        }
        namespace vartiations_withoutRepetition_Recursive {
            int ways_to_create_sum(std::vector<int> values, int sum) {
                if (sum == 0)
                    return 1;
                int num_of_ways = 0;
                if (sum > 0) {
                    for (auto &&v: values) {
                        auto new_values = values;
                        auto to_remove = std::find(new_values.begin(), new_values.end(), v);
                        new_values.erase(to_remove);
                        num_of_ways += ways_to_create_sum(new_values, sum - v);
                    }
                }
                return num_of_ways;
            }
        }

        int ways_to_create_sum(std::vector<int> values, int sum)
        {
            return 0;
        }
        ///////////////////////////////////////
        namespace combinations_withoutRepetition_Recursive {
            namespace detail {
                int ways_to_create_sum(std::vector<int> values, int sum, int pos) {
                    if (sum==0)
                        return 1;
                    if (sum < 0)
                        return 0;
                    if (pos < 0)
                        return 0;
                    else
                        return ways_to_create_sum(values, sum - values[pos], pos - 1) + // we tale element
                               ways_to_create_sum(values, sum, pos - 1);                // we omit element
                }
            }

            int ways_to_create_sum(std::vector<int> values, int sum) {
                int pos = values.size()-1;
                return detail::ways_to_create_sum(values, sum, pos);
            }
        }

        namespace combinations_withRepetition_Recursive {
            namespace detail {
                int ways_to_create_sum(std::vector<int> values, int sum, int pos) {
                    if (sum==0)
                        return 1;
                    if (sum < 0)
                        return 0;
                    if (pos < 0)
                        return 0;
                    else
                        return ways_to_create_sum(values, sum - values[pos], pos )    + // we take this element and allow to be reused
                               ways_to_create_sum(values, sum - values[pos], pos - 1) + // we tale element
                               ways_to_create_sum(values, sum,               pos - 1);  // we omit element
                }
            }

            int ways_to_create_sum(std::vector<int> values, int sum) {
                int pos = values.size()-1;
                return detail::ways_to_create_sum(values, sum, pos);
            }
        }

        int ways_to_create_sum_order_does_not_matter(std::vector<int> values, int sum)
        {
            return 0;
        }


        ////////////////////////////////////////



        int ways_to_create_sum_without_duplicates(std::vector<int> values, int sum)
        {
            return 0;
        }



        int ways_to_create_sum(std::vector<int> values, int sum,
                               AlgorithmType algorithmType,
                               CombinatoricsType combinatoricsType,
                               RepetitionType repetitionType)
        {
            if (algorithmType==AlgorithmType::Recursive)
            {
                if (combinatoricsType==CombinatoricsType::Combinations) // [2,1] == [1,2]
                {
                    if (repetitionType==RepetitionType::WithRepetition) // [1,1,1] OK
                    {
                        return combinations_withRepetition_Recursive::ways_to_create_sum(values, sum);
                    }
                    else if(repetitionType==RepetitionType::WithoutRepetition) // [1,1,1] NOK, [1,2,3] OK
                    {
                        return combinations_withoutRepetition_Recursive::ways_to_create_sum(values, sum);
                    }
                }
                else if (combinatoricsType==CombinatoricsType::Variations) // [2,1] != [1,2]
                {
                    if (repetitionType==RepetitionType::WithRepetition)
                    {
                        return vartiations_withRepetition_Recursive::ways_to_create_sum(values, sum);
                    }
                    else if(repetitionType==RepetitionType::WithoutRepetition)
                    {
                        return vartiations_withoutRepetition_Recursive::ways_to_create_sum(values, sum);
                    }
                }
            }
            throw std::runtime_error("type not supported");
        }
    }
}
