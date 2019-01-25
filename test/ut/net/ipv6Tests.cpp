//
// Created by pawluch on 1/25/19.
//

#include <gtest/gtest.h>
#include <net/ipv6.hpp>
using namespace ::testing;

TEST(NetTest, ipv6tobytes)
{
    std::array<uint8_t ,16> expected{};

    expected = {
            0x00, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x01
    };
    EXPECT_EQ(expected, alg::net::ipv6::from_string("::1"));
}