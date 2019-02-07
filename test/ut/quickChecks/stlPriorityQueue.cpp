//
// Created by pawluch on 2/7/19.
//

#include <gtest/gtest.h>
#include <queue>

using namespace ::testing;

namespace {
    struct A {
        A(int weight, int descriptor) : weight{weight}, desciptor{descriptor} {}

        int weight;
        int desciptor;

    };

    bool operator<(const A &a, const A &b) {
        return a.weight < b.weight;
    }

    bool operator==(const A &a, const A &b) {
        return a.weight == b.weight && a.desciptor == b.desciptor;
    }
}


TEST(priority_queue, tc1)
{
    std::priority_queue<A> queue{};
    queue.push(A{2,7});
    queue.push(A{3,8});
    queue.push(A{3,6});
    queue.push(A{1,9});
    queue.push(A{3,5});
    queue.push(A{2,7});
    auto getItem = [&queue](){auto x = queue.top(); queue.pop(); return x;};
    EXPECT_EQ(getItem(), A(3,8));
    EXPECT_EQ(getItem(), A(3,6));
    EXPECT_EQ(getItem(), A(3,5));
    EXPECT_EQ(getItem(), A(2,7));
    EXPECT_EQ(getItem(), A(2,7));
    EXPECT_EQ(getItem(), A(1,9));
}