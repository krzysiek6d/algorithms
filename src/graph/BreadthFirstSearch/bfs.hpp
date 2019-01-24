//
// Created by pawluch on 1/24/19.
//

#ifndef ALGORITHMS_BFS_HPP
#define ALGORITHMS_BFS_HPP

#include <graph/Graph.hpp>

namespace alg
{
    namespace graph
    {
        std::vector<std::pair<int, int>> bfs(const Graph& graph, int src);
    }
}

#endif //ALGORITHMS_BFS_HPP
