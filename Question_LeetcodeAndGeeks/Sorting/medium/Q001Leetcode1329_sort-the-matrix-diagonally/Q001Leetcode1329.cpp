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

vector<vector<int>> diagonalSort(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();

    unordered_map<int, vector<int>> map;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            map[i - j].push_back(arr[i][j]);
        }
    }

    for (auto &a : map)
        sort(a.second.begin(), a.second.end());

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            arr[i][j]=map[i - j].back();
            map[i - j].pop_back();
        }
    }

    return arr;
}