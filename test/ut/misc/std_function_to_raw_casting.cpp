//
// Created by pawluch on 2/18/19.
//
#include <gtest/gtest.h>
#include <iostream>
#include <functional>

using fun_type = int(*)(int);

int callme(int val, fun_type fun)
{
    return fun(val);
}

int c_function(int a)
{
    return a;
}

TEST(callbacks, raw_function)
{
    EXPECT_EQ(1, callme(1, c_function));
}

TEST(callbacks, std_function_needs_casting)
{
    std::function<void(int)> cpp_func = nullptr;

    EXPECT_EQ(nullptr, cpp_func.target<fun_type>());
    cpp_func = c_function;
    EXPECT_NE(nullptr, cpp_func.target<fun_type>());
    EXPECT_EQ(2, callme(2, *cpp_func.target<fun_type>()));
}

TEST(callbacks, lambda_does_not_need_casting)
{
    auto lambda_func = [](int x){return x;};
    EXPECT_EQ(3, callme(3, lambda_func));
}