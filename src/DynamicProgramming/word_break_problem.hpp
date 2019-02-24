//
// Created by pawluch on 2/24/19.
//

#ifndef ALGORITHMS_WORD_BREAK_PROBLEM_HPP
#define ALGORITHMS_WORD_BREAK_PROBLEM_HPP

#include <string>
#include <vector>

namespace alg
{
    namespace dp
    {
        namespace recursive {
            bool word_break_problem(const std::string &word, const std::vector<std::string> &dictionary);
        }
        bool word_break_problem(const std::string &word, const std::vector<std::string> &dictionary);
    }
}

#endif //ALGORITHMS_WORD_BREAK_PROBLEM_HPP
