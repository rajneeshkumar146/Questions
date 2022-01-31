// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int swimInWater(vector<vector<int>> &grid)
{
    if (grid.empty() || grid[0].empty())
        return 0;

    typedef pair<int, int> cell;
    priority_queue<cell, vector<cell>, greater<cell>> pq;

    int n = grid.size();
    int m = grid[0].size();

    pq.push({grid[0][0], 0});

    int ans = 0;
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    while (pq.size() != 0)
    {
        cell rvtx = pq.top();
        pq.pop();

        int x = rvtx.second / m;
        int y = rvtx.second % m;

        ans = max(ans, rvtx.first);
        if (x == n - 1 && y == m - 1)
            return ans;

        for (int d = 0; d < 4; d++)
        {
            int r = x + dir[d][0];
            int c = y + dir[d][1];

            if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] != -1)
            {
                pq.push({grid[r][c], r * m + c});
                grid[r][c] = -1;
            }
        }
    }
    return ans;
}