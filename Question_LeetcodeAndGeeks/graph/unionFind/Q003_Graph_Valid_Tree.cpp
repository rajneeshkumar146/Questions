#include <iostream>
using namespace std;

// Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes),
// write a function to check whether these edges make up a valid tree.
// Example 1:

// Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
// Output: true

// Example 2:

// Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
// Output: false
//====================================================================

// 1. if it is a tree then after path compression all node should have a common parent.
//    1.1. so we traverse each edge one by one and put into parent array.
//         if two nodes having same parent come as a edge then it is a cycle in tree. 

int par[100000];
int find(int u)
{
    if (par[u] == u)
        return u;

    par[u] = find(par[u]);
    return par[u];
}

bool validTree(int n, vector<vector<int>> &edges)
{
    if (n == 0)
        return false;

    for (int i = 0; i < n; i++)
        par[i] = i;

    for (vector<int> e : edges)
    {
        int u = e[0];
        int v = e[1];

        int p1 = find(u);
        int p2 = find(v);

        if (p1 != p2)
            par[p2] = p1;
        else
            return false;
    }

    int c = 0;
    for (int i = 0; i < n; i++)
        if (par[i] == i)
            c++;

    return c == 1 ? true : false;
}

int main()
{
    return 0;
}