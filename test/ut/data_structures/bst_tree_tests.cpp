//
// Created by pawluch on 2/8/19.
//
#include <gtest/gtest.h>
#include <data_structures/bst_tree.hpp>

using namespace ::testing;

TEST(bst, adding)
{
    auto tree = alg::structures::make_tree(0);
    alg::structures::bst::add(*tree, 1);
    alg::structures::bst::add(*tree, 6);
    alg::structures::bst::add(*tree, 2);
    alg::structures::bst::add(*tree, 3);
    alg::structures::bst::add(*tree, 12);
    alg::structures::bst::add(*tree, 5);
    alg::structures::bst::add(*tree, 7);

    EXPECT_EQ(0, tree->value);
    EXPECT_EQ(1, tree->right->value);
    EXPECT_EQ(6, tree->right->right->value);
    EXPECT_EQ(2, tree->right->right->left->value);
    EXPECT_EQ(3, tree->right->right->left->right->value);
    EXPECT_EQ(12, tree->right->right->right->value);
    EXPECT_EQ(5, tree->right->right->left->right->right->value);
    EXPECT_EQ(7, tree->right->right->right->left->value);
}


TEST(bst, remove_when_only_root)
{
    auto tree = alg::structures::make_tree(0);
    EXPECT_EQ(0, tree->value);
    alg::structures::bst::remove(tree, 0);
    EXPECT_EQ(nullptr, tree);
}

TEST(bst, remove_when_only_root_and_right)
{
    auto tree = alg::structures::make_tree(0);
    alg::structures::bst::add(*tree, 1);
    EXPECT_EQ(0, tree->value);
    EXPECT_EQ(1, tree->right->value);
    alg::structures::bst::remove(tree, 0);
    EXPECT_EQ(1, tree->value);
}