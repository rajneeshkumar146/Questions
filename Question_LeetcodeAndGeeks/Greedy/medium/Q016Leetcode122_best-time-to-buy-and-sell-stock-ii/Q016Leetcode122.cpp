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

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int ans = 0;
    int minSF = 1e8;
    int maxSF = 0;

    int i = 0;
    while (i < n)
    {
        while (i < n && prices[i] < minSF)
            minSF = prices[i++];

        maxSF = minSF;
        while (i < n && prices[i] >= maxSF)
            maxSF = prices[i++];

        ans += maxSF - minSF;
        minSF = 1e8;
        maxSF = 0;
    }

    return ans;
}