#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Edge
{
public:
    int v = 0;
    int w = 0;

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

int bfs2(vector<vector<Edge *>> &graph, int src, int dest)
{
    int n = graph.size();
    queue<pair<int, int>> que;
    vector<bool> vis(n, false);
    que.push({src, 0});

    bool isDest = false;
    int weight = 1e9 + 7;
    int level = 0;
    int l = 0;

    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            pair<int, int> rvtx = que.front();
            que.pop();

            if (vis[rvtx.first])
                continue;

            if (rvtx.first == dest && level == l)
            {
                isDest = true;
                weight = min(weight, rvtx.second);
            }

            vis[rvtx.first] = true;
            for (Edge *e : graph[rvtx.first])
                if (!vis[e->v])
                    que.push({e->v, rvtx.second + e->w});
        }
        l++;
        is(!isDest) level++;
    }

    return weight;
}

int getDirectedPath(int n, vector<int> &E, int s, int d)
{
    vector<vector<Edge *>> graph(n, vector<Edge *>());
    for (int i = 0; i < E.size(); i += 3)
    {
        int u = E[i];
        int v = E[i + 1];
        int w = E[i + 2];
        graph[u].push_back(new Edge(v, w));
    }

    return bfs2(graph, s, d);
}

int main()
{
    cout << min(-4, -5) << endl;
    return 0;
}
