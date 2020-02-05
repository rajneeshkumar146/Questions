// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <climits>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

vi *prefixSum(vi &arr)
{
    vector<int> *sum = new vector<int>(arr.size() + 1, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        (*sum)[i + 1] = (*sum)[i] + arr[i];
    }
    return sum;
}

int painterPartition(vi &arr, int n, int k, vi &sum, vii &dp)
{

    if (n == 0)
        return arr[0];
    if (k == 1)
        return sum[n + 1];

    if (dp[n][k] != 0)
        return dp[n][k];

    int min_ = INT_MAX;
    for (int i = 0; i <= n; i++)
    {
        int recAns = max(painterPartition(arr, i, k - 1, sum, dp), sum[n + 1] - sum[i + 1]);
        min_ = min(min_, recAns);
    }

    dp[n][k] = min_;
    return min_;
}

int painterPartition_dp(vi &arr, int k, vi &sum)
{
    if (arr.size() == 1)
        return arr[0];
    if (k == 1)
        return sum[arr.size()];

    vii dp(arr.size(), vector<int>(k + 1, 0));
    for (int i = 0; i < dp.size(); i++)
        dp[i][1] = sum[i + 1];
    for (int i = 1; i <= k; i++)
        dp[0][i] = arr[0];

    for (int j = 2; j <= k; j++)
    {
        for (int i = 1; i < arr.size(); i++)
        {
            int min_ = INT_MAX;
            for (int cut = 0; cut <= i; cut++)
            {
                int val = max(dp[cut][j - 1], sum[i + 1] - sum[cut + 1]);
                min_ = min(min_, val);
            }
            dp[i][j] = min_;
        }
    }

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     for (int j = 1; j <= k; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return dp[arr.size() - 1][k];
}

void solve()
{
    vi arr = {10, 20, 60, 50, 30, 40};
    int k = 3;
    vi sum = *prefixSum(arr);
    vii dp(arr.size(), vector<int>(k + 1, 0));
    cout << painterPartition(arr, arr.size() - 1, k, sum, dp) << endl;
    cout << painterPartition_dp(arr, k, sum) << endl;
}

int main(int args, char **argv)
{
    // int t;
    // cin >> t;
    // while (t-- > 0)
    solve();
    return 0;
}
