//
// Created by pawluch on 1/24/19.
//

#include <gtest/gtest.h>
#include <graph/Graph.hpp>
#include <graph/Utils.hpp>

using namespace ::testing;

TEST(GraphTest, shouldReturnProperNumOfVertexes)
{
    alg::graph::Graph g{alg::graph::GraphType::Directed};
    auto v1 = g.addVertex();
    auto v2 = g.addVertex();
    g.addEdge(v1, v2, 2);

    EXPECT_EQ(2, g.getNumOfVertexes());
}


TEST(GraphTest, shouldReturnProperAdjacencyMatrixForDirectedGraph)
{
    alg::graph::Graph g{alg::graph::GraphType::Directed};
    auto v1 = g.addVertex();
    auto v2 = g.addVertex();
    g.addEdge(v1, v2, 2);
    std::vector<std::vector<boost::optional<int>>> expectedMatrix;

    expectedMatrix.push_back({boost::none, 2          });
    expectedMatrix.push_back({boost::none, boost::none});

    EXPECT_EQ(expectedMatrix, g.getAdjacencyMatrix());
}

TEST(GraphTest, shouldReturnProperAdjacencyMatrixForUndirectedGraph)
{
    alg::graph::Graph g{alg::graph::GraphType::Undirected};
    auto v1 = g.addVertex();
    auto v2 = g.addVertex();
    g.addEdge(v1, v2, 2);
    std::vector<std::vector<boost::optional<int>>> expectedMatrix;

    expectedMatrix.push_back({boost::none, 2          });
    expectedMatrix.push_back({2          , boost::none});

    EXPECT_EQ(expectedMatrix, g.getAdjacencyMatrix());
}

TEST(GraphTest, shouldReturnProperCostBetweenEdgesInDirectedGraph)
{
    alg::graph::Graph g{alg::graph::GraphType::Directed};
    auto v1 = g.addVertex();
    auto v2 = g.addVertex();
    g.addEdge(v1, v2, 2);
    auto matrix = g.getAdjacencyMatrix();
    EXPECT_EQ(2, g.getCost(v1, v2));
    EXPECT_EQ(boost::none, g.getCost(v2, v1));
}

TEST(GraphTest, shouldReturnProperCostBetweenEdgesInUndirectedGraph)
{
    alg::graph::Graph g{alg::graph::GraphType::Undirected};
    auto v1 = g.addVertex();
    auto v2 = g.addVertex();
    g.addEdge(v1, v2, 2);
    auto matrix = g.getAdjacencyMatrix();
    EXPECT_EQ(2, g.getCost(v1, v2));
    EXPECT_EQ(2, g.getCost(v2, v1));
}

TEST(GraphTest, getEgressNeighborsInUndirectedGraph)
{
    alg::graph::Graph g{alg::graph::GraphType::Undirected};
    auto v1 = g.addVertex();
    auto v2 = g.addVertex();
    auto v3 = g.addVertex();
    g.addEdge(v1, v2);
    g.addEdge(v1, v3);
    auto matrix = g.getAdjacencyMatrix();

    std::vector<int> expectedEgressNeighborsOfV1{v2, v3};
    EXPECT_EQ(expectedEgressNeighborsOfV1, g.getEgressNeighbors(v1));

    std::vector<int> expectedEgressNeighborsOfV2{v1};
    EXPECT_EQ(expectedEgressNeighborsOfV2, g.getEgressNeighbors(v2));

    std::vector<int> expectedEgressNeighborsOfV3{v1};
    EXPECT_EQ(expectedEgressNeighborsOfV3, g.getEgressNeighbors(v3));
}

TEST(GraphTest, getEgressNeighborsInDirectedGraph)
{
    alg::graph::Graph g{alg::graph::GraphType::Directed};
    auto v1 = g.addVertex();
    auto v2 = g.addVertex();
    auto v3 = g.addVertex();
    g.addEdge(v1, v2);
    g.addEdge(v1, v3);
    auto matrix = g.getAdjacencyMatrix();

    std::vector<int> expectedEgressNeighborsOfV1{v2, v3};
    EXPECT_EQ(expectedEgressNeighborsOfV1, g.getEgressNeighbors(v1));

    std::vector<int> expectedEgressNeighborsOfV2{};
    EXPECT_EQ(expectedEgressNeighborsOfV2, g.getEgressNeighbors(v2));

    std::vector<int> expectedEgressNeighborsOfV3{};
    EXPECT_EQ(expectedEgressNeighborsOfV3, g.getEgressNeighbors(v3));
}

TEST(GraphTest, getIngressNeighborsInUndirectedGraph)
{
    alg::graph::Graph g{alg::graph::GraphType::Undirected};
    auto v1 = g.addVertex();
    auto v2 = g.addVertex();
    auto v3 = g.addVertex();
    g.addEdge(v1, v2);
    g.addEdge(v1, v3);
    auto matrix = g.getAdjacencyMatrix();

    std::vector<int> expectedIngressNeighborsOfV1{v2, v3};
    EXPECT_EQ(expectedIngressNeighborsOfV1, g.getIngressNeighbors(v1));

    std::vector<int> expectedIngressNeighborsOfV2{v1};
    EXPECT_EQ(expectedIngressNeighborsOfV2, g.getIngressNeighbors(v2));

    std::vector<int> expectedIngressNeighborsOfV3{v1};
    EXPECT_EQ(expectedIngressNeighborsOfV3, g.getIngressNeighbors(v3));
}

