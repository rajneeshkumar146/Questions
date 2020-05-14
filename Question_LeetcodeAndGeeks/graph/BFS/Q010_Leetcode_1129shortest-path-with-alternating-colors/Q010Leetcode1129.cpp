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

   vector<vector<pair<int, int>>> graph;
vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &red_edges, vector<vector<int>> &blue_edges)
{
    graph.resize(n, vector<pair<int, int>>());
    for (vector<int> &e : red_edges)
        graph[e[0]].push_back({e[1], 0});
    for (vector<int> &e : blue_edges)
        graph[e[0]].push_back({e[1], 1});

    queue<pair<int, int>> que;
    que.push({0, 0});
    que.push({0, 1});

    vector<int> dis(n, -1);
    int d=0;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            pair<int, int> rvtx = que.front();
            que.pop();
            
            dis[rvtx.first]=d;
            for(pair<int,int>& e: graph[rvtx.first])
                if(e.second==(rvtx.second+1)%2 && dis[e.first]==-1)
                   que.push({e.first,e.second});
        }
        d++;
    }

    return dis;
}