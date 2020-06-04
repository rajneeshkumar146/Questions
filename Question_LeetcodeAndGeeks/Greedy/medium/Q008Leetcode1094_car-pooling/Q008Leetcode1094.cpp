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

//using treeMap.========================================================
bool carPooling(vector<vector<int>>& trips, int capacity) {
    int n = trips.size();
    map<int, int> bst;
    for (auto &ar : trips)
    {
        bst[ar[1]]+=ar[0];
        bst[ar[2]]-=ar[0];
    }

    int ans = 0, rooms = 0;
    for (auto ele : bst)
    {
        rooms += ele.second;
        ans = max(ans, rooms);
        if(ans>capacity) return false;
    }
    return true;
}