//
// Created by pawluch on 1/24/19.
//

#ifndef ALGORITHMS_BFS_HPP
#define ALGORITHMS_BFS_HPP

#include <graph/Graph.hpp>
#include <functional>
#include <queue>
#include <map>

namespace alg
{
    namespace graph
    {
        void bfs(const Graph& graph, int src, std::function<void(int)> callback = nullptr);

        template <typename T>
        void bfs(T src, std::function<void(const std::vector<T>&)> callback = nullptr, std::function<std::vector<T>(const T&)> generator = nullptr)
        {
            std::map<T, bool> visited;
            std::map<T, T> parent;
            std::queue<T> queue;

            visited[src] = true;
            queue.push(src);
            parent[src] = src;

            while (!queue.empty())
            {
                auto current = queue.front();
                queue.pop();
                if (callback)
                {
                    std::vector<T> history;
                    auto currentCopy = current;
                    //history.push_back(src);
                    while (parent[currentCopy] != src)
                    {
                        history.push_back(currentCopy);
                        currentCopy = parent[currentCopy];
                    }
                    history.push_back(currentCopy);
                    history.push_back(src);
                    std::reverse(history.begin(), history.end());
                    callback(history);
                }
                if (generator)
                {
                    auto neighbors = generator(current);
                    for (auto neighbor: neighbors)
                    {
                        if (!visited[neighbor])
                        {
                            parent[neighbor] = current;
                            visited[neighbor] = true;
                            queue.push(neighbor);
                        }
                    }
                }
            }
        }
    }
}

#endif //ALGORITHMS_BFS_HPP
