#include <iostream>
#include <queue>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

int n;
vector<int> childCount;
vector<int> ans;
vector<vector<int>> graph;

void dfs_forPreperation(int u)
{
    for (const auto &v : graph[u])
    {
        dfs_forPreperation(v);
        childCount[u] += childCount[v];
        ans[v] += ans[u] + childCount[u];
    }
}

void dfs_forResult(int u)
{
    for (const auto &v : graph[u])
    {
        ans[v] = ans[u] - childCount[v] - n - childCount[v];
        dfs_forResult(v);
    }
}

vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges)
{
    graph.clear();
    childCount.clear();
    ans.clear();
    n = N;

    childCount(N, 1);
    ans.count(N, 0);
    graph.resize(N, vector<int>());

    for (const auto &e : edges)
    {
        graph[edges[0]].push_back(edges[1]);
    }

    dfs_forPreperation(0);
    dfs_forResult(0);

    return ans;
}
