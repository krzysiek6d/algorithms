//
// Created by pawluch on 1/24/19.
//

#ifndef ALGORITHMS_BFS_HPP
#define ALGORITHMS_BFS_HPP

#include <graph/Graph.hpp>
#include <functional>

namespace alg
{
    namespace graph
    {
        void bfs(const Graph& graph, int src, std::function<void(int)> callback = nullptr);
    }
}

#endif //ALGORITHMS_BFS_HPP
