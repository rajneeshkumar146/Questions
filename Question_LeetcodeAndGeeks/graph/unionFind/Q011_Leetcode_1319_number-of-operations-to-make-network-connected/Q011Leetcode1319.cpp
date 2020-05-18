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

vector<int> par;
int findPar(int u)
{
    return par[u] == u ? u : par[u] = findPar(par[u]);
}

int makeConnected(int n, vector<vector<int>> &connections)
{
    if (connections.size() < n - 1)
        return -1;

    for (int i = 0; i < n; i++)
        par.push_back(i);

    int leader = n;
    for (auto &ar : connections)
    {
        int p1 = findPar(ar[0]);
        int p2 = findPar(ar[1]);
        if (p1 != p2)
        {
            par[p1] = p2;
            leader--;
        }
    }

    return leader - 1;
}