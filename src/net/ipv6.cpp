//
// Created by pawluch on 1/25/19.
//

#include "ipv6.hpp"


namespace alg
{
    namespace net
    {
        namespace ipv6
        {
            boost::optional<std::array<uint8_t, 16>> from_string(const std::string& ip)
            {
                return std::array<uint8_t, 16>{};
            };
        }
    }
}