//
// Created by pawluch on 1/30/19.
//
#include <gtest/gtest.h>
#include <DynamicProgramming/ways_to_create_sum.hpp>

using namespace ::testing;


TEST(num_of_ways_Recursive_Variations_WithRepetition, tc1)
{
    std::vector<int> values{1};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 1,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Variations,
                                                   alg::dp::RepetitionType::WithRepetition);
    EXPECT_EQ(1, num_of_ways);
}

TEST(num_of_ways_Recursive_Variations_WithRepetition, tc2)
{
    std::vector<int> values{1, 2};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 1,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Variations,
                                                   alg::dp::RepetitionType::WithRepetition);
    EXPECT_EQ(1, num_of_ways);
}
TEST(num_of_ways_Recursive_Variations_WithRepetition, tc3)
{
    std::vector<int> values{1, 2};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 2,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Variations,
                                                   alg::dp::RepetitionType::WithRepetition);
    EXPECT_EQ(2, num_of_ways);
}

TEST(num_of_ways_Recursive_Variations_WithRepetition, tc4)
{
    std::vector<int> values{1, 2, 3};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 3,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Variations,
                                                   alg::dp::RepetitionType::WithRepetition); /// [1,1,1], [1,2], [2.1], [3]
    EXPECT_EQ(4, num_of_ways);
}

TEST(num_of_ways_Recursive_Variations_WithRepetition, tc5)
{
    std::vector<int> values{1, 2, 3};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 4,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Variations,
                                                   alg::dp::RepetitionType::WithRepetition); /// [1,1,1,1], [1,1,2], [1,2,1], [2,1,1], [2,2], [3,1], [1,3]
    EXPECT_EQ(7, num_of_ways);
}

TEST(num_of_ways_Recursive_Variations_WithRepetition, dp_tc1)
{
    std::vector<int> values{1};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 1,
                                                   alg::dp::AlgorithmType::DynamicProgramming,
                                                   alg::dp::CombinatoricsType::Variations,
                                                   alg::dp::RepetitionType::WithRepetition);
    EXPECT_EQ(1, num_of_ways);
}

TEST(num_of_ways_Recursive_Variations_WithRepetition, dp_tc2)
{
    std::vector<int> values{1, 2};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 1,
                                                   alg::dp::AlgorithmType::DynamicProgramming,
                                                   alg::dp::CombinatoricsType::Variations,
                                                   alg::dp::RepetitionType::WithRepetition);
    EXPECT_EQ(1, num_of_ways);
}
TEST(num_of_ways_Recursive_Variations_WithRepetition, dp_tc3)
{
    std::vector<int> values{1, 2};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 2,
                                                   alg::dp::AlgorithmType::DynamicProgramming,
                                                   alg::dp::CombinatoricsType::Variations,
                                                   alg::dp::RepetitionType::WithRepetition);
    EXPECT_EQ(2, num_of_ways);
}

TEST(num_of_ways_Recursive_Variations_WithRepetition, dp_tc4)
{
    std::vector<int> values{1, 2, 3};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 3,
                                                   alg::dp::AlgorithmType::DynamicProgramming,
                                                   alg::dp::CombinatoricsType::Variations,
                                                   alg::dp::RepetitionType::WithRepetition); /// [1,1,1], [1,2], [2.1], [3]
    EXPECT_EQ(4, num_of_ways);
}

TEST(num_of_ways_Recursive_Variations_WithRepetition, dp_tc5)
{
    std::vector<int> values{1, 2, 3};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 4,
                                                   alg::dp::AlgorithmType::DynamicProgramming,
                                                   alg::dp::CombinatoricsType::Variations,
                                                   alg::dp::RepetitionType::WithRepetition); /// [1,1,1,1], [1,1,2], [1,2,1], [2,1,1], [2,2], [3,1], [1,3]
    EXPECT_EQ(7, num_of_ways);
}




//////////////////////////////
TEST(num_of_ways_Recursive_Variations_WithoutRepetition, tc1)
{
    std::vector<int> values{1};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 1,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Variations,
                                                   alg::dp::RepetitionType::WithoutRepetition);
    EXPECT_EQ(1, num_of_ways);
}

TEST(num_of_ways_Recursive_Variations_WithoutRepetition, tc2)
{
    std::vector<int> values{1, 2};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 1,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Variations,
                                                   alg::dp::RepetitionType::WithoutRepetition); /// [1]
    EXPECT_EQ(1, num_of_ways);
}
TEST(num_of_ways_Recursive_Variations_WithoutRepetition, tc3)
{
    std::vector<int> values{1, 2};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 2,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Variations,
                                                   alg::dp::RepetitionType::WithoutRepetition); /// [2]
    EXPECT_EQ(1, num_of_ways);
}

