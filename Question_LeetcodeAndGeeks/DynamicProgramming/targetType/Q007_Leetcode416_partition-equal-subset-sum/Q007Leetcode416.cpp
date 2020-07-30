// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Recursive=================================================================================
vector<vector<int>> dp;
int targetSum_01(vector<int> &nums, int tar, int idx)
{
    if (idx == nums.size() || tar == 0)
        return dp[idx][tar] = tar == 0;
    if (dp[idx][tar] != -1)
        return dp[idx][tar];

    bool res = false;
    if (tar - nums[idx] >= 0)
        res = res || targetSum(nums, tar - nums[idx], idx + 1) == 1;
    res = res || targetSum(nums, tar, idx + 1) == 1;

    return dp[idx][tar] = res;
}

//1D_DP.==============================================================================
int targetSum_02_1dDP(vector<int> &nums, int tar)
{
    vector<bool> dp(tar + 1, 0);
    dp[0] = true;
    for (int ele : nums)
    {
        for (int t = tar; t >= ele; t--)
        {
            if (t - ele >= 0)
                dp[t] = dp[t] || dp[t - ele];
        }
    }
    return dp[tar];
}

bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int ele : nums)
        sum += ele;

    dp.resize(nums.size() + 1, vector<int>(sum / 2 + 1, -1));
    return !(sum & 1) && targetSum_01(nums, sum / 2, 0) > 0;

    return !(sum & 1) && targetSum_02_1dDP(nums, (sum >> 1));
}