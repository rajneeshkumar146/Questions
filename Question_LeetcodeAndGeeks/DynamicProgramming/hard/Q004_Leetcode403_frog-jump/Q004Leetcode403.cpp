// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool canCross_Rec(vector<int> &arr, int si, int k, vector<vector<int>> &dp)
{
    if (si == arr.size() - 1)
        return dp[si][k] = 1;
    if (dp[si][k] >= 0)
        return dp[si][k];

    for (int idx = si + 1; idx < arr.size(); idx++)
    {
        int gap = arr[idx] - arr[si];
        if (gap >= k - 1 && gap <= k + 1)
        {
            dp[si][k] = (canCross_Rec(arr, idx, gap, dp) == 1);
            if (dp[si][k] == 1)
                break;
        }
    }

    return dp[si][k] == 1;
}

bool canCross_DP(vector<int> &arr)
{
    vector<vector<bool>> dp(arr.size() + 1, vector<bool>(arr.size() + 1, false));
    
    dp[0][1]=true;
    for (int si = 1; si < arr.size(); si++)
    {
        for (int idx = 0; idx < si; idx++)
        {
            int gap = arr[idx] - arr[si];
            if (gap >=  && gap <= k + 1)
            {
                k = gap;
                dp[si][k] = dp[idx][gap];   
                if (dp[si][k])
                    break;
            }
        }
    }

    return dp[0];
}

bool canCross(vector<int> &arr)
{
    if (arr.size() <= 1)
        return true;
    vector<vector<int>> dp(arr.size() + 1, vector<int>(arr.size() + 1, -1));
    return canCross_(arr, 0, 0, dp) == 1;
}