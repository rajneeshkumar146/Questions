// #include <cstdlib>
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

//similar to find the min height of tree.
int minCoins(vector<int> &arr, int idx, int tar, vector<int> &dp)
{
    if (tar == 0)
        return 0;

    if (dp[tar] != 0)
        return dp[tar];
    int minCoin = 1e8;
    for (int i = 0; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
        {
            int rec = minCoins(arr, i, tar - arr[i], dp);
            if (rec >= 0 && rec < minCoin)
                minCoin = rec + 1;
        }
    }

    dp[tar] = minCoin == 1e8 ? -1 : minCoin;
    return dp[tar];
}

int minCoins(vector<int> &arr, int tar)
{
    vector<int> dp(tar + 1, 1e8);
    dp[0] = 0;
    for (int t = 1; t <= tar; t++)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (t - arr[i] >= 0)
                dp[t] = min(dp[t], dp[t - arr[i]] + 1);
        }
    }

    return dp[tar] == 1e8 ? -1 : dp[tar];
}

void solve()
{

    if (arr.size() == 0 || tar <= 0)
        return 0;

    vector<int> dp(tar + 1, 0);
    return minCoins(arr, 0, tar, dp);
}

int main()
{
    solve();
    return 0;
}