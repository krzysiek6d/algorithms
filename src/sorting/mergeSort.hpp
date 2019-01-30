//
// Created by pawluch on 1/24/19.
//

#ifndef ALGORITHMS_MERGESORT_HPP
#define ALGORITHMS_MERGESORT_HPP


#include <iterator>
#include <iostream>

namespace alg
{
    namespace sorting
    {
        namespace detail
        {
            template <typename RandomIt>
            inline constexpr void merge(RandomIt begin1, RandomIt end1, RandomIt begin2, RandomIt end2)
            {
                RandomIt begin1_ = begin1;
                RandomIt end1_ = end1;
                RandomIt begin2_  = begin2;
                RandomIt end2_ = end2;
                std::cout << "BEFORE MERGE" << std::endl;
                std::copy(begin1, end1, std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
                std::copy(begin2, end2, std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;

                while (begin1 != end1 && begin2 != end2)
                {
                    if (*begin1 > *begin2)
                    {
                        std::swap(*begin1, *begin2);
                        begin1 = std::next(begin1);
                        begin2 = std::next(begin2);
                    } else
                    {
                        begin1 = std::next(begin1);
                    }
                }
//                while (begin1 != end1) // first [] was longer
//                {
//
//                }
//                while (begin2 != end2) // first [] was longer
//                {
//
//                }
                std::cout << "AFTER MERGE" << std::endl;
                std::copy(begin1_, end1_, std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
                std::copy(begin2_, end2_, std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
            }
        }
        template <typename RandomIt>
        constexpr void mergeSort(RandomIt begin, RandomIt end)
        {
            std::cout << "MERGE SORT CALLED FOR: ";
            std::copy(begin, end, std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
            auto distance = std::distance(begin, end);
            if (distance >= 2) {
                auto middle = distance/2;
                mergeSort(begin, std::next(begin, middle));
                mergeSort(std::next(begin, middle), end);
                detail::merge(begin, std::next(begin, middle), std::next(begin, middle), end);
            }
        }
    }
}


#endif //ALGORITHMS_MERGESORT_HPP
