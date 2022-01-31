// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

vector<int> par;
int findPar(int u)
{
    return par[u] == u ? u : par[u] = findPar(par[u]);
}

int getMST(int n, vector<vector<int>> &edges, int delEdge, int addEdge)
{
    par.clear();
    for (int i = 0; i < n; i++)
        par.push_back(i);

    int res = 0;
    if (addEdge != -1)
    {
        vector<int> e = edges[addEdge];
        par[e[0]] = e[1];
        res += e[2];
    }

    for (int i = 0; i < edges.size(); i++)
    {
        vector<int> e = edges[i];
        if (i == delEdge || i == addEdge)
            continue;
        int p1 = findPar(e[0]), p2 = findPar(e[1]);
        if (p1 != p2)
        {
            par[p1] = p2;
            res += e[2];
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (findPar(i) == i && ++count > 1)
            return 1e9;
    }

    return res;
}

vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
        edges[i].push_back(i);

    sort(edges.begin(), edges.end(), [](auto &a, auto &b)
         { return a[2] < b[2]; });

    int mstWeight = getMST(n, edges, -1, -1);

    vector<int> psuedo_Edge, critical_Edge;
    for (int i = 0; i < edges.size(); i++)
    {
        int weight = getMST(n, edges, i, -1);
        if (weight > mstWeight)
        {
            critical_Edge.push_back(edges[i][3]);
        }
        else if (getMST(n, edges, -1, i) == mstWeight)
        {

            psuedo_Edge.push_back(edges[i][3]);
        }
    }

    return {critical_Edge, psuedo_Edge};
}