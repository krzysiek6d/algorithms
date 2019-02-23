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
                RandomIt begin1_ = begin1;
                RandomIt end1_ = end1;
                RandomIt begin2_ = begin2;
                RandomIt end2_ = end2;
                auto length = std::distance(begin1_, end1_) + std::distance(begin2_, end2_);
                std::vector<RandomIt> mergedIterators;
                mergedIterators.reserve(length);
                for (auto i = 0u; i < length; i++) {
                    if (begin1_ != end1_) {
                        if (begin2_ != end2_) {
                            if (*begin1_ < *begin2_) {
                                mergedIterators.emplace_back(begin1_);
                                begin1_ = std::next(begin1_);
                            } else {
                                mergedIterators.emplace_back(begin2_);
                                begin2_ = std::next(begin2_);
                            }
                        } else {
                            mergedIterators.emplace_back(begin1_);
                            begin1_ = std::next(begin1_);
                        }
                    } else if (begin2_ != end2_) {
                        mergedIterators.emplace_back(begin2_);
                        begin2_ = std::next(begin2_);
                    }
                }
                return mergedIterators;
            }
            template <typename RandomIt>
            inline constexpr void relocateValues(RandomIt begin1, RandomIt end1, RandomIt begin2, RandomIt end2, std::vector<RandomIt> mergedIterators)
            {

                RandomIt begin1_ = begin1;
                RandomIt end1_ = end1;
                RandomIt begin2_ = begin2;
                RandomIt end2_ = end2;
                auto i = 0u;
                std::vector<typename std::remove_reference<decltype(*begin1_)>::type> values;
                for (auto && elemIt: mergedIterators)
                {
                    values.emplace_back(std::move(*elemIt));
                }
                while (begin1_ != end1_)
                {
                    *begin1_ = std::move(values[i]);
                    begin1_ = std::next(begin1_);
                    i++;
                }
                while (begin2_ != end2_)
                {
                    *begin2_ = std::move(values[i]);
                    begin2_ = std::next(begin2_);
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
