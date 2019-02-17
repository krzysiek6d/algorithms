//
// Created by pawluch on 1/30/19.
//
#include <gtest/gtest.h>
#include <DynamicProgramming/ways_to_create_sum.hpp>

using namespace ::testing;

using test_data = std::tuple<int, std::vector<int>, int>; // sum, values, result
struct Variations_WithRepetition : public ::testing::TestWithParam<test_data> {};
struct Variations_WithoutRepetition : public ::testing::TestWithParam<test_data> {};
struct Combinations_WithRepetition : public ::testing::TestWithParam<test_data> {};
struct Combinations_WithoutRepetition : public ::testing::TestWithParam<test_data> {};
std::vector<test_data> variations_with_repetition = {
        {1, {1}, 1},
        {1, {1, 2}, 1},
        {2, {1, 2}, 2},    /// {1,1}, {2}
        {3, {1, 2, 3}, 4}, /// [1,1,1], [1,2], [2.1], [3]
        {4, {1, 2, 3,}, 7}, /// [1,1,1,1], [1,1,2], [1,2,1], [2,1,1], [2,2], [3,1], [1,3]
        {4, {2, 3, 4, 5}, 2}, ///  [2,2], [4]
        {5, {1, 2}, 8},
        {8, {5, 12}, 0}
};
std::vector<test_data> variations_without_repetition = {
        {1, {1}, 1},
        {1, {1, 2}, 1},
        {2, {1, 2}, 1},    /// {2}
        {3, {1, 2, 3}, 3}, /// [2,1], [1,2], [3]
        {4, {1, 2, 3,}, 2}, /// [3,1], [1,3]
};

std::vector<test_data> combinations_with_repetition = {
        {1, {1}, 1},
        {1, {1, 2}, 1},
        {2, {1, 2}, 2}, /// [2], [1,1]
        {3, {1, 2, 3}, 3}, /// [3], [1,2], [1,1,1]
        {4, {1, 2, 3}, 3}, /// [1,3], [1,1,1,1], [2,2]
        {5, {1, 2, 3}, 4}, /// [1,1,1,1,1], [1,1,1,2], [1,1,3], [2,3]
        {5, {1, 2, 3, 4}, 5}, /// [1,1,1,1,1], [1,1,1,2], [1,1,3], [1,4], [2,3]

};
std::vector<test_data> combinations_without_repetition = {
        {1, {1}, 1},
        {1, {1, 2}, 1},
        {2, {1, 2}, 1},
        {3, {1, 2, 3}, 2}, /// [3], [1,2]
        {4, {1, 2, 3}, 1}, /// [1,3]
};

INSTANTIATE_TEST_CASE_P(Recursive_Variations_WithRepetition_Tests,
                        Variations_WithRepetition,
                        ::testing::ValuesIn(variations_with_repetition));
INSTANTIATE_TEST_CASE_P(Variations_WithoutRepetition_Tests,
                        Variations_WithoutRepetition,
                        ::testing::ValuesIn(variations_without_repetition));

INSTANTIATE_TEST_CASE_P(Recursive_Combinations_WithRepetition_Tests,
                        Combinations_WithRepetition,
                        ::testing::ValuesIn(combinations_with_repetition));


INSTANTIATE_TEST_CASE_P(Recursive_Combinations_WithoutRepetition_Tests,
                        Combinations_WithoutRepetition,
                        ::testing::ValuesIn(combinations_without_repetition));

TEST_P(Variations_WithRepetition, recursive)
{
    auto args = GetParam();
    auto sum = std::get<0>(args);
    auto values = std::get<1>(args);
    auto expected_num_of_ways = std::get<2>(args);
    auto num_of_ways = alg::dp::ways_to_create_sum(values, sum,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Variations,
                                                   alg::dp::RepetitionType::WithRepetition);
    EXPECT_EQ(expected_num_of_ways, num_of_ways);
}

TEST_P(Variations_WithRepetition, dp)
{
    auto args = GetParam();
    auto sum = std::get<0>(args);
    auto values = std::get<1>(args);
    auto expected_num_of_ways = std::get<2>(args);
    auto num_of_ways = alg::dp::ways_to_create_sum(values, sum,
                                                   alg::dp::AlgorithmType::DynamicProgramming,
                                                   alg::dp::CombinatoricsType::Variations,
                                                   alg::dp::RepetitionType::WithRepetition);
    EXPECT_EQ(expected_num_of_ways, num_of_ways);
}

TEST_P(Variations_WithoutRepetition, recursive)
{
    auto args = GetParam();
    auto sum = std::get<0>(args);
    auto values = std::get<1>(args);
    auto expected_num_of_ways = std::get<2>(args);
    auto num_of_ways = alg::dp::ways_to_create_sum(values, sum,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Variations,
                                                   alg::dp::RepetitionType::WithoutRepetition);
    EXPECT_EQ(expected_num_of_ways, num_of_ways);
}

TEST_P(Combinations_WithoutRepetition, recursive)
{
    auto args = GetParam();
    auto sum = std::get<0>(args);
    auto values = std::get<1>(args);
    auto expected_num_of_ways = std::get<2>(args);
    auto num_of_ways = alg::dp::ways_to_create_sum(values, sum,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Combinations,
                                                   alg::dp::RepetitionType::WithoutRepetition);
    EXPECT_EQ(expected_num_of_ways, num_of_ways);
}

TEST_P(Combinations_WithRepetition, recursive)
{
    auto args = GetParam();
    auto sum = std::get<0>(args);
    auto values = std::get<1>(args);
    auto expected_num_of_ways = std::get<2>(args);
    auto num_of_ways = alg::dp::ways_to_create_sum(values, sum,
                                                   alg::dp::AlgorithmType::Recursive,
                                                   alg::dp::CombinatoricsType::Combinations,
                                                   alg::dp::RepetitionType::WithRepetition);
    EXPECT_EQ(expected_num_of_ways, num_of_ways);
}
