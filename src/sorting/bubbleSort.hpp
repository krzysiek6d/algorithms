//
// Created by pawluch on 1/25/19.
//

#ifndef ALGORITHMS_BUBBLESORT_HPP
#define ALGORITHMS_BUBBLESORT_HPP

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
            auto next = actual + 1;
            while (changed)
            {
                changed = false;
                while(next != last)
                {
                    if (*actual > *next) {
                        std::swap(*actual, *next);
                        changed = true;
                    }
                    actual++;
                    next = actual +1;
                }
                actual = first;
                next = actual + 1;
            }
        }
    }
}

#endif //ALGORITHMS_BUBBLESORT_HPP
