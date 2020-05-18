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

unordered_map<string, string> parent;
unordered_map<string, string> name;

string findPar(string &u)
{
    if (parent[u] == u)
        return u;
    return parent[u] = findPar(parent[u]);
}

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{

    for (vector<string> &acc : accounts)
    {
        for (int i = 1; i < acc.size(); i++)
        {
            string &email = acc[i];
            parent[email] = email;
            name[email] = acc[0];
        }
    }

    for (vector<string> &acc : accounts)
    {
        string p1 = findPar(acc[1]);
        for (int i = 2; i < acc.size(); i++)
        {
            string p2 = findPar(acc[i]);
            parent[p2] = p1;
        }
    }

    unordered_map<string, set<string>> res;
    for (auto s : parent)
    {
        if (s.first == s.second)
        {
            res[s.first].insert(name[s.first]);
        }
    }

    for (auto s : parent)
        res[findPar(s.second)].insert(s.first);

    vector<vector<string>> ans;
    for (auto s : res)
    {
        vector<string> temp(s.second.begin(), s.second.end());
        ans.push_back(temp);
    }

    return ans;
}