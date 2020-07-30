// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int trapRainWater(vector<vector<int>> &heightMap)
{
    if (heightMap.empty() || heightMap[0].empty())
        return 0;

    typedef pair<int, int> cell;
    priority_queue<cell, vector<cell>, greater<cell>> pq;

    int n = heightMap.size();
    int m = heightMap[0].size();
    vector<vector<bool>> visited(n , vector<bool>(m,false));

    for (int i = 0; i < n; i++)
    {
        pq.push({heightMap[i][0], i * m});
        pq.push({heightMap[i][m - 1], i * m + m - 1});
        visited[i][0]=true;
        visited[i][m-1]=true;
    }

    for (int j = 0; j < m; j++)
    {
        pq.push({heightMap[0][j], j});
        pq.push({heightMap[n - 1][j], (n - 1) * m + j});
        visited[0][j]=true;
        visited[n-1][j]=true;
    }

    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int water = 0, Max = 0;
    while (pq.size() != 0)
    {
        auto rvtx = pq.top();
        pq.pop();

        int x = rvtx.second / m;
        int y = rvtx.second % m;
        int height = rvtx.first;

        Max = max(Max, height);
        for (int d = 0; d < 4; d++)
        {
            int r = x + dir[d][0];
            int c = y + dir[d][1];

            if (r >= 0 && c >= 0 && r < n && c < m && !visited[r][c])
            {
                water += max(0, Max - heightMap[r][c]);
                visited[r][c] = true;
                pq.push({heightMap[r][c], r * m + c});
            }
        }
    }

    return water;
}
