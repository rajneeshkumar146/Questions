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

int maxLen(int arr[], int N)
{
    if (N == 0)
        return 0;

    unordered_map<int, int> map;
    map[0] = -1;
    int sum = 0;
    int len = 0;
    for (int i = 0; i < N; i++)
    {
        int val = arr[i];
        if (val == 0)
            val = -1;

        sum += val;
        if (map.find(sum) == map.end())
            map[sum] = i;
        else
            len = max(len, i - map[sum]);
    }

    return len;
}
