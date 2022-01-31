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
    return par[u] == u ? u : (par[u] = findPar(par[u]));
}

int getMST(int n, vector<vector<int>> &edges)
{
    par.clear();
    for (int i = 0; i <= n; i++)
        par.push_back(i);

    int res = 0;
    sort(edges.begin(), edges.end(), [](auto &a, auto &b)
         { return a[2] < b[2]; });

    for (int i = 0; i < edges.size(); i++)
    {
        vector<int> &e = edges[i];
        int p1 = findPar(e[0]), p2 = findPar(e[1]);
        if (p1 != p2)
        {
            par[p1] = p2;
            res += e[2];
        }
    }

    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (findPar(i) == i && ++count > 1)
            return -1;
    }

    return res;
}

int minimumCost(int n, vector<vector<int>> &connections)
{
    return getMST(n, connections);
}