#include <iostream>
#include <vector>
using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

vector<int> par, unionParent;
int findPar(int u)
{
    return (unionParent[u] == -1 ? u : unionParent[u] = findPar(unionParent[u]));
}

//e1 and e2 are edges to represent redundant edge.
vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
{
    int n = edges.size();
    int e1 = -1, e2 = -1, circleEdge = -1;
    par.resize(n + 1, -1);
    unionParent.resize(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        auto &e = edges[i];
        int p = e[0]; //parent
        int c = e[1]; //child

        if (par[c] != -1) //agar mere child ko phele se parent assign tha.
        {
            e1 = par[c];
            e2 = i;
            continue;
        }

        par[c] = i;
        int op = findPar(p); // cycle detection ke liye.

        if (op == c)
            circleEdge = i;
        else
            unionParent[c] = op;
    }

    if (circleEdge == -1)
        return edges[e2];
    else if (e2 == -1)
        return edges[circleEdge];
    return edges[e1];
}