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

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    if (n == 0)
        return 0;
    int count = 0;
    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
        return a[1] < b[1];
    });
    int end = intervals[0][1];
    for (int i = 1; i < n; i++)
    {
        if (end <= intervals[i][0])  // non overlapping.
            end = intervals[i][1];
        else
            count++;  // overlapping.
    }
    return count;
}