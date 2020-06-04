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

bool canAttendMeetings(vector<vector<int>> &intervals)
{
    if (intervals.size() <= 1)
        return true;

    int n = intervals.size();
    vector<int> start;
    vector<int> end;
    for (auto &ar : intervals)
    {
        start.push_back(ar[0]);
        end.push_back(ar[1]);
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int count = 0, i = 0, j = 0, ans = 0;
    while (i < n && j < n)
    {
        if (start[i] < end[j])
            count++, i++;
        else
            count--, j++;

        ans = max(ans, count);
        if (ans > 1)
            break;
    }
    return ans <= 1;
}