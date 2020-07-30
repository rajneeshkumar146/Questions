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
        res = res || targetSum_01(nums, tar - nums[idx], idx + 1) == 1;
    res = res || targetSum_01(nums, tar, idx + 1) == 1;

    return dp[idx][tar] = res;
}

//1D_DP.==============================================================================
// int targetSum_02_1dDP(vector<int> &nums, int tar)
// {
// }

bool canPartitionKSubsets(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n < k)
        return false;
    if (k == 1)
        return true;
        
    int sum = 0;
    for (int ele : nums)
        sum += ele;

    if (sum % k != 0)
        return false;

    sum = sum / k;

    dp.resize(nums.size() + 1, vector<int>(sum + 1, -1));
    return targetSum_01(nums, sum, 0) > 0;
}