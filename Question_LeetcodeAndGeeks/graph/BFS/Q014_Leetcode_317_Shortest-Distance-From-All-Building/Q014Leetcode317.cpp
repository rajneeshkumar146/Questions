#include <iostream>
#include <queue>

#define pii pair<int, int>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &grid)
{
    if (grid.size() == 0 || grid[0].size() == 0)
        return grid;

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int dirA[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    queue<int> que;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 0)
                que.push((i * m + j));

    int level = 1;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int rvtx = que.front();
            que.pop();

            int r = rvtx / m;
            int c = rvtx % m;

            for (int d = 0; d < 4; d++)
            {
                int x = r + dirA[d][0];
                int y = c + dirA[d][1];

                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != 0 && vis[x][y] == 0)
                {
                    que.push((x * m + y));
                    grid[x][y] = level;
                    vis[x][y] = 1;
                }
            }
        }
        level++;
    }

    return grid;
}