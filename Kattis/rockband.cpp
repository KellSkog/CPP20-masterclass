#include <vector>
#include <iostream>
#include <tuple>
/*
1 2 3 4 5 6 7 8 9 10
2 3 4 5 6 7 8 9 10 11
3 4 5 6 7 8 9 10 11 12
4 5 6 7 8 9 10 11 12 13
5 6 7 8 9 10 11 12 13 14
6 7 8 9 10 11 12 13 14 15
7 8 9 10 11 12 13 14 15 16
8 9 10 11 12 13 14 15 16 17
9 10 11 12 13 14 15 16 17 18
10 11 12 13 14 15 16 17 18 19
*/
std::tuple<unsigned, unsigned> scanInput(std::vector<std::vector<int>> &matrix)
{
    unsigned nrows, ncols;
    std::cin >> nrows;
    std::cin >> ncols;
    matrix.resize(nrows);
    for (unsigned i = 0; i < nrows; i++)
    {
        int tmp;
        while (matrix[i].size() < ncols)
        {
            while (!(std::cin >> tmp))
            { // Not a number. Clear cin
                std::cin.clear();
                std::cin.ignore(1);
            }
            matrix[i].push_back(tmp);
        }
    }
    return std::make_tuple(nrows, ncols);
}
int main()
{
    std::vector<std::vector<int>> matrix;
    auto [nrows, ncols] = scanInput(matrix);
    // for (unsigned i = 0; i < nrows; ++i)
    // {
    //     for (unsigned j = 0; j < ncols; ++j)
    //     {
    //         std::cout << matrix[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }
}