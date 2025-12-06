#include <iostream>
using namespace std;
bool isValid(int board[][9], int row, int col, int num)
{
    // for row validation
    for (int j = 0; j < 9; j++)
    {
        if (board[row][j] == num)
        {
            return false;
        }
    }
    // for column validation
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
        {
            return false;
        }
    }
    // for box
    int startr = row - row % 3;
    int startc = col - col % 3;

    for (int i = startr; i < startr + 3; i++)
    {
        for (int j = startc; j < startc + 3; j++)
        {
            if (board[i][j] == num)
                return false;
        }
    }

    return true;
}
bool solve(int board[][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                for (int num = 1; num < 10; num++)
                {
                    if (isValid(board, i, j, num))
                    {
                        board[i][j] = num;
                    }
                }
            }
        }
    }
}
int main()
{
    int board[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    return 0;
}