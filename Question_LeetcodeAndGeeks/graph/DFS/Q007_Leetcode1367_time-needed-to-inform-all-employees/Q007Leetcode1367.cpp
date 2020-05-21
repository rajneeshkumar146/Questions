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

//BFS.==================================================================================

int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
{
    vector<vector<int>> graph(n);
    for (int i = 0; i < manager.size(); i++)
        if (manager[i] != -1)
            graph[manager[i]].push_back(i);

    queue<pair<int, int>> que;
    que.push({headID, 0});

    int maxTime = 0;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            pair<int, int> rvtx = que.front();
            que.pop();

            maxTime = max(maxTime, rvtx.second);
            for (int ele : graph[rvtx.first])
                que.push({ele, rvtx.second + informTime[rvtx.first]});
        }
    }
    return maxTime;
}

//DFS.========================================================================

int dfs(int src, vector<vector<int>> &graph, vector<int> &informTime)
{
    int time = 0;
    for (int e : graph[src])
        time = max(time, dfs(e, graph, informTime) + informTime[src]);

    return time;
}

int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
{
    vector<vector<int>> graph(n);
    for (int i = 0; i < manager.size(); i++)
        if (manager[i] != -1)
            graph[manager[i]].push_back(i);

    return dfs(headID, graph, informTime);
}
