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
    std::vector<std::string> dictionary = {"mobile","samsung","sam","sung",
                                           "man","mango","icecream","and",
                                           "go","i","like","ice","cream"}; ;
    EXPECT_TRUE(alg::dp::recursive::word_break_problem("ilikesamsung", dictionary));
    EXPECT_TRUE(alg::dp::recursive::word_break_problem("iiiiiiii", dictionary));
    EXPECT_TRUE(alg::dp::recursive::word_break_problem("", dictionary));
    EXPECT_TRUE(alg::dp::recursive::word_break_problem("ilikelikeimangoiii", dictionary));
    EXPECT_TRUE(alg::dp::recursive::word_break_problem("samsungandmango", dictionary));
    EXPECT_FALSE(alg::dp::recursive::word_break_problem("samsungandmangok", dictionary));
}


TEST(word_break_problem, dp1)
{
    std::vector<std::string> dictionary = {"I", "like", "it", "anyway", "any", "way", "don't"};
    EXPECT_TRUE(alg::dp::word_break_problem("Ilikeit", dictionary));
}

TEST(word_break_problem, dp2)
{
    std::vector<std::string> dictionary = {"I", "like", "it", "anyway", "any", "way", "don't"};
    EXPECT_TRUE(alg::dp::word_break_problem("Ilikeitanyway", dictionary));
}

TEST(word_break_problem, dp3)
{
    std::vector<std::string> dictionary = {"I", "like", "it", "anyway", "any", "way", "don't"};
    EXPECT_FALSE(alg::dp::word_break_problem("Ilikesit", dictionary));
}

TEST(word_break_problem, dp4)
{
    std::vector<std::string> dictionary = {"mobile","samsung","sam","sung",
                                           "man","mango","icecream","and",
                                           "go","i","like","ice","cream"}; ;
    EXPECT_TRUE(alg::dp::word_break_problem("ilikesamsung", dictionary));
    EXPECT_TRUE(alg::dp::word_break_problem("iiiiiiii", dictionary));
    EXPECT_TRUE(alg::dp::word_break_problem("", dictionary));
    EXPECT_TRUE(alg::dp::word_break_problem("ilikelikeimangoiii", dictionary));
    EXPECT_TRUE(alg::dp::word_break_problem("samsungandmango", dictionary));
    EXPECT_FALSE(alg::dp::word_break_problem("samsungandmangok", dictionary));
}

