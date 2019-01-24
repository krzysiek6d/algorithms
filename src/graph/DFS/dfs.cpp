//
// Created by pawluch on 1/24/19.
//

#include "dfs.hpp"
#include <algorithm>
#include <iostream>

namespace alg
{
    namespace graph
    {
        namespace detail
        {
            void dfs(const Graph& graph, int node, std::function<void(int)> callback, std::vector<bool>& visited)
            {
                if (visited[node])
                    return;

                visited[node] = true;
                callback(node);
                auto neighbors = graph.getEgressNeighbors(node);
                // sorting can be removed
                std::sort(neighbors.begin(), neighbors.end());
                for (auto&& n : neighbors)
                    dfs(graph, n, callback, visited);
            }
        }

        void dfs(const Graph& graph, int src, std::function<void(int)> callback)
        {
            auto visited = std::vector<bool>(graph.getNumOfVertexes(), false);
            detail::dfs(graph, src, callback, visited);
        }
    }
}