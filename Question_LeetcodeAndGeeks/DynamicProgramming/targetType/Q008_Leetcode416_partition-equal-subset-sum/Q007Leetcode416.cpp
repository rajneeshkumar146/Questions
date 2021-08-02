// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


//2D_DP=================================================================================
int targetSum_01(vector<int> &nums, int tar, int idx,vector<vector<int>>& dp)
{
    if (idx == nums.size() || tar == 0)
        return dp[idx][tar] = tar == 0;
    if (dp[idx][tar] != -1)
        return dp[idx][tar];

    bool res = false;
    if (tar - nums[idx] >= 0)
        res = res || targetSum(nums, tar - nums[idx], idx + 1,dp) == 1;
    res = res || targetSum(nums, tar, idx + 1,dp) == 1;

    return dp[idx][tar] = res;
}

//1D_DP.==============================================================================
int targetSum_02(vector<int> &nums, int tar, int idx)
{
    if (idx == nums.size() || tar == 0)
        return dp[idx][tar] = tar == 0;
    if (dp[idx][tar] != -1)
        return dp[idx][tar];

    bool res = false;
    for (int i = idx; i < nums.size() && !res; i++)
    {
        if (tar - nums[idx] >= 0)
            res = targetSum_02(nums, tar - nums[i], i + 1) == 1;
    }

    return dp[idx][tar] = res;
}

bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int ele : nums)
        sum += ele;
    dp.resize(nums.size() + 1, vector<int>(sum / 2 + 2, -1));
    return !(sum & 1) && targetSum_01(nums, sum / 2, 0) > 0;
}