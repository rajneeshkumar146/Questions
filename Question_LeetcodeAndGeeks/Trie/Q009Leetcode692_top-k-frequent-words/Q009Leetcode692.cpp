// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

struct comp
{
public:
    // according to min PQ of java "-" replace with "<" but in cpp it is bydefault max so ">".
    bool operator()(const pair<string, int> &a, const pair<string, int> &b) const
    {
        if (a.second == b.second)
            return b.first > a.first;
        else
            return a.second > b.second;
    }
};

//same as finding kth largest element just make min pq and insert all element in it.
vector<string> topKFrequent(vector<string> &words, int k)
{
    unordered_map<string, int> map;
    for (string &word : words)
        map[word]++;

    priority_queue<pair<string, int>, vector<pair<string, int>>, comp> pq;
    for (auto &key : map)
    {
        pq.push(key);
        if (pq.size() > k)
            pq.pop();
    }
    vector<string> ans(k);
    for (int i = k - 1; i >= 0; i--)
    {
        ans[i] = pq.top().first;
        pq.pop();
    }
    return ans;
}