TEST(num_of_ways_Recursive_Variations_WithoutRepetition, tc4)
{
    std::vector<int> values{1, 2, 3};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 3,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Variations,
                                                   alg::dp::RepetitionType::WithoutRepetition); /// [2,1], [3], [1,2]
    EXPECT_EQ(3, num_of_ways);
}

TEST(num_of_ways_Recursive_Variations_WithoutRepetition, tc5)
{
    std::vector<int> values{1, 2, 3};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 4,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Variations,
                                                   alg::dp::RepetitionType::WithoutRepetition); /// [3,1], [1,3]
    EXPECT_EQ(2, num_of_ways);
}

//////////////////////////////////////////////////
TEST(num_of_ways_Recursive_Combinations_WithoutRepetition, tc1) {
    std::vector<int> values{1};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 1,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Combinations,
                                                   alg::dp::RepetitionType::WithoutRepetition);  // 1
    EXPECT_EQ(1, num_of_ways);
}

TEST(num_of_ways_Recursive_Combinations_WithoutRepetition, tc2)
{
    std::vector<int> values{1, 2};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 1,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Combinations,
                                                   alg::dp::RepetitionType::WithoutRepetition); /// [1]
    EXPECT_EQ(1, num_of_ways);
}
TEST(num_of_ways_Recursive_Combinations_WithoutRepetition, tc3)
{
    std::vector<int> values{1, 2};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 2,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Combinations,
                                                   alg::dp::RepetitionType::WithoutRepetition); /// [2]
    EXPECT_EQ(1, num_of_ways);
}

TEST(num_of_ways_Recursive_Combinations_WithoutRepetition, tc4)
{
    std::vector<int> values{1, 2, 3};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 3,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Combinations,
                                                   alg::dp::RepetitionType::WithoutRepetition); /// [3], [1,2]
    EXPECT_EQ(2, num_of_ways);
}

TEST(num_of_ways_Recursive_Combinations_WithoutRepetition, tc5)
{
    std::vector<int> values{1, 2, 3};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 4,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Combinations,
                                                   alg::dp::RepetitionType::WithoutRepetition); /// [1,3]
    EXPECT_EQ(1, num_of_ways);
}

////////////////////////////////////////////////////////////
TEST(num_of_ways_Recursive_Combinations_WithRepetition, tc1) {
    std::vector<int> values{1};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 1,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Combinations,
                                                   alg::dp::RepetitionType::WithRepetition);  // 1
    EXPECT_EQ(1, num_of_ways);
}

TEST(num_of_ways_Recursive_Combinations_WithRepetition, tc2)
{
    std::vector<int> values{1, 2};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 1,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Combinations,
                                                   alg::dp::RepetitionType::WithRepetition); /// [1]
    EXPECT_EQ(1, num_of_ways);
}
TEST(num_of_ways_Recursive_Combinations_WithRepetition, tc3)
{
    std::vector<int> values{1, 2};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 2,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Combinations,
                                                   alg::dp::RepetitionType::WithRepetition); /// [2], [1,1]
    EXPECT_EQ(2, num_of_ways);
}

TEST(num_of_ways_Recursive_Combinations_WithRepetition, tc4)
{
    std::vector<int> values{1, 2, 3};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 3,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Combinations,
                                                   alg::dp::RepetitionType::WithRepetition); /// [3], [1,2], [1,1,1]
    EXPECT_EQ(3, num_of_ways);
}

TEST(num_of_ways_Recursive_Combinations_WithRepetition, tc5)
{
    std::vector<int> values{1, 2, 3};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 4,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Combinations,
                                                   alg::dp::RepetitionType::WithRepetition); /// [1,3], [1,1,1,1], [2,2]
    EXPECT_EQ(3, num_of_ways);
}

TEST(num_of_ways_Recursive_Combinations_WithRepetition, tc6)
{
    std::vector<int> values{1, 2, 3};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 5,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Combinations,
                                                   alg::dp::RepetitionType::WithRepetition); /// [1,1,1,1,1], [1,1,1,2], [1,1,3], [2,3]
    EXPECT_EQ(4, num_of_ways);
}

TEST(num_of_ways_Recursive_Combinations_WithRepetition, tc7)
{
    std::vector<int> values{1, 2, 3, 4};
    auto num_of_ways = alg::dp::ways_to_create_sum(values, 5,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Combinations,
                                                   alg::dp::RepetitionType::WithRepetition); /// [1,1,1,1,1], [1,1,1,2], [1,1,3], [1,4], [2,3]
    EXPECT_EQ(5, num_of_ways);
}