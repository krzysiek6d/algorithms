//
// Created by pawluch on 1/29/19.
//
#include <DynamicProgramming/longest_common_subsequence.hpp>
#include <gtest/gtest.h>

using namespace ::testing;

TEST(LCS, no1)
{
    const std::string str1 = "ABACD";
    const std::string str2 = "BATD";
    EXPECT_EQ("BAD", alg::dp::longest_common_subsequence(str1, str2));
}

TEST(LCS, no2)
{
    const std::string str1 = "AxBfCgDhAjBiClDuArBsCfDc";
    const std::string str2 = "ABCDE";
    EXPECT_EQ("ABCD", alg::dp::longest_common_subsequence(str1, str2));
}
