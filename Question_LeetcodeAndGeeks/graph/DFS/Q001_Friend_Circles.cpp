// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

void dfs(int src, vector<bool> &vis, vector<vector<int>> &M)
{

    vis[src] = true;

    for (int i = 0; i < M[src].size(); i++)
    {
        if (src != i && M[src][i] == 1 && !vis[i])
        {
            dfs(i, vis, M);
        }
    }
}

int findCircleNum(vector<vector<int>> &M)
{
    vector<bool> vis(M.size(), false);
    int count = 0;
    for (int i = 0; i < M.size(); i++)
    {
        if (!vis[i])
        {
            count++;
            dfs(i, vis, M);
        }
    }

    return count;
}

//=======================================================

vector<int> par;
vector<int> size;

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
        par[u] = v;
        size[v] += size[u];
    }
    else
    {
        par[v] = u;
        size[u] += size[v];
    }
}

int findCircleNum_(vector<vector<int>> &M)
{
    int n = M.size();
    for (int i = 0; i < n; i++)
    {
        par.push_back(i);
        size.push_back(1);
    }

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (r != c && M[r][c] != 0)
            {
                int p1 = find(r);
                int p2 = find(c);

                if (p1 != p2)
                {
                    merge(p1, p2);
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (par[i] == i)
            ++count;
    }

    return count;
}

void solve()
{
}
int main()
{
    solve();
    return 0;
}
