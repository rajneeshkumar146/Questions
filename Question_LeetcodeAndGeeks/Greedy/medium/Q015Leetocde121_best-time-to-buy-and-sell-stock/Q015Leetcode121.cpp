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

int maxProfit(vector<int> &arr)
{
    if (arr.size() == 0)
        return 0;

    int n = arr.size();
    int ans = 0;
    int maxVal = 0;
    for (int i = n - 1; i >= 0; i--)
    {

        maxVal = max(maxVal, arr[i]);
        ans = max(ans, maxVal - arr[i]);
    }

    return ans;
}