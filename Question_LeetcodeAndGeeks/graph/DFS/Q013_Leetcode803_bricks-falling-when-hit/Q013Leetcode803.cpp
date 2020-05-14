// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int dir[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
int n, m;
int dfs(vector<vector<int>> &grid, int r, int c)
{
    grid[r][c] = 0;
    int count = 0;
    for (int d = 0; d < 4; d++)
    {
        int x = r + dir[d][0];
        int y = c + dir[d][1];

        if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y])
            count += dfs(grid, x, y);
    }
    return count + 1;
}

vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits)
{

    for (vector<int> &ar : hits)
        grid[ar[0]][ar[1]] = 0;

    for (int i = 0; i < grid[0].size(); i++)
        if (grid[0][i])
            dfs(grid, 0, i);

    int ans = 0;
    for (int i = grid[0].size() - 1; i >= 0; i--)
        ans += dfs(grid, 0, i) - 1;
    
    return ans;
}