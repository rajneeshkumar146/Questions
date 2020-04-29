#include <iostream>
#include <vector>
#include <string>
#include <queue>

#define vi vector<int>
#define vii vector<vi>

#define pii pair<int, int>

using namespace std;

auto SpeedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

vii graph;

bool possibleBipartition(int N, vector<vector<int>> &list)
{
    graph.resize(N + 1, vi());
    for (const auto &ar : list)
    {
        graph[ar[0]].push_back(ar[1]);
        graph[ar[1]].push_back(ar[0]);
    }

    vector<int> vis(N + 1, -1);
    queue<pii> que;
    for (int i = 1; i <= N; i++)
    {
        if (vis[i] != -1)
            continue;

        que.push({i, 0});
        while (que.size() != 0)
        {
            pii vtx = que.front();
            que.pop();
            if (vis[vtx.first] != -1 && vtx.second != vis[vtx.first])
                return false;

            vis[vtx.first] = vtx.second;
            for (int e : graph[vtx.first])
            {
                if (vis[e] == -1)
                    que.push({e, (vtx.second + 1) % 2});
            }
        }
    }
    return true;
}
