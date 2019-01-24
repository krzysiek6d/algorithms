//
// Created by pawluch on 1/24/19.
//

#include "dijkstra.hpp"
#include <queue>
namespace alg
{
    namespace graph
    {
        std::vector<int> dijkstra(const Graph& g, int src)
        {
            auto vertexes = g.getVertexes();
            std::vector<int> distances;
            std::vector<int> prev;
            std::queue<int> queue;
            for (unsigned int i = 0; i < vertexes.size(); i++)
            {
                distances.push_back(std::numeric_limits<int>::max());
                prev.push_back(-1);
            }
            distances[src] = 0;
            queue.push(src);
            while(not queue.empty())
            {
                auto u = queue.front();
                queue.pop();
                for(auto&& neighbor : g.getEgressNeighbors(u)) // todo - optimize with sorting by lowest cost
                {
                    auto alt = distances[u] + g.getCost(u, neighbor).get();
                    if (alt < distances[neighbor])
                    {
                        distances[neighbor] = alt;
                        prev[neighbor] = u;
                        queue.push(neighbor);
                    }
                }
            }
            return prev;
        }
    }
}
