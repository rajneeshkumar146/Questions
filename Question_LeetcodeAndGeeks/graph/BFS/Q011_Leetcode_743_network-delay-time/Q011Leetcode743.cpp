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

//Approach 01.==============================================================

int networkDelayTime(vector<vector<int>> &times, int N, int K)
{

    vector<vector<pair<int, int>>> graph(N + 1);
    for (auto &ar : times)
        graph[ar[0]].push_back({ar[1], ar[2]});
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(N + 1, -1);

    pq.push({0, K});

    while (pq.size() != 0)
    {
        auto rvtx = pq.top();
        pq.pop();
        if (dis[rvtx.second] != -1)
            continue;
        dis[rvtx.second] = rvtx.first;
        for (auto &e : graph[rvtx.second])
        {
            if (dis[e.first] == -1)
                pq.push({rvtx.first + e.second, e.first});
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
        if (dis[i] == -1)
            return -1;
        else
            ans = max(ans, dis[i]);
    return ans;
}

//approach 02.================================================================

int networkDelayTime(vector<vector<int>> &times, int N, int K)
{
    vector<vector<pair<int, int>>> graph(N + 1, vector<pair<int, int>>());
    for (vector<int> &ar : times)
        graph[ar[0]].push_back({ar[1], ar[2]});
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(N + 1, INT_MAX);

    pq.push({0, K});
    dis[K] = 0;

    while (pq.size() != 0)
    {
        int size = pq.size();
        while (size-- > 0)
        {
            auto rvtx = pq.top();
            pq.pop();
            for (auto &e : graph[rvtx.second])
            {
                if (dis[e.first] > rvtx.first + e.second)
                {                                         // check for nbrs, if its value is not calculated yet.
                    dis[e.first] = rvtx.first + e.second; // mark it so that cycle didn't occure.
                    pq.push({dis[e.first], e.first});
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans = max(ans, dis[i]);
    return ans == INT_MAX ? -1 : ans;
}