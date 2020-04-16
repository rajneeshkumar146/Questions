#include <iostream>
#include <vector>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

vi par;

int findPar(int u)
{
    if (par[u] == 0)
        return 0;
    if (par[u] == u)
        return u;

    return par[u] = findPar(par[u]);
}

int regionsBySlashes(vector<string> &grid)
{
    if (grid.empty())
        return 0;

    int n = grid.size();
    int m = n + 1;
    par.resize(m * m, 0);
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int p = j + i * m;
            par[p] = p;
        }
    }
    int count = 1;

    for (int i = 0; i < n; i++)
    {
        string &s = grid[i];
        for (int j = 0; j < s.length(); j++)
        {
            char ch = s[j];
            if (ch == '/')
            {
                int p1 = findPar((j + 1) + i * m);
                int p2 = findPar(j + (i + 1) * m);
                if (p1 == p2)
                    count++;
                else
                {
                    par[p1] = min(p1, p2);
                    par[p2] = min(p1, p2);
                }
            }
            else if (ch == '\\')
            {

                int p1 = findPar(j + i * m);
                int p2 = findPar((j + 1) + (i + 1) * m);
                if (p1 == p2)
                    count++;
                else
                {
                    par[p1] = min(p1, p2);
                    par[p2] = min(p1, p2);
                }
            }
        }
    }

    return count;
}
