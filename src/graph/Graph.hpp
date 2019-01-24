//
// Created by pawluch on 1/24/19.
//

#ifndef GRAPH_GRAPH_HPP
#define GRAPH_GRAPH_HPP

#include <vector>
#include <list>
#include "Edge.hpp"
#include "Types.h"
#include <boost/optional.hpp>

namespace alg
{
    namespace graph {
        class Graph {
        public:
            Graph(GraphType type); // inheritance here ;)
            int getNumOfVertexes() const;

            int addVertex();

            void addEdge(int src, int dst, int cost = 1);

            std::vector<std::vector<boost::optional<int>>> getAdjacencyMatrix();
            std::vector<std::list<std::pair<int, int>>> getAdjacencyList();
            boost::optional<int> getCost(int v1, int v2) const;
            std::vector<int> getNeighbors(int v) const;
            std::vector<int> getIngressNeighbors(int v);
            std::vector<int> getEgressNeighbors(int v) const;

            std::vector<Edge> getEgressEdges(int v) const;
            std::vector<int> getVertexes() const;

        private:
            GraphType type;
            std::vector<int> vertexes;
            std::vector<Edge> edges;
        };
    }
}

#endif //GRAPH_GRAPH_HPP
