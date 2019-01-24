//
// Created by pawluch on 1/24/19.
//

#include <gtest/gtest.h>
#include <graph/Graph.hpp>
#include <graph/Utils.hpp>

using namespace ::testing;



TEST(UtilsTest, shouldReturnProperCostBetweenEdgesInDirectedGraph)
{
    alg::graph::Graph g{alg::graph::GraphType::Directed};
    auto v1 = g.addVertex();
    auto v2 = g.addVertex();
    g.addEdge(v1, v2, 2);
    auto matrix = g.getAdjacencyMatrix();
    EXPECT_EQ(2, alg::graph::utils::getCost(v1, v2, matrix));
    EXPECT_EQ(boost::none, alg::graph::utils::getCost(v2, v1, matrix));
}

TEST(UtilsTest, shouldReturnProperCostBetweenEdgesInUndirectedGraph)
{
    alg::graph::Graph g{alg::graph::GraphType::Undirected};
    auto v1 = g.addVertex();
    auto v2 = g.addVertex();
    g.addEdge(v1, v2, 2);
    auto matrix = g.getAdjacencyMatrix();
    EXPECT_EQ(2, alg::graph::utils::getCost(v1, v2, matrix));
    EXPECT_EQ(2, alg::graph::utils::getCost(v2, v1, matrix));
}

TEST(UtilsTest, getEgressNeighborsInUndirectedGraph)
{
    alg::graph::Graph g{alg::graph::GraphType::Undirected};
    auto v1 = g.addVertex();
    auto v2 = g.addVertex();
    auto v3 = g.addVertex();
    g.addEdge(v1, v2);
    g.addEdge(v1, v3);
    auto matrix = g.getAdjacencyMatrix();

    std::vector<int> expectedEgressNeighborsOfV1{v2, v3};
    EXPECT_EQ(expectedEgressNeighborsOfV1, alg::graph::utils::getEgressNeighbors(v1, matrix));

    std::vector<int> expectedEgressNeighborsOfV2{v1};
    EXPECT_EQ(expectedEgressNeighborsOfV2, alg::graph::utils::getEgressNeighbors(v2, matrix));

    std::vector<int> expectedEgressNeighborsOfV3{v1};
    EXPECT_EQ(expectedEgressNeighborsOfV3, alg::graph::utils::getEgressNeighbors(v3, matrix));
}

TEST(UtilsTest, getEgressNeighborsInDirectedGraph)
{
    alg::graph::Graph g{alg::graph::GraphType::Directed};
    auto v1 = g.addVertex();
    auto v2 = g.addVertex();
    auto v3 = g.addVertex();
    g.addEdge(v1, v2);
    g.addEdge(v1, v3);
    auto matrix = g.getAdjacencyMatrix();

    std::vector<int> expectedEgressNeighborsOfV1{v2, v3};
    EXPECT_EQ(expectedEgressNeighborsOfV1, alg::graph::utils::getEgressNeighbors(v1, matrix));

    std::vector<int> expectedEgressNeighborsOfV2{};
    EXPECT_EQ(expectedEgressNeighborsOfV2, alg::graph::utils::getEgressNeighbors(v2, matrix));

    std::vector<int> expectedEgressNeighborsOfV3{};
    EXPECT_EQ(expectedEgressNeighborsOfV3, alg::graph::utils::getEgressNeighbors(v3, matrix));
}

TEST(UtilsTest, getIngressNeighborsInUndirectedGraph)
{
    alg::graph::Graph g{alg::graph::GraphType::Undirected};
    auto v1 = g.addVertex();
    auto v2 = g.addVertex();
    auto v3 = g.addVertex();
    g.addEdge(v1, v2);
    g.addEdge(v1, v3);
    auto matrix = g.getAdjacencyMatrix();

    std::vector<int> expectedIngressNeighborsOfV1{v2, v3};
    EXPECT_EQ(expectedIngressNeighborsOfV1, alg::graph::utils::getIngressNeighbors(v1, matrix));

    std::vector<int> expectedIngressNeighborsOfV2{v1};
    EXPECT_EQ(expectedIngressNeighborsOfV2, alg::graph::utils::getIngressNeighbors(v2, matrix));

    std::vector<int> expectedIngressNeighborsOfV3{v1};
    EXPECT_EQ(expectedIngressNeighborsOfV3, alg::graph::utils::getIngressNeighbors(v3, matrix));
}

TEST(UtilsTest, getIngressNeighborsInDirectedGraph)
{
    alg::graph::Graph g{alg::graph::GraphType::Directed};
    auto v1 = g.addVertex();
    auto v2 = g.addVertex();
    auto v3 = g.addVertex();
    g.addEdge(v1, v2);
    g.addEdge(v1, v3);
    auto matrix = g.getAdjacencyMatrix();

    std::vector<int> expectedIngressNeighborsOfV1{};
    EXPECT_EQ(expectedIngressNeighborsOfV1, alg::graph::utils::getIngressNeighbors(v1, matrix));

    std::vector<int> expectedIngressNeighborsOfV2{v1};
    EXPECT_EQ(expectedIngressNeighborsOfV2, alg::graph::utils::getIngressNeighbors(v2, matrix));

    std::vector<int> expectedIngressNeighborsOfV3{v1};
    EXPECT_EQ(expectedIngressNeighborsOfV3, alg::graph::utils::getIngressNeighbors(v3, matrix));
}

TEST(UtilsTest, getNeighborsInUndirectedGraph)
{
    alg::graph::Graph g{alg::graph::GraphType::Undirected};
    auto v1 = g.addVertex();
    auto v2 = g.addVertex();
    auto v3 = g.addVertex();
    g.addEdge(v1, v2);
    g.addEdge(v1, v3);
    auto matrix = g.getAdjacencyMatrix();

    std::vector<int> expectedNeighborsOfV1{v2, v3};
    EXPECT_EQ(expectedNeighborsOfV1, alg::graph::utils::getNeighbors(v1, matrix));

    std::vector<int> expectedNeighborsOfV2{v1};
    EXPECT_EQ(expectedNeighborsOfV2, alg::graph::utils::getNeighbors(v2, matrix));

    std::vector<int> expectedIngressNeighborsOfV3{v1};
    EXPECT_EQ(expectedIngressNeighborsOfV3, alg::graph::utils::getNeighbors(v3, matrix));
}

TEST(UtilsTest, getNeighborsInDirectedGraph)
{
    alg::graph::Graph g{alg::graph::GraphType::Directed};
    auto v1 = g.addVertex();
    auto v2 = g.addVertex();
    auto v3 = g.addVertex();
    g.addEdge(v1, v2);
    g.addEdge(v1, v3);
    auto matrix = g.getAdjacencyMatrix();

    std::vector<int> expectedNeighborsOfV1{v2, v3};
    EXPECT_EQ(expectedNeighborsOfV1, alg::graph::utils::getNeighbors(v1, matrix));

    std::vector<int> expectedNeighborsOfV2{v1};
    EXPECT_EQ(expectedNeighborsOfV2, alg::graph::utils::getNeighbors(v2, matrix));

    std::vector<int> expectedNeighborsOfV3{v1};
    EXPECT_EQ(expectedNeighborsOfV3, alg::graph::utils::getNeighbors(v3, matrix));
}

