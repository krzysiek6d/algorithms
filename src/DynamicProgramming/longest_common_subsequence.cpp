//
// Created by pawluch on 1/29/19.
//

#include <iostream>
#include <vector>
#include "longest_common_subsequence.hpp"


namespace alg
{
    namespace dp
    {
        namespace detail
        {
            std::vector<std::vector<int>> lcs(const std::string& p, const std::string& q)
            {
                std::vector<std::vector<int>> p_q_table;
                for (unsigned i = 0u; i < p.length() + 1; i++)
                {
                    p_q_table.emplace_back(std::vector<int>(q.length()+1, 0));
                }
                for (auto pos_p = 0u; pos_p < p.length()+1; ++pos_p) {
                    for (auto pos_q = 0u; pos_q < q.length()+1; ++pos_q) {
                        if (pos_p == 0 || pos_q == 0) {
                            p_q_table[pos_p][pos_q] = 0;
                        } else if (p[pos_p - 1] == q[pos_q - 1]) {
                            p_q_table[pos_p][pos_q] = p_q_table[pos_p - 1][pos_q - 1] + 1;
                        } else {
                            p_q_table[pos_p][pos_q] = std::max(
                                    p_q_table[pos_p][pos_q - 1],
                                    p_q_table[pos_p - 1][pos_q]
                            );
                        }
                    }
                }
                return p_q_table;
            }

            std::string dp_table_to_string(const std::string& p, const std::string& q, const std::vector<std::vector<int>>& memo)
            {
                auto lcsLen = memo[p.length()][q.length()];
                auto lcs = std::string(lcsLen, ' ');
                auto i = p.length();
                auto j = q.length();

                while (i>0 && j>0)
                {
                    if (p[i-1]==q[j-1])
                    {
                        lcs[lcsLen-1] = p[i-1];
                        i--;
                        j--;
                        lcsLen--;
                    }
                    else if (memo[i-1][j] > memo[i][j-1])
                    {
                        i--;
                    }
                    else
                    {
                        j--;
                    }
                }
                return lcs;
            }
        }
        std::string longest_common_subsequence(const std::string& p, const std::string& q)
        {
            auto dp_table = detail::lcs(p, q);
            return detail::dp_table_to_string(p, q, dp_table);
        }
    }
}
