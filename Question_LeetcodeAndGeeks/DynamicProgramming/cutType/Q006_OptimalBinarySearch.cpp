// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <climits>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

void prefixSum(vi &arr, vi &sum)
{
    for (int i = 0; i < arr.size(); i++)
    {
        sum[i] = (i == 0 ? 0 : sum[i - 1]) + arr[i];
    }
}

int OBS_rec(vi &arr, vi &sum, int i, int j, vii &dp)
{
    if (i == j)
        return (sum[i] - (i == 0 ? 0 : sum[i - 1]));

    if (dp[i][j] != 0)
        return dp[i][j];

    int min_ = INT_MAX;
    for (int cut = i; cut <= j; cut++)
    {
        int leftTree = cut == i ? 0 : OBS_rec(arr, sum, i, cut - 1, dp);
        int rightTree = cut == j ? 0 : OBS_rec(arr, sum, cut + 1, j, dp);

        int cost = leftTree + (sum[j] - (i == 0 ? 0 : sum[i - 1])) + rightTree;
        min_ = min(min_, cost);
    }

    dp[i][j] = min_;
    return min_;
}

int OBS_DP(vi &arr, vi &sum)
{
    vii dp(arr.size(), vi(arr.size(), 0));
    for (int gap = 0; gap < arr.size(); gap++)
    {
        for (int i = 0, j = gap; j < arr.size(); i++, j++)
        {
            dp[i][j] = INT_MAX;
            for (int cut = i; cut <= j; cut++)
            {
                int leftTree = cut == i ? 0 : dp[i][cut - 1];
                int rightTree = cut == j ? 0 : dp[cut + 1][j];
                int cost = leftTree + (sum[j] - (i == 0 ? 0 : sum[i - 1])) + rightTree;
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[0][arr.size() - 1];
}

void solve()
{
    vi arr = {10, 12, 20};
    vi freq = {34, 8, 50};
    vi sum(arr.size(), 0);

    prefixSum(freq, sum);
    vii dp(arr.size(), vi(arr.size(), 0));

    cout << OBS_rec(arr, sum, 0, arr.size() - 1, dp) << endl;
    cout << OBS_DP(arr, sum) << endl;
}

int main(int args, char **argv)
{
    // int t;
    // cin >> t;
    // while (t-- > 0)
    solve();
    return 0;
}
