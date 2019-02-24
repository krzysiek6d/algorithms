//
// Created by pawluch on 2/24/19.
//
#include "word_break_problem.hpp"
#include <algorithm>
#include <iostream>

namespace alg
{
    namespace dp
    {
        namespace detail
        {
            bool isInDictionary(const std::string& word, const std::vector<std::string>& dictionary)
            {
                return std::any_of(dictionary.begin(), dictionary.end(), [&word](const std::string& elem){ return word == elem;});
            }
        }
        namespace recursive {
            bool word_break_problem(const std::string &word, const std::vector<std::string> &dictionary, std::string solution) {
                auto result = false;
                if (word.empty()) {
                    std::cout << solution << std::endl;
                    return true;
                }
                for (auto i = 1u; i <= word.length(); i++) {
                    std::string left = word.substr(0, i);
                    std::string right = word.substr(i, word.length());
                    if (detail::isInDictionary(left, dictionary)) {
                        result = word_break_problem(right, dictionary, solution + left + " ");
                    }
                }
                return result;
            }
            bool word_break_problem(const std::string &word, const std::vector<std::string> &dictionary) {
                std::string solution;
                return word_break_problem(word, dictionary, solution);
            }
        }
        bool word_break_problem(const std::string &word, const std::vector<std::string> &dictionary) {
            if (word.empty())
                return true;

            std::vector<bool> dp(word.length() +1, false);
            for (auto i=1u; i <= word.length(); i++)
            {
                if (dp[i] == false && detail::isInDictionary(word.substr(0, i), dictionary))
                    dp[i] = true;

                if (dp[i] == true)
                {
                    for (auto j = i+1; j <= word.length(); j++)
                    {
                        if (dp[j] == false && detail::isInDictionary(word.substr(i, j-i) , dictionary))
                            dp[j] = true;
                    }
                }
            }
            return dp[word.length()];
        }
    }
}

