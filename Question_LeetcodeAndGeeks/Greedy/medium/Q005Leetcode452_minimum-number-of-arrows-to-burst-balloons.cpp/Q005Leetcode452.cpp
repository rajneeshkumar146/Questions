// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

static const auto magic = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int findMinArrowShots(vector<vector<int>> &points)
{
    if (points.size() <= 1)
        return points.size();

    int n = points.size();
    sort(points.begin(), points.end(), [](auto &a, auto &b) {
        return a[1] < b[1];
    });
    int end = points[0][1], count = 1;
    for (int i = 1; i < n; i++)
    {
        if (end < points[i][0])
        {
            count++;
            end = points[i][1];
        }
    }

    return count;
}