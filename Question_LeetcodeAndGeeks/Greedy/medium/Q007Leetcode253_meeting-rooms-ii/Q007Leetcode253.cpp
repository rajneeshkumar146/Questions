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

//using sorting.========================================================
int minMeetingRooms_01(vector<vector<int>> &intervals)
{
    if (intervals.size() <= 1)
        return intervals.size();

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
    }
    return ans;
}

//using treeMap.========================================================
int minMeetingRooms_02(vector<vector<int>> &intervals)
{
    if (intervals.size() <= 1)
        return intervals.size();

    int n = intervals.size();
    map<int, int> bst;
    for (auto &ar : intervals)
    {
        bst[ar[0]]++;
        bst[ar[1]]--;
    }

    int ans = 0, rooms = 0;
    for (auto ele : bst)
    {
        rooms += ele.second;
        ans = max(ans, rooms);
    }
    return ans;
}