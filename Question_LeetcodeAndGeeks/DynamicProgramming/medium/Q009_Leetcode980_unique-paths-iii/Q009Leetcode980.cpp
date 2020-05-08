// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int uniquePathsIII(int sr, int sc, int er, int ec, int freeCell, vector<vector<int>> &board, vector<vector<int>> &dir)
{
    if (sr == er && sc == ec)
    {
        if (freeCell == 1)
            return 1;
        return 0;
    }

    int count = 0;
    int temp = board[sr][sc];
    board[sr][sc] = -2;

    for (int d = 0; d < 4; d++)
    {
        int x = sr + dir[d][0];
        int y = sc + dir[d][1];
        if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size() && board[x][y] >= 0)
            count += uniquePathsIII(x, y, er, ec, freeCell - 1, board, dir);
    }

    board[sr][sc] = temp;
    return count;
}

int uniquePathsIII(vector<vector<int>> &board)
{
    vector<vector<int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int sr, sc, er, ec;
    int freeCell = 0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] != -1)
                freeCell++;
            if (board[i][j] == 1)
            {
                sr = i;
                sc = j;
            }

            if (board[i][j] == 2)
            {
                er = i;
                ec = j;
            }
        }
    }

    return uniquePathsIII(sr, sc, er, ec, freeCell, board, dir);
}
