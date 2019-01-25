//
// Created by pawluch on 1/25/19.
//

#include <string>
#include <gtest/gtest.h>
#include <net/utils.hpp>

TEST(IpWithLeadingZeros, shouldBeChangedToNonLeadingZeros1)
{
    std::string ip = "00ff:123:0:00::f00:0020.000.0101010.23.000.2000:00600000234";
    std::string converted = alg::net::utils::removeLeadingZerosFromIp(ip);
    EXPECT_EQ("ff:123:0:0::f00:20.0.101010.23.0.2000:600000234", converted);
}

TEST(IpWithLeadingZeros, shouldBeChangedToNonLeadingZeros2)
{
    std::string ip = "0.0.0.0";
    std::string converted = alg::net::utils::removeLeadingZerosFromIp(ip);
    EXPECT_EQ("0.0.0.0", converted);
}

TEST(IpWithLeadingZeros, shouldBeChangedToNonLeadingZeros3)
{
    std::string ip = "01.020.100.04";
    std::string converted = alg::net::utils::removeLeadingZerosFromIp(ip);
    EXPECT_EQ("1.20.100.4", converted);
}

TEST(IpWithLeadingZeros, shouldBeChangedToNonLeadingZeros4)
{
    std::string ip = "";
    std::string converted = alg::net::utils::removeLeadingZerosFromIp(ip);
    EXPECT_EQ("", converted);
}

TEST(convertToIpv4IfIpv4ToIpv6Mapping, shouldReturnIpv4)
{
    std::string converted
            = alg::net::utils::convertToIpv4IfIpv4ToIpv6Mapping("[ffff:192.168.255.126]");
    EXPECT_EQ("192.168.255.126", converted);
}

TEST(convertToIpv4IfIpv4ToIpv6Mapping, shouldReturnIpv6BecauseThereIsNoValidIpv4)
{
    std::string converted
            = alg::net::utils::convertToIpv4IfIpv4ToIpv6Mapping("[ffff:bef:168.255.126]");
    EXPECT_EQ("[ffff:bef:168.255.126]", converted);
}

TEST(convertToIpv4IfIpv4ToIpv6Mapping, shouldRemoveBrackets)
{
    std::string converted = alg::net::utils::convertToIpv4IfIpv4ToIpv6Mapping("[192.1.4.23]");
    EXPECT_EQ("192.1.4.23", converted);
}

TEST(convertToIpv4IfIpv4ToIpv6Mapping, shouldWorkIfNoBrackets)
{
    std::string converted = alg::net::utils::convertToIpv4IfIpv4ToIpv6Mapping("192.1.4.23");
    EXPECT_EQ("192.1.4.23", converted);
}

TEST(convertToIpv4IfIpv4ToIpv6Mapping, shouldWorkIfIpIsANY)
{
    std::string converted = alg::net::utils::convertToIpv4IfIpv4ToIpv6Mapping("0.0.0.0");
    EXPECT_EQ("0.0.0.0", converted);
}

TEST(convertToIpv4IfIpv4ToIpv6Mapping, shouldWorkIfIpv6IsANY)
{
    std::string converted = alg::net::utils::convertToIpv4IfIpv4ToIpv6Mapping("::");
    EXPECT_EQ("::", converted);
}

TEST(convertToIpv4IfIpv4ToIpv6Mapping, shouldWorkIfIpv6IsANYIpv6)
{
    std::string converted
            = alg::net::utils::convertToIpv4IfIpv4ToIpv6Mapping("0:0:0:0::0");
    EXPECT_EQ("0:0:0:0::0", converted);
}

TEST(convertToIpv4IfIpv4ToIpv6Mapping, shouldWorkIfEmpty)
{
    std::string converted = alg::net::utils::convertToIpv4IfIpv4ToIpv6Mapping("");
    EXPECT_EQ("", converted);
}

TEST(convertToIpv4IfIpv4ToIpv6Mapping, shouldReturnProperlyIfNumbersAreBefore)
{
    std::string converted
            = alg::net::utils::convertToIpv4IfIpv4ToIpv6Mapping("fff::1234:01.01.32.23");
    EXPECT_EQ("01.01.32.23", converted);
}