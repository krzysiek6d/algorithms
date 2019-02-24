//
// Created by pawluch on 2/23/19.
//

#ifndef ALGORITHMS_SUDOKU_HPP
#define ALGORITHMS_SUDOKU_HPP

namespace alg
{
    namespace games
    {

        namespace detail
        {
            constexpr int N = 9;
            constexpr int UNASSIGNED = 0;

            struct GridLocation
            {
                unsigned short col;
                unsigned short row;
            };

            template <typename T>
            bool findUnassignedLocation(T grid, int &row, int &col)
            {
                for (row = 0; row < N; row++)
                    for (col = 0; col < N; col++)
                        if (grid[row][col] == UNASSIGNED)
                            return true;
                return false;
            }

            template <typename T>
            bool isValueAlreadyInRow(T grid, int row, int num)
            {
                for (int col = 0; col < N; col++)
                    if (grid[row][col] == num)
                        return true;
                return false;
            }

            template <typename T>
            bool isValueAlreadyInCol(T grid, int col, int num)
            {
                for (int row = 0; row < N; row++)
                    if (grid[row][col] == num)
                        return true;
                return false;
            }

            template <typename T>
            bool isValueAlreadyInBox(T grid, int boxStartRow, int boxStartCol, int num)
            {
                for (int row = 0; row < 3; row++)
                    for (int col = 0; col < 3; col++)
                        if (grid[row+boxStartRow][col+boxStartCol] == num)
                            return true;
                return false;
            }

            template <typename T>
            bool isSafeToAssignValue(T grid, int row, int col, int num)
            {
                return !isValueAlreadyInRow(grid, row, num) &&
                       !isValueAlreadyInCol(grid, col, num) &&
                       !isValueAlreadyInBox(grid, row - row%3 , col - col%3, num)&&
                       grid[row][col]==UNASSIGNED;
            }

            template <typename T>
            bool solveSudoku(T grid)
            {
                int row, col;
                if (!findUnassignedLocation(grid, row, col))
                    return true;

                for (int num = 1; num <= 9; num++)
                {
                    if (isSafeToAssignValue(grid, row, col, num))
                    {
                        grid[row][col] = num;

                        if (solveSudoku(grid))
                            return true;

                        grid[row][col] = UNASSIGNED;
                    }
                }
                return false;
            }
        }
        template <typename T>
        bool solveSudoku(T grid)
        {
            return detail::solveSudoku(grid);
        }
    }
}

#endif //ALGORITHMS_SUDOKU_HPP
