// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

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
    int maxSF = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        maxSF = max(maxSF, prices[i]);     // max possible price jispe bech skte ho.
        ans = max(ans, maxSF - prices[i]); // har price pe khareed ke dekho max profit beat hoga ya nahi.
    }

    return ans;
}