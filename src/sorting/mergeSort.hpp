//
// Created by pawluch on 1/24/19.
//

#ifndef ALGORITHMS_MERGESORT_HPP
#define ALGORITHMS_MERGESORT_HPP


#include <iterator>
#include <iostream>
#include <vector>

namespace alg
{
    namespace sorting
    {
        namespace detail
        {
            template <typename RandomIt>
            inline constexpr std::vector<RandomIt> merge(RandomIt begin1, RandomIt end1, RandomIt begin2, RandomIt end2) {
                auto length = std::distance(begin1, end1) + std::distance(begin2, end2);
                std::vector<RandomIt> mergedIterators;
                mergedIterators.reserve(length);
                for (auto i = 0u; i < length; i++) {
                    if (begin1 != end1) {
                        if (begin2 != end2) {
                            if (*begin1 < *begin2) {
                                mergedIterators.emplace_back(begin1);
                                begin1 = std::next(begin1);
                            } else {
                                mergedIterators.emplace_back(begin2);
                                begin2 = std::next(begin2);
                            }
                        } else {
                            mergedIterators.emplace_back(begin1);
                            begin1 = std::next(begin1);
                        }
                    } else if (begin2 != end2) {
                        mergedIterators.emplace_back(begin2);
                        begin2 = std::next(begin2);
                    }
                }
                return mergedIterators;
            }
            template <typename RandomIt>
            inline constexpr void relocateValues(RandomIt begin1, RandomIt end1, RandomIt begin2, RandomIt end2, std::vector<RandomIt> mergedIterators)
            {
                auto i = 0u;
                std::vector<typename std::remove_reference<decltype(*begin1)>::type> values;
                for (auto && elemIt: mergedIterators)
                {
                    values.emplace_back(std::move(*elemIt));
                }
                while (begin1 != end1)
                {
                    *begin1 = std::move(values[i]);
                    begin1 = std::next(begin1);
                    i++;
                }
                while (begin2 != end2)
                {
                    *begin2 = std::move(values[i]);
                    begin2 = std::next(begin2);
                    i++;
                }
            }
        }
        template <typename RandomIt>
        constexpr void mergeSort(RandomIt begin, RandomIt end)
        {
            auto distance = std::distance(begin, end);
            if (distance >= 2) {
                auto middle = distance/2;
                mergeSort(begin, std::next(begin, middle));
                mergeSort(std::next(begin, middle), end);
                detail::relocateValues(begin, std::next(begin, middle), std::next(begin, middle), end,
                        detail::merge(begin, std::next(begin, middle), std::next(begin, middle), end));
            }
        }
    }
}


#endif //ALGORITHMS_MERGESORT_HPP
