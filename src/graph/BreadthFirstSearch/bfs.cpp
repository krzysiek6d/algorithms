//
// Created by pawluch on 1/24/19.
//

#include <queue>
#include <iostream>
#include "bfs.hpp"

namespace alg
{
    namespace graph
    {
        void bfs(const Graph& graph, int src, std::function<void(int)> callback)
        {
            std::vector<bool> visited(graph.getNumOfVertexes(), false);
            std::queue<int > queue;

            visited[src] = true;
            queue.push(src);

            while (!queue.empty())
            {
                auto current = queue.front();
                queue.pop();
                if (callback)
                {
                    callback(current);
                }
                for (auto neighbor: graph.getNeighbors(current))
                {
                    if (!visited[neighbor])
                    {
                        visited[neighbor] = true;
                        queue.push(neighbor);
                    }
                }
            }
        }

    }
}