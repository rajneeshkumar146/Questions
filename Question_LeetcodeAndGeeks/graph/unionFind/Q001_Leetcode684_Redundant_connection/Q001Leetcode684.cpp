// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

vi size;
vi par;

int find(int u)
{
    if (par[u] == u)
        return u;
    par[u] = find(par[u]);
    return par[u];
}

void merge(int u, int v)
{
    if (size[u] < size[v])
    {
        par[u] = par[v];
        size[v] += size[u];
    }
    else
    {
        par[v] = par[u];
        size[u] += size[v];
    }
}

vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    for (int i = 0; i <= edges.size(); i++)
    {
        par.push_back(i);
        size.push_back(1);
    }

    vector<int> ans(2, 0);
    for (vector<int> ar : edges)
    {
        int pt1 = find(ar[0]);
        int pt2 = find(ar[1]);
        if (pt1 != pt2)
        {
            merge(pt1, pt2);
        }
        else
        {
            return {ar[0], ar[1]};
        }
    }
    return ans;
}

void solve()
{
}
int main()
{
    solve();
    return 0;
}
