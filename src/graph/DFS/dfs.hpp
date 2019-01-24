//
// Created by pawluch on 1/24/19.
//

#ifndef ALGORITHMS_DFS_HPP
#define ALGORITHMS_DFS_HPP

#include <functional>
#include <graph/Graph.hpp>

namespace alg
{
    namespace graph
    {
        void dfs(const Graph& graph, int src, std::function<void(int)> callback);
    }
}

#endif //ALGORITHMS_DFS_HPP
