#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

auto SpeedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define vi vector<int>

int numBusesToDestination(vector<vector<int>> &routes, int S, int T)
{
    if (routes.size() == 0)
        return -1;

    unordered_map<int, vector<int>> map;
    for (int i = 0; i < routes.size(); i++)
    {
        for (int ele : routes[i])
        {
            map[ele].push_back(i);
        }
    }

    unordered_set<int> vis;
    vector<bool> idxVis(routes.size(), false);

    queue<int> que;
    que.push(S);
    vis.insert(S);
    int level = 0;

    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int u = que.front();
            que.pop();

            if (u == T)
            {
                return level;
            }

            for (int idx : map[u])
            {
                if (idxVis[idx])
                    continue;
                for (int busStands : routes[idx])
                {
                    if (vis.find(busStands) == vis.end())
                    {
                        que.push(busStands);
                        vis.insert(busStands);
                    }
                }
                idxVis[idx] = true;
            }
        }
        level++;
    }

    return -1;
}
