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
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int countEqualSubarrays(vector<int> &arr)
{
    if (arr.size() == 0)
        return 0;

    unordered_map<int, int> map;
    map[0] = 1;
    int sum = 0;
    for (int ele : arr)
    {
        int val = ele;
        if (val == 0)
            val = -1;

        sum += val;
        map[sum]++;
    }

    int count = 0;
    for (auto p : map)
    {
        count += (p.second * (p.second - 1)) / 2;
    }

    return count;
}