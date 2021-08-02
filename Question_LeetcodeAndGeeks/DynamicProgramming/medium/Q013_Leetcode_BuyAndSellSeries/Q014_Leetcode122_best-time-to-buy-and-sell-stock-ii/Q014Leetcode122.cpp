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
    int minSF = 1e8;
    for (int i = 0; i < n; i++)
    {
        minSF = min(minSF, prices[i]); // min possible price jispe khareed skte ho.
        if (prices[i] - minSF > 0)     // har price pe bechne ki korsis krte hai and profit mein add krenge.
        {
            ans += prices[i] - minSF;
            minSF = prices[i];
        }
    }

    return ans;
}