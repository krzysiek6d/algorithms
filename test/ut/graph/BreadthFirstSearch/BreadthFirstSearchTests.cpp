//
// Created by pawluch on 1/24/19.
//

#include <gtest/gtest.h>
#include <graph/BreadthFirstSearch/bfs.hpp>

using namespace ::testing;

TEST(BFSTest, x)
{
    std::vector<int> callsArguments;
    auto callback = [&callsArguments](int arg){
        callsArguments.push_back(arg);
    };
    alg::graph::Graph graph{alg::graph::GraphType::Directed};
    auto v1 = graph.addVertex();
    auto v2 = graph.addVertex();
    auto v3 = graph.addVertex();
    auto v4 = graph.addVertex();
    graph.addEdge(v1, v2, 5);
    graph.addEdge(v1, v3, 5);
    graph.addEdge(v2, v4, 5);

    alg::graph::bfs(graph, v1, callback);
    std::vector<int> expectedCallsArguments = {v1, v2, v3, v4};
    EXPECT_EQ(expectedCallsArguments, callsArguments);
}