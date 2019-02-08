//
// Created by pawluch on 2/8/19.
//

#ifndef ALGORITHMS_BST_TREE_HPP
#define ALGORITHMS_BST_TREE_HPP

#include "tree.hpp"
namespace alg
{
    namespace structures
    {
        namespace bst
        {
            template <typename T>
            void add(std::unique_ptr<tree<T>>& root, T value)
            {
                if (root->value > value)
                {
                    if (root->left)
                        add(root->left, value);
                    else
                        root->left = std::make_unique<alg::structures::tree<T>>(value);
                }
                else if (root->value < value)
                {
                    if (root->right)
                        add(root->right, value);
                    else
                        root->right = std::make_unique<alg::structures::tree<T>>(value);
                }
                else
                {
                    throw std::runtime_error("trying to insert duplicate into bst tree!");
                }


            }
        }
    }
}
#endif //ALGORITHMS_BST_TREE_HPP
