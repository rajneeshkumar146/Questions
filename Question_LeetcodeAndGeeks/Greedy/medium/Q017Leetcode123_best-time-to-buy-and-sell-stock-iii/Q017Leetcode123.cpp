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


// Intutive Solution.
int maxProfit(vector<int> &prices)
{
    if (prices.size() == 0)
        return 0;

    int n = prices.size();

    vector<int> maxProfitLR(n, 0);
    vector<int> maxProfitRL(n, 0);

    int minSF = prices[0];
    for (int i = 1; i < n; i++)
    {
        maxProfitLR[i] = max(maxProfitLR[i - 1], prices[i] - minSF);
        minSF = min(minSF, prices[i]);
    }

    int maxSF = prices[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        maxProfitRL[i] = max(maxProfitRL[i + 1], maxSF - prices[i]);
        maxSF = max(maxSF, prices[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, maxProfitLR[i] + maxProfitRL[i]);

    return ans;
}