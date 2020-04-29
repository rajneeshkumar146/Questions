#include <iostream>
using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

int dfs(int x, int y, int &len, vector<vector<int>> &grid)
{
    grid[x][y] = 2;
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int rad = 1; rad <= len; rad++)
        {
            int u = x + rad * dir[i][0];
            int v = y + rad * dir[i][1];

            if (u >= 0 && v >= 0 && u < grid.size() && v < grid[0].size())
            {
                if (grid[u][v] == 1)
                    count += dfs(u, v, len, grid);
            }
            else
                break;
        }
    }

    return count + 1;
}

int method01(vector<vector<int>> &grid)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int ans = 0;
    int len = max(grid.size(), grid[0].size());
    for (int u = 0; u < grid.size(); u++)
        for (int v = 0; v < grid[0].size(); v++)
            if (grid[u][v] == 1)
            {
                int count = dfs(u, v, len, grid);
                ans += (count == 1 ? 0 : count);
            }

    return ans;
}

//method2.Fast.==========================================

int method02(vector<vector<int>> &grid)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = grid.size();
    int m = grid[0].size();
    vector<int> row(n, 0);
    vector<int> col(m, 0);

    int total_server = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            row[i] += grid[i][j];
            col[j] += grid[i][j];
            total_server += grid[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && row[i] * col[j] * grid[i][j] == 1)
                total_server--;
        }
    }

    return total_server;
}

int countServers(vector<vector<int>> &grid)
{
}

int main()
{

    return;
}