// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

string frequencySort(string s)
{
    unordered_map<int, int> map;
    for (char ch : s)
        map[ch]++;
    priority_queue<pair<int, char>> pq;
    for (auto p : map)
        pq.push({p.second, p.first});

    string ans = "";
    while (!pq.empty())
    {
        auto rvtx = pq.top();
        pq.pop();
        for (int i = 0; i < rvtx.first; i++)
            ans += rvtx.second;
    }
    return ans;
}