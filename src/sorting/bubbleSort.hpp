//
// Created by pawluch on 1/25/19.
//

#ifndef ALGORITHMS_BUBBLESORT_HPP
#define ALGORITHMS_BUBBLESORT_HPP

#include <algorithm>
#include <functional>
#include <iostream>

namespace alg
{
    namespace sorting
    {
        template <typename RandomIt>
        constexpr void bubble_sort(RandomIt first, RandomIt last)
        {
            bool changed = true;
            if (first == last)
                return;
            auto actual = first;
            auto next = std::next(actual);
            do
            {
                changed = false;
                while(next != last)
                {
                    if (*actual > *next) {
                        std::swap(*actual, *next);
                        changed = true;
                    }
                    actual = std::next(actual);
                    next = std::next(actual);
                }
                actual = first;
                next = std::next(actual);
            } while (changed);
        }

        template <typename RandomIt>
        std::vector<RandomIt> bubble_sort2(RandomIt first, RandomIt last)
        {
            std::vector<RandomIt> sorted_view;
            for (;first!=last;)
            {
                sorted_view.push_back(first);
                first = std::next(first);
            }
            auto sorted_view_first = std::begin(sorted_view);
            auto sorted_view_last = std::end(sorted_view);
            bool changed = true;
            if (sorted_view_first == sorted_view_last)
                return std::vector<RandomIt>{};
            auto actual = std::begin(sorted_view);
            auto next = std::next(actual);
            do
            {
                changed = false;
                while(next != sorted_view_last)
                {
                    if (actual > next) {
                        std::swap(actual, next);
                        changed = true;
                    }
                    actual = std::next(actual);
                    next = std::next(actual);
                }
                actual = sorted_view_first;
                next = std::next(actual);
            } while (changed);
            return sorted_view;
        }

    }
}

#endif //ALGORITHMS_BUBBLESORT_HPP
