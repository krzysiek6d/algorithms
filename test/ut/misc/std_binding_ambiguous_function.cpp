//
// Created by pawluch on 2/18/19.
//

#include <gtest/gtest.h>
#include <functional>
static int foo(int)
{
    return 1;
}

static int foo(std::string)
{
    return 2;
}

TEST(binding, ambiguous)
{
    auto f1 = std::bind(static_cast<int(*)(int)>(foo), std::placeholders::_1);
    auto f2 = std::bind(static_cast<int(*)(std::string)>(foo), std::placeholders::_1);
    EXPECT_EQ(1, f1(0xDEAD));
    EXPECT_EQ(2, f2("DEAD"));
}

struct Bar{
    int foo(int){ return 1;}
    int foo(std::string){ return 2;}
};

TEST(binding, ambigous_member)
{
    Bar b{};
    auto f1 = std::bind(static_cast<int (Bar::*)(int)>(&Bar::foo), &b, std::placeholders::_1);
    auto f2 = std::bind(static_cast<int (Bar::*)(std::string)>(&Bar::foo), &b, std::placeholders::_1);
    EXPECT_EQ(1, f1(0xDEAD));
    EXPECT_EQ(2, f2("DEAD"));
}