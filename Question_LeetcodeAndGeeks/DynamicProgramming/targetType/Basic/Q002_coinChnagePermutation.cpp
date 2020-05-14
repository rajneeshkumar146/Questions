// #include <cstdlib>
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

int coinChangeRec(vi &coins, int target, vi &dp)
{
    if (target <= 0)
        return target == 0 ? 1 : 0;
    if (dp[target] != 0)
        return dp[target];

    int count = 0;
    for (int i = 0; i < coins.size(); i++)
    {
        if (target - coins[i] >= 0)
            count += coinChangeRec(coins, target - coins[i],dp);
    }

    dp[target] = count;

    return count;
}

int coinChangeDP(vector<int> &coins, int target)
{
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i < dp.size(); i++)
    {
        for (int cidx = 0; cidx < coins.size(); cidx++)
            dp[i] += i - coins[cidx] >= 0 ? dp[i - coins[cidx]] : 0;
    }

    return dp[target];
}

void solve()
{
    vi coins = {2, 3, 5};
    vi dp(51,0);

    cout << coinChangeRec(coins, 50,dp) << endl;
    cout << coinChangeDP(coins, 50) << endl;
}

int main()
{
    solve();
    return 0;
}