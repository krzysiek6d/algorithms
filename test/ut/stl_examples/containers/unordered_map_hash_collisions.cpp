//
// Created by pawluch on 3/6/19.
//

#include <gtest/gtest.h>
#include <unordered_map>

using namespace ::testing;

int numOfEqualOperatorCalls = 0;

struct A
{
    explicit A(int x) : number(x) {}
    int number;
    bool operator==(const A& other) const
    {
        numOfEqualOperatorCalls++;
        return this->number == other.number;
    }
};

struct BadHash
{
    std::size_t operator()(A const& a) const noexcept
    {
        return 1;
    }
};

struct BetterHash
{
    std::size_t operator()(A const& a) const noexcept
    {
        return std::hash<long long>()(((long long) a.number) ^ (((long long) a.number) << 32));
    }
};

// hash by template specialization
namespace std {
    template<>
    struct hash<A> {
        size_t operator()(const A &x) const noexcept {
            return hash<long long>()(((long long) x.number) ^ (((long long) x.number) << 32));
        }
    };
}

TEST(unordered_map, collisions)
{
    numOfEqualOperatorCalls = 0; // clear global counter
    std::unordered_map<A, int, BadHash> map;
    map[A(1)] = 0;
    map[A(2)] = 0;
    map[A(3)] = 1;
    map[A(4)] = 0;
    map[A(5)] = 0;

    EXPECT_NE(numOfEqualOperatorCalls, 0); // collisions (EXPECT_NE - not equal)
    numOfEqualOperatorCalls = 0; // clear global counter

    auto x = map[A(5)];

    EXPECT_EQ(0, x);
    EXPECT_EQ(1, numOfEqualOperatorCalls);
    EXPECT_EQ(5u, map.size());
    EXPECT_EQ(0, map[A(0)]);
    EXPECT_EQ(1, map[A(3)]);
}

TEST(unordered_map, no_collisions)
{
    numOfEqualOperatorCalls = 0; // clear global counter
    std::unordered_map<A, int, BetterHash> map;
    map[A(1)] = 0;
    map[A(2)] = 0;
    map[A(3)] = 1;
    map[A(4)] = 0;
    map[A(5)] = 0;

    EXPECT_EQ(0, numOfEqualOperatorCalls);
    numOfEqualOperatorCalls = 0; // clear global counter

    auto x = map[A(5)];

    EXPECT_EQ(0, x);
    EXPECT_EQ(1, numOfEqualOperatorCalls);
    EXPECT_EQ(5u, map.size());
    EXPECT_EQ(0, map[A(0)]);
    EXPECT_EQ(1, map[A(3)]);
}

TEST(unordered_map, hash_in_std_compilation_test)
{
    std::unordered_map<A, int> map;
    map[A(1)] = 0;
    map[A(2)] = 0;
    EXPECT_EQ(2u, map.size());
}


TEST(unordered_map, duplicate)
{
    std::unordered_map<A, int> map;
    map[A(1)] = 0;
    map[A(1)] = 0;
    EXPECT_EQ(1u, map.size());
}