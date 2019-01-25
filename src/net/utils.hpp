//
// Created by pawluch on 1/25/19.
//

#ifndef ALGORITHMS_UTILS_HPP
#define ALGORITHMS_UTILS_HPP

#include <string>
namespace alg
{
    namespace net
    {
        namespace utils
        {
            std::string removeLeadingZerosFromIp(const std::string& ip);
            std::string convertToIpv4IfIpv4ToIpv6Mapping(const std::string& ip);
        }
    }
}


#endif //ALGORITHMS_UTILS_HPP
