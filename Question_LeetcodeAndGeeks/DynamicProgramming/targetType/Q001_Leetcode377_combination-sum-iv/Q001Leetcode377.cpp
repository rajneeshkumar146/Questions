// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


int combinationSum4(vector<int>& coins, int target) {        
    vector<unsigned int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i < dp.size(); i++)
    {
        for (int cidx = 0; cidx < coins.size(); cidx++)
            dp[i] += i - coins[cidx] >= 0 ? dp[i - coins[cidx]] : 0;
    }

    return dp[target];

    }