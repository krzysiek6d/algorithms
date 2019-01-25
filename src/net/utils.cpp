//
// Created by pawluch on 1/25/19.
//

#include "utils.hpp"
#include <regex>

namespace alg
{
    namespace net
    {
        namespace utils
        {
            std::string removeLeadingZerosFromIp(const std::string& ip)
            {
                static const std::regex r("(^|[:.])(0+)([0]|[a-fA-F1-9][0-9]*)");
                return std::regex_replace(ip, r, "$1$3");
            }

            std::string convertToIpv4IfIpv4ToIpv6Mapping(const std::string& ip)
            {
                try {
                    static const std::regex r("[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}");
                    std::smatch match;
                    if (std::regex_search(ip, match, r))
                    {
                        if (match.size() != 1)
                        {
                            return ip;
                        }
                        else
                        {
                            return match[0];
                        }
                    }
                    return ip;
                }
                catch (const std::exception&)
                {
                    return ip;
                }
            }
        }
    }
}