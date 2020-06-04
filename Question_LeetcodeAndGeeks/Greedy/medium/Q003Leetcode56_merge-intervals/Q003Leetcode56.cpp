// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

vector<vector<int>> merge(vector<vector<int>> &arr)
{
    if (arr.size() <= 1)
        return arr;

    sort(arr.begin(), arr.end(), [](auto const &a, auto const &b) {
        return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
    });

    vector<vector<int>> res;
    res.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++)
    {
        if (res.back()[1] < arr[i][0])
            res.push_back(arr[i]);
        else
            res.back()[1] = max(res.back()[1], arr[i][1]);
    }

    return res;
}