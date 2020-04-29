// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

//DFS Solution.========================================================================

void dfs(vector<vector<char>> &grid, int sr, int sc)
{
    grid[sr][sc] = 'N';
    for (int d = 0; d < 4; d++)
    {
        int x = sr + dir[d][0];
        int y = sc + dir[d][1];

        if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 'O')
        {
            dfs(grid, x, y);
        }
    }
}

void solveDFS(vector<vector<char>> &board)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (board.size() == 0 || board[0].size() == 0)
        return;
    int n = board.size();
    int m = board[0].size();

    // upward and downward border.
    for (int j = 0; j < board[0].size(); j++)
    {
        if (board[0][j] == 'O')
            dfs(board, 0, j);
        if (board[n - 1][j] == 'O')
            dfs(board, n - 1, j);
    }

    // left and right border.
    for (int i = 1; i < board.size() - 1; i++)
    {
        if (board[i][0] == 'O')
            dfs(board, i, 0);
        if (board[i][m - 1] == 'O')
            dfs(board, i, m - 1);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == 'N')
                board[i][j] = 'O';
        }
    }
}

//BFS Solution.==========================================================

void solveBFS(vector<vector<char>> &board)
{
    if (board.size() == 0 || board[0].size() == 0)
        return;
    int n = board.size();
    int m = board[0].size();
    queue<pair<int, int>> que;

    // upward and downward border.
    for (int j = 0; j < board[0].size(); j++)
    {
        if (board[0][j] == 'O')
            que.push({0, j});
        if (board[n - 1][j] == 'O')
            que.push({n - 1, j});
    }

    // left and right border.
    for (int i = 1; i < board.size() - 1; i++)
    {
        if (board[i][0] == 'O')
            que.push({i, 0});
        if (board[i][m - 1] == 'O')
            que.push({i, m - 1});
    }

    while (que.size() != 0)
    {

        pair<int, int> rpair = que.front();
        que.pop();
        board[rpair.first][rpair.second] = 'N';
        for (int d = 0; d < 4; d++)
        {
            int x = rpair.first + dir[d][0];
            int y = rpair.second + dir[d][1];

            if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size() && board[x][y] == 'O')
            {
                que.push({x, y});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == 'N')
                board[i][j] = 'O';
        }
    }
}

void solve()
{
}
int main()
{
    solve();
    return 0;
}
