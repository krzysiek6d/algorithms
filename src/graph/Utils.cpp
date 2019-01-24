//
// Created by pawluch on 1/24/19.
//

#include "Utils.hpp"

namespace alg
{
    namespace graph {
        namespace utils {
            boost::optional<int>
            getCost(int v1, int v2, const std::vector<std::vector<boost::optional<int>>> &adj_matrix) {
                return adj_matrix[v1][v2];
            }

            // fixme - unique is probably bad - there can be 2 edges between vertexes
            std::vector<int> getNeighbors(int v, const std::vector<std::vector<boost::optional<int>>> &adj_matrix) { // O(V) + O(V) + O(VlogV) -> O(VlogV)
                auto in = getIngressNeighbors(v, adj_matrix);
                auto out = getEgressNeighbors(v, adj_matrix);
                in.insert(in.end(), out.begin(), out.end());
                std::sort(in.begin(), in.end());
                auto last = std::unique(in.begin(), in.end());
                in.erase(last, in.end());
                return in;
            }

            std::vector<int>
            getIngressNeighbors(int v, const std::vector<std::vector<boost::optional<int>>> &adj_matrix) {  // O(V)
                std::vector<int> result;
                for (u_int32_t possibleIngressNeighborId = 0;
                     possibleIngressNeighborId < adj_matrix.size(); possibleIngressNeighborId++) {
                    if (adj_matrix[possibleIngressNeighborId][v] != boost::none)
                        result.push_back(possibleIngressNeighborId);
                }
                return result;
            }

            std::vector<int>
            getEgressNeighbors(int v, const std::vector<std::vector<boost::optional<int>>> &adj_matrix) {  // O(V)
                std::vector<int> result;
                for (u_int32_t possibleEgressNeighborId = 0;
                     possibleEgressNeighborId < adj_matrix[v].size(); possibleEgressNeighborId++) {
                    if (adj_matrix[v][possibleEgressNeighborId] != boost::none)
                        result.push_back(possibleEgressNeighborId);
                }
                return result;
            }
        }
    }
}