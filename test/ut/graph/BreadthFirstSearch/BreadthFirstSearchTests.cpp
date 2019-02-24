//
// Created by pawluch on 1/24/19.
//

#include <gtest/gtest.h>
#include <graph/BreadthFirstSearch/bfs.hpp>
#include <vector>

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

TEST(BFSTest, RemoveInvalidBrackets)
{
    std::vector<std::vector<std::string>> results;
    auto isValid = [](const std::string& str)->bool
    {
        int cnt = 0;
        for (auto i = 0u; i < str.length(); i++)
        {
            std::queue<char> q;
            if (str[i] == '(')
                cnt++;
            else if (str[i] == ')')
                cnt--;
            if (cnt < 0)
                return false;
        }
        return (cnt == 0);
    };
    std::function<void(const std::vector<std::string>&)> callback = [&](const std::vector<std::string>& str)
    {
        if (isValid(str.back()))
            results.push_back(str);
    };

    std::function<std::vector<std::string>(const std::string&)> generator = [](const std::string& str)->std::vector<std::string>
    {
        std::vector<std::string> result;
        if (str.length() > 4) {
            for (auto i = 0u; i < str.length(); i++) {
                auto copy = str;
                copy.erase(std::next(copy.begin(), i));
                result.push_back(copy);
            }
        }
        return result;
    };
    std::string str = "()())()";
    alg::graph::bfs(str, callback, generator);

    std::vector<std::vector<std::string>> expected =  {
            { "()())()", "(())()" },
            { "()())()", "()()()" },
            { "()())()", ")())()", "())()", "()()" },
            { "()())()", "(())()", "(()()", "(())" } };
    EXPECT_EQ(expected, results);
}
