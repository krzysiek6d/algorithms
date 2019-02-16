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
            namespace detail {
                template<typename T>
                bool isLeaf(const tree<T> &node) {
                    return node.left == nullptr && node.right == nullptr;
                }

                template<typename T>
                bool hasExactlyOneChild(const tree<T> &node) {
                    return (node.left== nullptr) xor (node.right== nullptr);
                }

                template<typename T>
                bool has2Children(const tree<T> &node) {
                    return node.left != nullptr and node.right != nullptr;
                }
            }

            template <typename T>
            void add(tree<T>& root, T value)
            {
                if (root.value > value)
                {
                    if (root.left)
                        add(*root.left, value);
                    else
                        root.left = std::make_unique<alg::structures::tree<T>>(value);
                }
                else if (root.value < value)
                {
                    if (root.right)
                        add(*root.right, value);
                    else
                        root.right = std::make_unique<alg::structures::tree<T>>(value);
                }
                else
                {
                    throw std::runtime_error("trying to insert duplicate into bst tree!");
                }
            }

            template <typename T>
            void remove(std::unique_ptr<tree<T>>& root, T value)
            {
                if (root->value > value)
                {
                    if (root->left)
                        remove(root->left, value);
                }
                else if (root->value < value)
                {
                    if (root->right)
                        remove(root->right, value);
                }
                else
                {
                    if (detail::isLeaf(*root))
                        root.reset();

                    else if (detail::hasExactlyOneChild(*root)) {
                        if (root->right) {
                            root = std::move(root->right);
                        }
                    }
                    // value is found
                }
            }
        }
    }
}
#endif //ALGORITHMS_BST_TREE_HPP
