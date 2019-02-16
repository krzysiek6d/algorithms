//
// Created by pawluch on 2/8/19.
//

#ifndef ALGORITHMS_TREE_HPP
#define ALGORITHMS_TREE_HPP

#include <memory>
namespace alg
{
    namespace structures
    {
        template <typename T>
        struct tree{
            tree(T val) : value{val} {}
            std::unique_ptr<tree<T>> left;
            std::unique_ptr<tree<T>> right;
            T value;
        };

        template <typename T>
        std::unique_ptr<tree<T>> make_tree(T root_value)
        {
            return std::make_unique<tree<T>>(root_value);
        }
    }


}

#endif //ALGORITHMS_TREE_HPP
