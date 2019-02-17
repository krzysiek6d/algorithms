//
// Created by pawluch on 1/30/19.
//

#include <algorithm>
#include <stdexcept>
#include <iostream>
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

        namespace vartiations_withRepetition_Dp {
            int ways_to_create_sum(std::vector<int> values, int sum)
            {
                std::vector<int> dp(sum+1, 0);
                dp[0] = 1;
                for(int i = 1; i <= sum; i++)
                {
                    for(auto&& v : values)
                    {
                        if (v <= i)
                        {
                            dp[i] += dp[i - v];
                        }
                    }
                }
                return dp[sum];
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

//        namespace vartiations_withoutRepetition_Dp {
//            int ways_to_create_sum(std::vector<int> values, int sum) { // values are changing - dp table should keep that int mind!
//                std::vector<int> dp(sum+1, 0);
//                dp[0] = 1;
//
//                for(int i = 1; i <= sum; i++)
//                {
//                    for (auto v_iter = values.begin(); v_iter!= values.end();)
//                    {
//                        int v = *v_iter;
//                        std::cout << "i: " << i << " v: " << v << std::endl;
//                        if (i - v >= 0) {
//
//                            dp[i] += dp[i - v];
//                            v_iter = values.erase(v_iter);
//                            std::cout << "erasing v: " << v << std::endl;
//                        }
//                        else v_iter ++;
//                    }
//                }
//                return dp[sum];
//            }
//        }
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

        namespace combinations_withoutRepetition_Dp {
            namespace detail {
                int ways_to_create_sum(std::vector<int> values, int sum) {
                    int numofValues = (int)values.size();
                    std::vector<std::vector<int>> dp;
                    std::vector<int> v(numofValues+1, 1);
                    dp.emplace_back(v);
                    for(int i = 1; i <=sum; i++)
                    {
                        std::vector<int> v(numofValues+1, 0);
                        dp.emplace_back(v);
                    }


                    for(int i=1; i<=sum; i++)
                    {
                        for(int j=1; j <= numofValues; j++)
                        {
                            int result = 0;
                            if (i - values[j-1] >= 0 && j-1 >= 0)
                                result += dp[i - values[j-1]][j-1];
                            if (j-1 >= 0)
                                result += dp[i][j-1];
                            dp[i][j] = result;
                        }
                    }
                    return dp[sum][numofValues];

                }
            }

            int ways_to_create_sum(std::vector<int> values, int sum) {
                return detail::ways_to_create_sum(values, sum);
            }
        }

        namespace combinations_withRepetition_Recursive {
            namespace detail {
                int ways_to_create_sum(std::vector<int> values, int sum, int pos) {
                    if (pos < 0 || sum < 0)
                        return 0;
                    if (sum == 0 && pos >= 0)
                        return 1;

                    return std::max(
                           ways_to_create_sum(values, sum - values[pos], pos ),   // we take this element and allow to be reused

                           ways_to_create_sum(values, sum - values[pos], pos - 1) + // we tale element
                           ways_to_create_sum(values, sum,               pos - 1));  // we omit element
                }
            }

            int ways_to_create_sum(std::vector<int> values, int sum) {
                int pos = values.size()-1;
                return detail::ways_to_create_sum(values, sum, pos);
            }
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
            else if (algorithmType==AlgorithmType::DynamicProgramming)
            {
                if (combinatoricsType==CombinatoricsType::Variations)
                {
                    if (repetitionType==RepetitionType::WithRepetition)
                    {
                        return vartiations_withRepetition_Dp::ways_to_create_sum(values, sum);
                    }
//                    if (repetitionType==RepetitionType::WithoutRepetition)
//                    {
//                        return vartiations_withoutRepetition_Dp::ways_to_create_sum(values, sum);
//                    }
                }
                else if (combinatoricsType==CombinatoricsType::Combinations)
                {
                    if (repetitionType == RepetitionType::WithoutRepetition)
                    {
                        return combinations_withoutRepetition_Dp::ways_to_create_sum(values, sum);
                    }
                }
            }
            throw std::runtime_error("type not supported");
        }
    }
}
