// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>
#define pi pair<int, int>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
{
    vector<vector<pi>> graph(n);
    for (auto &ar : flights)
        graph[ar[0]].push_back({ar[1], ar[2]});

    priority_queue<vi, vector<vi>, greater<vi>> pq;
    pq.push({0, src, K + 1});

    while (pq.size() != 0)
    {
        auto rvtx = pq.top();
        pq.pop();

        if (rvtx[1] == dst)
            return rvtx[0];
        if (rvtx[2] == 0)
            continue;

        for (auto &e : graph[rvtx[1]])
            pq.push({rvtx[0] + e.second, e.first, rvtx[2] - 1});
    }
    return -1;
}

//Applying BellmanFord Algo for single src.====================================================

int findCheapestPrice_02(int n, vector<vector<int>> &flights, int src, int dst, int K)
{
    int INF = 1e8;
    K++;
    vector<vector<int>> dp(n, vector<int>(K + 1, INF));
    dp[src][0] = 0;
    for (int k = 1; k <= K; k++)
    {
        for (int i = 0; i < n; i++)
            dp[i][k] = dp[i][k - 1];
        for (auto &e : flights)
            dp[e[1]][k] = min(dp[e[1]][k], dp[e[0]][k - 1] + e[2]);
    }
    return dp[dst][K] != INF ? dp[dst][K] : -1;
}

int findCheapestPrice_03(int n, vector<vector<int>> &flights, int src, int dst, int K)
{
    int INF = 1e8;
    vector<int> dp(n, INF);
    dp[src] = 0;
    for (int k = 0; k <= K; k++)
    {
        vector<int> dp2(dp);
        for (auto &e : flights)
            dp2[e[1]] = min(dp2[e[1]], dp[e[0]] + e[2]);

        dp = dp2;
    }
    return dp[dst] != INF ? dp[dst] : -1;
}
