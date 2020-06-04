#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

static const auto magic = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

vii tree;
vi parent, depth, blockPar;
int height, bs;

void dfs(int src, int d, int par)
{
    parent[src] = par;
    depth[src] = d;

    height = max(height, d);
    for (int ch : tree[src])
        dfs(ch, d + 1, src);
}

void dfs2(int src, int d, int par)
{

    if (depth[src] % bs == 0)
        blockPar[src] = parent[src];
    else
        blockPar[src] = blockPar[par];

    for (int ch : tree[src])
        dfs2(ch, d + 1, src);
}

int LCA(int u, int v)
{
    while (blockPar[u] != blockPar[v])
    {
        if (u > v)
            swap(u, v);
        v = blockPar[v];
    }

    while (u != v)
    {
        if (depth[u] > depth[v])
            swap(u, v);
        v = parent[v];
    }
    return u;
}

void solve()
{
    int n;
    cin >> n;

    tree.resize(n + 2, vector<int>());
    parent.resize(n + 2, 0);
    depth.resize(n + 2, 0);

    for (int i = 1; i <= n; i++)
    {
        int par, ch;
        cin >> par >> ch;
        tree[par].push_back(ch);
    }

    dfs(1, 0, 0);

    bs = (int)sqrt(height) + 1;
    blockPar.resize(bs + 2, 0);

    dfs2(1, 1, 0);

    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << endl;
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}