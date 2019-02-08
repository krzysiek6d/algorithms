//
// Created by pawluch on 2/8/19.
//

#include <gtest/gtest.h>
#include <data_structures/tree.hpp>

using namespace ::testing;

template <typename T>
std::unique_ptr<alg::structures::tree<T>> createNode(T value)
{
    return std::make_unique<alg::structures::tree<T>>(value);
}

TEST(tree, check_adding_elements)
{
    alg::structures::tree<int> tree{0};
    tree.left = createNode(1);
    tree.right = createNode(2);
    tree.left->left = createNode(3);
    tree.left->right = createNode(4);

    EXPECT_EQ(0, tree.value);
    EXPECT_EQ(1, tree.left->value);
    EXPECT_EQ(3, tree.left->left->value);
    EXPECT_EQ(4, tree.left->right->value);
    EXPECT_EQ(2, tree.right->value);
}
