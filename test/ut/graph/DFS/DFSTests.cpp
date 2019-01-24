//
// Created by pawluch on 1/24/19.
//

#include <gtest/gtest.h>
#include <graph/DFS/dfs.hpp>

using namespace ::testing;

TEST(DFSTest, shouldTraverseOnDirectedGraph)
{
    alg::graph::Graph graph{alg::graph::GraphType::Directed};
    auto v1 = graph.addVertex();
    auto v2 = graph.addVertex();
    graph.addEdge(v1, v2, 5);

    std::vector<int> traversedVertexes;
    auto handler = [&traversedVertexes](int v){traversedVertexes.push_back(v);};
    alg::graph::dfs(graph, v1, handler);

    std::vector<int> expectedTraversal{v1, v2};
    EXPECT_EQ(expectedTraversal, traversedVertexes);
}


TEST(DFSTest, shouldTraverseOnDirectedGraph_2)
{
    alg::graph::Graph g{alg::graph::GraphType::Directed};
    auto v0 = g.addVertex();
    auto v1 = g.addVertex();
    auto v2 = g.addVertex();
    auto v3 = g.addVertex();
    auto v4 = g.addVertex();
    auto v5 = g.addVertex();
    g.addEdge(v0, v1);
    g.addEdge(v0, v4);
    g.addEdge(v1, v4);
    g.addEdge(v1, v3);
    g.addEdge(v1, v2);
    g.addEdge(v3, v4);
    g.addEdge(v2, v3);
    g.addEdge(v3, v5);

    std::vector<int> traversedVertexes;
    auto handler = [&traversedVertexes](int v){traversedVertexes.push_back(v);};
    alg::graph::dfs(g, v1, handler);

    std::vector<int> expectedTraversal{v1, v2, v3, v4, v5};
    EXPECT_EQ(expectedTraversal, traversedVertexes);
}