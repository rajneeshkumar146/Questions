// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int dfs(vector<vector<int>> &grid, int sr, int sc)
{
    grid[sr][sc] = 0;
    int count = 0;
    for (int d = 0; d < 4; d++)
    {
        int x = sr + dir[d][0];
        int y = sc + dir[d][1];

        if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1)
        {
            count += dfs(grid, x, y);
        }
    }

    return count + 1;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int max_area = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
                max_area = max(max_area, dfs(grid, i, j));
        }
    }

    return max_area;
}

void solve()
{
}
int main()
{
    solve();
    return 0;
}
