//
// Created by pawluch on 2/24/19.
//
#include <gtest/gtest.h>
#include <DynamicProgramming/word_break_problem.hpp>

TEST(word_break_problem, recursive1)
{
    std::vector<std::string> dictionary = {"I", "like", "it", "anyway", "any", "way", "don't"};
    EXPECT_TRUE(alg::dp::recursive::word_break_problem("Ilikeit", dictionary));
}

TEST(word_break_problem, recursive2)
{
    std::vector<std::string> dictionary = {"I", "like", "it", "anyway", "any", "way", "don't"};
    EXPECT_TRUE(alg::dp::recursive::word_break_problem("Ilikeitanyway", dictionary));
}

TEST(word_break_problem, recursive3)
{
    std::vector<std::string> dictionary = {"I", "like", "it", "anyway", "any", "way", "don't"};
    EXPECT_FALSE(alg::dp::recursive::word_break_problem("Ilikesit", dictionary));
}

TEST(word_break_problem, recursive4)
{
    std::vector<std::string> dictionary = {"I", "like", "it", "anyway", "any", "way", "don't"};
    EXPECT_FALSE(alg::dp::recursive::word_break_problem("adam", dictionary));
}

