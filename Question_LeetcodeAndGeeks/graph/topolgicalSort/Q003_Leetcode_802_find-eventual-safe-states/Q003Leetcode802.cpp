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

vector<int> vis;
int n;

bool dfs_cycle(int src, vector<vector<int>> &graph)
{
    if (vis[src] > 0)
        return vis[src] == 1;

    vis[src] = 1;
    for (int &ele : graph[src])
    {
        if (vis[ele] == 2)
            continue;
        if (vis[ele] == 1 || dfs_cycle(ele, graph))
            return true;
    }

    vis[src] = 2;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    n = graph.size();
    vector<int> ans;
    vis.resize(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 1)
            continue;
        if (vis[i] == 2 || !dfs_cycle(i, graph))
        {
            ans.push_back(i);
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}