TEST(GraphTest, getIngressNeighborsInDirectedGraph)
{
    alg::graph::Graph g{alg::graph::GraphType::Directed};
    auto v1 = g.addVertex();
    auto v2 = g.addVertex();
    auto v3 = g.addVertex();
    g.addEdge(v1, v2);
    g.addEdge(v1, v3);
    auto matrix = g.getAdjacencyMatrix();

    std::vector<int> expectedIngressNeighborsOfV1{};
    EXPECT_EQ(expectedIngressNeighborsOfV1, g.getIngressNeighbors(v1));

    std::vector<int> expectedIngressNeighborsOfV2{v1};
    EXPECT_EQ(expectedIngressNeighborsOfV2, g.getIngressNeighbors(v2));

    std::vector<int> expectedIngressNeighborsOfV3{v1};
    EXPECT_EQ(expectedIngressNeighborsOfV3, g.getIngressNeighbors(v3));
}

TEST(GraphTest, getNeighborsInUndirectedGraph)
{
    alg::graph::Graph g{alg::graph::GraphType::Undirected};
    auto v1 = g.addVertex();
    auto v2 = g.addVertex();
    auto v3 = g.addVertex();
    g.addEdge(v1, v2);
    g.addEdge(v1, v3);
    auto matrix = g.getAdjacencyMatrix();

    std::vector<int> expectedNeighborsOfV1{v2, v3};
    EXPECT_EQ(expectedNeighborsOfV1, g.getNeighbors(v1));

    std::vector<int> expectedNeighborsOfV2{v1};
    EXPECT_EQ(expectedNeighborsOfV2, g.getNeighbors(v2));

    std::vector<int> expectedIngressNeighborsOfV3{v1};
    EXPECT_EQ(expectedIngressNeighborsOfV3, g.getNeighbors(v3));
}

TEST(GraphTest, getNeighborsInDirectedGraph)
{
    alg::graph::Graph g{alg::graph::GraphType::Directed};
    auto v1 = g.addVertex();
    auto v2 = g.addVertex();
    auto v3 = g.addVertex();
    g.addEdge(v1, v2);
    g.addEdge(v1, v3);
    auto matrix = g.getAdjacencyMatrix();

    std::vector<int> expectedNeighborsOfV1{v2, v3};
    EXPECT_EQ(expectedNeighborsOfV1, g.getNeighbors(v1));

    std::vector<int> expectedNeighborsOfV2{v1};
    EXPECT_EQ(expectedNeighborsOfV2, g.getNeighbors(v2));

    std::vector<int> expectedNeighborsOfV3{v1};
    EXPECT_EQ(expectedNeighborsOfV3, g.getNeighbors(v3));
}

TEST(GraphTest, getAdjacencyListForUndirectedGraph)
{
    alg::graph::Graph g{alg::graph::GraphType::Undirected};
    auto v0 = g.addVertex();
    auto v1 = g.addVertex();
    auto v2 = g.addVertex();
    auto v3 = g.addVertex();
    auto v4 = g.addVertex();
    g.addEdge(v0, v1, 1);
    g.addEdge(v0, v4, 1);
    g.addEdge(v1, v4, 1);
    g.addEdge(v1, v3, 1);
    g.addEdge(v1, v2, 1);
    g.addEdge(v3, v4, 1);
    g.addEdge(v2, v3, 1);

    auto adjList = g.getAdjacencyList();

    std::list<std::pair<int, int>> listOfV0{std::make_pair(1,1), std::make_pair(4,1)};
    EXPECT_EQ(listOfV0, adjList[v0]);

    std::list<std::pair<int, int>> listOfV1{std::make_pair(0,1), std::make_pair(4,1), std::make_pair(3,1), std::make_pair(2,1)};
    EXPECT_EQ(listOfV1, adjList[v1]);

    std::list<std::pair<int, int>> listOfV2{std::make_pair(1,1), std::make_pair(3,1)};
    EXPECT_EQ(listOfV2, adjList[v2]);

    std::list<std::pair<int, int>> listOfV3{std::make_pair(1,1), std::make_pair(4,1), std::make_pair(2,1)};
    EXPECT_EQ(listOfV3, adjList[v3]);

    std::list<std::pair<int, int>> listOfV4{std::make_pair(0,1), std::make_pair(1,1), std::make_pair(3,1)};
    EXPECT_EQ(listOfV4, adjList[v4]);
}

TEST(GraphTest, getAdjacencyListForDirectedGraph)
{
    alg::graph::Graph g{alg::graph::GraphType::Directed};
    auto v0 = g.addVertex();
    auto v1 = g.addVertex();
    auto v2 = g.addVertex();
    auto v3 = g.addVertex();
    auto v4 = g.addVertex();
    g.addEdge(v0, v1, 1);
    g.addEdge(v0, v4, 1);
    g.addEdge(v1, v4, 1);
    g.addEdge(v1, v3, 1);
    g.addEdge(v1, v2, 1);
    g.addEdge(v3, v4, 1);
    g.addEdge(v2, v3, 1);

    auto adjList = g.getAdjacencyList();

    std::list<std::pair<int, int>> listOfV0{std::make_pair(1,1), std::make_pair(4,1)};
    EXPECT_EQ(listOfV0, adjList[v0]);

    std::list<std::pair<int, int>> listOfV1{std::make_pair(4,1), std::make_pair(3,1), std::make_pair(2,1)};
    EXPECT_EQ(listOfV1, adjList[v1]);

    std::list<std::pair<int, int>> listOfV2{std::make_pair(3,1)};
    EXPECT_EQ(listOfV2, adjList[v2]);

    std::list<std::pair<int, int>> listOfV3{std::make_pair(4,1)};
    EXPECT_EQ(listOfV3, adjList[v3]);

    std::list<std::pair<int, int>> listOfV4{};
    EXPECT_EQ(listOfV4, adjList[v4]);
}