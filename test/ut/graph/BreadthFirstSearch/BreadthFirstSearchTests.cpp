//
// Created by pawluch on 1/24/19.
//

#include <gtest/gtest.h>
#include <graph/BreadthFirstSearch/bfs.hpp>

using namespace ::testing;

TEST(BFSTest, shouldCalculateSPF)
{
    alg::graph::Graph graph{alg::graph::GraphType::Directed};
    auto v1 = graph.addVertex();
    auto v2 = graph.addVertex();
    graph.addEdge(v1, v2, 5);

    auto result = alg::graph::bfs(graph, v1);
    std::vector<std::pair<int, int>> expectedSPF = {std::make_pair(v2, 5)};

    EXPECT_EQ(expectedSPF, result);
}