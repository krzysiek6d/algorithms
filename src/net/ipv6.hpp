//
// Created by pawluch on 1/25/19.
//

#ifndef ALGORITHMS_IPV6_HPP
#define ALGORITHMS_IPV6_HPP

#include <boost/optional.hpp>

namespace alg
{
    namespace net
    {
        namespace ipv6
        {
            boost::optional<std::array<uint8_t, 16>> from_string(const std::string& ip);
        }
    }
}



#endif //ALGORITHMS_IPV6_HPP
