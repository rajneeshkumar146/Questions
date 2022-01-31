// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int dir[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
int n, m, time = 0, root = -1;
vector<int> low, disc;

int dfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int r, int c)
{
    vis[r][c] = true;
    int count = 0;
    for (int d = 0; d < 4; d++)
    {
        int x = r + dir[d][0];
        int y = c + dir[d][1];

        if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1 && !vis[x][y])
            count += dfs(grid, vis, x, y);
    }
    return count + 1;
}

bool tarjans(vector<vector<int>> &grid, int src, int par)
{

    disc[src] = low[src] = time++;

    bool res = false;
    for (int d = 0; d < 4; d++)
    {
        int r = src / m + dir[d][0];
        int c = src % m + dir[d][1];

        if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 1)
        {
            int nbr = r * m + c;
            if (disc[nbr] == -1)
            {
                res = res || tarjans(grid, nbr, src);
                if (disc[src] < low[nbr])
                {
                    return true;
                }
                low[src] = min(low[src], low[nbr]);
      
            }
            else if (nbr != par)
            {
                low[src] = min(low[src], disc[nbr]);
            }
        }
    }
    return res;
}

int minDays(vector<vector<int>> &grid)
{
    n = grid.size(), m = grid[0].size();
    int component = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int size = 0;

    for (int i = 0; i < n * m; i++)
    {
        low.push_back(0);
        disc.push_back(-1);
    }

    for (int i = 0; i < n * m; i++)
    {
        if (grid[i / m][i % m] == 1 && !vis[i / m][i % m])
        {
            root = i;
            size = dfs(grid, vis, i / m, i % m);
            component++;
        }
    }

    if (component != 1)
        return 0;
    if (size <= 2)
        return size;

    bool res = tarjans(grid, root, -1);
    return res ? 1 : 2;
}