//
// Created by pawluch on 1/24/19.
//

#ifndef ALGORITHMS_DIJKSTRA_HPP
#define ALGORITHMS_DIJKSTRA_HPP

#include <graph/Graph.hpp>

namespace alg
{
    namespace graph
    {
        std::vector<int> dijkstra(const Graph& g, int src);
        std::vector<int> dijkstra_recursive(const Graph& g, int src);
    }
}

#endif //ALGORITHMS_DIJKSTRA_HPP
