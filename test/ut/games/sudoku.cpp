//
// Created by pawluch on 2/23/19.
//

#include <gtest/gtest.h>
#include <games/sudoku.hpp>
#include <graph/BreadthFirstSearch/bfs.hpp>

TEST(sudoku, backtracing)
{
    int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    int expected_grid[9][9] =
                     {{3, 1, 6, 5, 7, 8, 4, 9, 2},
                      {5, 2, 9, 1, 3, 4, 7, 6, 8},
                      {4, 8, 7, 6, 2, 9, 5, 3, 1},
                      {2, 6, 3, 4, 1, 5, 9, 8, 7},
                      {9, 7, 4, 8, 6, 3, 1, 2, 5},
                      {8, 5, 1, 7, 9, 2, 6, 4, 3},
                      {1, 3, 8, 9, 4, 7, 2, 5, 6},
                      {6, 9, 2, 3, 5, 1, 8, 7, 4},
                      {7, 4, 5, 2, 8, 6, 3, 1, 9}};
    alg::games::solveSudoku(grid);
    for (int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            EXPECT_EQ(expected_grid[i][j], grid[i][j]);
}

template <class T>
using Matrix = std::vector<std::vector<T>>;

TEST(Sudoku, bfs)
{
    Matrix<int> grid =
           {{3, 0, 6, 5, 0, 8, 4, 0, 0},
            {5, 2, 0, 0, 0, 0, 0, 0, 0},
            {0, 8, 7, 0, 0, 0, 0, 3, 1},
            {0, 0, 3, 0, 1, 0, 0, 8, 0},
            {9, 0, 0, 8, 6, 3, 0, 0, 5},
            {0, 5, 0, 0, 9, 0, 6, 0, 0},
            {1, 3, 0, 0, 0, 0, 2, 5, 0},
            {0, 0, 0, 0, 0, 0, 0, 7, 4},
            {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    Matrix<int> solution;
    std::function<void(const std::vector<Matrix<int>>&)> callback = [&solution](const std::vector<Matrix<int>>& grids)
    {
        int row;
        int col;
        if (!alg::games::detail::findUnassignedLocation(grids.back(), row, col))
        {
            solution = grids.back();
        }
    };
    std::function<std::vector<Matrix<int>>(const Matrix<int>&)> generator = [](const Matrix<int>& grid) -> std::vector<Matrix<int>>
    {
        std::vector<Matrix<int>> generatedNeighborSolutions;
        int row;
        int col;
        if(alg::games::detail::findUnassignedLocation(grid, row, col))
        {
            for (int i = 1; i <= 9; i++)
            {
                if (alg::games::detail::isSafeToAssignValue(grid, row, col, i))
                {
                    auto copy = grid;
                    copy[row][col] = i;
                    generatedNeighborSolutions.emplace_back(copy);
                }
            }
        }
        return generatedNeighborSolutions;
    };
    Matrix<int> expected_grid =
            {{3, 1, 6, 5, 7, 8, 4, 9, 2},
             {5, 2, 9, 1, 3, 4, 7, 6, 8},
             {4, 8, 7, 6, 2, 9, 5, 3, 1},
             {2, 6, 3, 4, 1, 5, 9, 8, 7},
             {9, 7, 4, 8, 6, 3, 1, 2, 5},
             {8, 5, 1, 7, 9, 2, 6, 4, 3},
             {1, 3, 8, 9, 4, 7, 2, 5, 6},
             {6, 9, 2, 3, 5, 1, 8, 7, 4},
             {7, 4, 5, 2, 8, 6, 3, 1, 9}};
    alg::graph::bfs(grid, callback, generator);
    EXPECT_EQ(expected_grid, solution);
}