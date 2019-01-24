//
// Created by pawluch on 1/24/19.
//

#ifndef ALGORITHMS_UTILS_HPP
#define ALGORITHMS_UTILS_HPP

#include <vector>
#include <boost/optional.hpp>
namespace alg
{
    namespace graph {
        namespace utils {
            boost::optional<int>
            getCost(int v1, int v2, const std::vector<std::vector<boost::optional<int>>> &adj_matrix);

            std::vector<int> getNeighbors(int v, const std::vector<std::vector<boost::optional<int>>> &adj_matrix);

            std::vector<int>
            getIngressNeighbors(int v, const std::vector<std::vector<boost::optional<int>>> &adj_matrix);

            std::vector<int>
            getEgressNeighbors(int v, const std::vector<std::vector<boost::optional<int>>> &adj_matrix);
        }
    }
}
#endif //ALGORITHMS_UTILS_HPP
