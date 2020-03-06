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

bool isBipartite(vector<vector<int>> &graph)
{
    int N = graph.size();
    vector<int> vis(N, -1);
    queue<pii> que;
    for (int i = 0; i < N; i++)
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
