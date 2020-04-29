#include <iostream>
#include <queue>

#define pii pair<int, int>
using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

vector<vector<int>> distance, reach, vis;
int n, m;

void minTotalDistance_(int src, vector<vector<int>> &grid)
{
    int dirA[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    queue<int> que;
    que.push(src);

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
            reach[r][c]++;

            for (int d = 0; d < 4; d++)
            {
                int x = r + dirA[d][0];
                int y = c + dirA[d][1];

                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0 && vis[x][y] == 0)
                {
                    que.push((x * m + y));
                    distance[x][y] += level;
                    vis[x][y] = 1;
                }
            }
        }
        level++;
    }
}

int minTotalDistance(vector<vector<int>> &grid)
{
    if (grid.size() == 0 || grid[0].size() == 0)
        return -1;

    n = grid.size();
    m = grid[0].size();
    distance.resize(n, vector<int>(m, 0));
    reach.resize(n, vector<int>(m, 0));

    int NoofOnces = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 1) 
            {
                vis.clear();
                vis.resize(n, vector<int>(m, 0));
                vis[i][j] = 1;
                minTotalDistance_(i * m + j, grid);
                NoofOnces++;
            }
    int min_ = 1e8;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (distance[i][j] != 0 && reach[i][j] == NoofOnces)
            {
                min_ = min(min_, distance[i][j]);
            }
    return min_ != 1e8 ? min_ : -1;
}