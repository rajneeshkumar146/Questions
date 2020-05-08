// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getMaximumGold(int r, int c, vector<vector<int>> &board, vector<vector<int>> &dir)
{
    board[r][c] = -board[r][c];
    int res = 0;
    for (int d = 0; d < 4; d++)
    {
        int x = r + dir[d][0];
        int y = c + dir[d][1];

        if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size() && board[x][y] > 0)
            res = max(res, getMaximumGold(x, y, board, dir));
    }

    board[r][c] = -board[r][c];
    return res + board[r][c];
}

int getMaximumGold(vector<vector<int>> &board)
{
    vector<vector<int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int res = 0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] > 0)
            {
                res = max(res, getMaximumGold(i, j, board, dir));
            }
        }
    }
    return res;
}