//
// Created by pawluch on 1/24/19.
//
#include <algorithm>
#include "Graph.hpp"
#include <boost/optional.hpp>
namespace alg
{
    namespace graph {
        Graph::Graph(GraphType type) : type{type} {
        }

        int Graph::addVertex() {
            auto id = vertexes.size();
            vertexes.push_back(id);
            return id;
        }

        int Graph::getNumOfVertexes() const
        {
            return vertexes.size();
        }

        void Graph::addEdge(int src, int dst, int cost) {
            // throw if no src/dst ?
            edges.push_back(Edge(src, dst, cost));
        }

        std::vector<std::vector<boost::optional<int>>> Graph::getAdjacencyMatrix() {
            std::vector<std::vector<boost::optional<int>>> adjacencyMatrix;
            for (auto &&v1 : vertexes) {
                std::vector<boost::optional<int>> adjacencyRow{};
                for (auto &&v2 : vertexes) {
                    boost::optional<int> cost = boost::none;
                    std::for_each(edges.begin(), edges.end(), [&v1, &v2, &cost, this](const Edge &e) {
                        if ((type == GraphType::Directed && e.src == v1 && e.dst == v2)
                            ||
                            (type == GraphType::Undirected &&
                             ((e.src == v1 && e.dst == v2) || (e.dst == v1 && e.src == v2))
                            )) {
                            cost = e.cost;
                        }
                    });
                    adjacencyRow.push_back(cost);
                }
                adjacencyMatrix.emplace_back(adjacencyRow);
            }
            return adjacencyMatrix;
        }

        std::vector<std::list<std::pair<int, int>>> Graph::getAdjacencyList()
        {
            std::vector<std::list<std::pair<int, int>>> adjacencyLists(vertexes.size(), std::list<std::pair<int, int>>{});
            for(auto&& e : edges)
            {
                adjacencyLists[e.src].push_back(std::make_pair(e.dst, e.cost));
                if (type == GraphType::Undirected)
                    adjacencyLists[e.dst].push_back(std::make_pair(e.src, e.cost));
            }
            return adjacencyLists;
        }

        boost::optional<int> Graph::getCost(int v1, int v2) const
        {
            for (auto&& e: edges) {
                if (e.src == v1 && e.dst==v2)
                    return e.cost;
                if (type == GraphType::Undirected && e.dst == v1 && e.src==v2)
                    return e.cost;
            }
            return boost::none;
        }
        std::vector<int> Graph::getNeighbors(int v) const // O(E)
        {
            std::vector<int> neighbors;
            for (auto&& e: edges) {
                if (e.src == v)
                    neighbors.push_back(e.dst);
                if (e.dst == v)
                    neighbors.push_back(e.src);
            }
            return neighbors;
        }
        std::vector<int> Graph::getIngressNeighbors(int v) // O(E)
        {
            std::vector<int> neighbors;
            for (auto&& e: edges) {
                if (e.dst == v)
                    neighbors.push_back(e.src);
                if (type == GraphType::Undirected && e.src == v)
                    neighbors.push_back(e.dst);
            }
            return neighbors;
        }
        std::vector<int> Graph::getEgressNeighbors(int v) const // O(E)
        {
            std::vector<int> neighbors;
            for (auto&& e: edges) {
                if (e.src == v)
                    neighbors.push_back(e.dst);
                if (type == GraphType::Undirected && e.dst == v)
                    neighbors.push_back(e.src);
            }
            return neighbors;
        }

        std::vector<Edge> Graph::getEgressEdges(int v) const
        {
            std::vector<Edge> egressEdges;
            for (auto&& e: edges) {
                if (e.src == v)
                    egressEdges.push_back(e);
                if (type == GraphType::Undirected && e.dst == v)
                    egressEdges.push_back(Edge(e.dst, e.src, e.cost));
            }
            return egressEdges;
        }

        std::vector<int> Graph::getVertexes() const
        {
            return vertexes;
        }
    }
}