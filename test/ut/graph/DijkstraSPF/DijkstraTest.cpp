//
// Created by pawluch on 1/24/19.
//

#include <gtest/gtest.h>
#include <graph/DijkstraSPF/dijkstra.hpp>

using namespace ::testing;

std::vector<int> reconstructPath(int src, int dst, std::vector<int> sfp)
{
    std::vector<int> path;
    path.push_back(dst);
    int prev = dst;
    while(true)
    {
        prev = sfp[prev];
        if (prev != -1)
            path.push_back(prev);
        else
            break;
    }
    std::reverse(path.begin(), path.end());
    return path;
}

TEST(DijkstraTest, shouldCalculateSPF)
{
    alg::graph::Graph graph{alg::graph::GraphType::Directed};
    auto v1 = graph.addVertex();
    auto v2 = graph.addVertex();
    graph.addEdge(v1, v2, 5);

    auto result = alg::graph::dijkstra(graph, v1);
    std::vector<int> actualPathV1V2 = reconstructPath(v1, v2, result);
    std::vector<int> expectedPathFromV1V2 = {v1, v2};

    EXPECT_EQ(expectedPathFromV1V2, actualPathV1V2);
}

TEST(DijkstraTest, shouldCalculateSPFdiamond)
{
    alg::graph::Graph graph{alg::graph::GraphType::Directed};
    auto v1 = graph.addVertex();
    auto v2 = graph.addVertex();
    auto v3 = graph.addVertex();
    auto v4 = graph.addVertex();
    graph.addEdge(v1, v2, 1);
    graph.addEdge(v1, v3, 1);
    graph.addEdge(v2, v4, 1);
    graph.addEdge(v3, v4, 2);

    auto result = alg::graph::dijkstra(graph, v1);

    std::vector<int> actualPathV1V4 = reconstructPath(v1, v4, result);
    std::vector<int> expectedPathFromV1V4 = {v1, v2, v4};

    EXPECT_EQ(expectedPathFromV1V4, actualPathV1V4);
}

TEST(DijkstraTest, shouldCalculateSPFdiamondStartingFromOtherThanFirstVertex)
{
    alg::graph::Graph graph{alg::graph::GraphType::Directed};
    auto v1 = graph.addVertex();
    auto v2 = graph.addVertex();
    auto v3 = graph.addVertex();
    auto v4 = graph.addVertex();
    graph.addEdge(v2, v1, 1);
    graph.addEdge(v2, v3, 1);
    graph.addEdge(v1, v4, 1);
    graph.addEdge(v3, v4, 2);

    auto result = alg::graph::dijkstra(graph, v2);
    std::vector<int> actualPathV2V4 = reconstructPath(v2, v4, result);
    std::vector<int> expectedPathFromV2V4 = {v2, v1, v4};

    EXPECT_EQ(expectedPathFromV2V4, actualPathV2V4);
}

TEST(DijkstraTest, moreComplexTest)
{
    alg::graph::Graph graph{alg::graph::GraphType::Directed};
    auto v0 = graph.addVertex();
    auto v1 = graph.addVertex();
    auto v2 = graph.addVertex();
    auto v3 = graph.addVertex();
    auto v4 = graph.addVertex();
    auto v5 = graph.addVertex();
    graph.addEdge(v0, v1, 3);
    graph.addEdge(v0, v4, 3);
    graph.addEdge(v1, v2, 1);
    graph.addEdge(v2, v3, 3);
    graph.addEdge(v2, v5, 1);
    graph.addEdge(v3, v1, 3);
    graph.addEdge(v4, v5, 2);
    graph.addEdge(v5, v0, 6);
    graph.addEdge(v5, v3, 1);

    auto result = alg::graph::dijkstra(graph, v0);
    std::vector<int> expected_p = {-1, v0, v1, v5, v0, v4};
    EXPECT_EQ(expected_p, result);

    std::vector<int> expectedPathFromV0V0 = {v0};
    std::vector<int> expectedPathFromV0V1 = {v0, v1};
    std::vector<int> expectedPathFromV0V2 = {v0, v1, v2};
    std::vector<int> expectedPathFromV0V3 = {v0, v4, v5, v3};
    std::vector<int> expectedPathFromV0V4 = {v0, v4};
    std::vector<int> expectedPathFromV0V5 = {v0, v4, v5};

    EXPECT_EQ(expectedPathFromV0V0, reconstructPath(v0, v0, result));
    EXPECT_EQ(expectedPathFromV0V1, reconstructPath(v0, v1, result));
    EXPECT_EQ(expectedPathFromV0V2, reconstructPath(v0, v2, result));
    EXPECT_EQ(expectedPathFromV0V3, reconstructPath(v0, v3, result));
    EXPECT_EQ(expectedPathFromV0V4, reconstructPath(v0, v4, result));
    EXPECT_EQ(expectedPathFromV0V5, reconstructPath(v0, v5, result));
}