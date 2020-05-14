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

vector<vector<int>> res;
vector<int> ans;

vector<vector<int>> res;
vector<int> ans;

void combine_(int n, int num, int k)
{
    if (k == 0)
    {
        res.push_back(ans);
        return;
    }

    while (num <= n)
    {
        ans.push_back(num);
        combine_(n, num + 1, k - 1);
        ans.pop_back();
        num++;
    }
}

vector<vector<int>> combine(int n, int k)
{
    combine_(n, 1, k);
    return res;
}