// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int findTargetSumWays_Rec(vector<int> &nums, int n, int sum, int tar)
{
    if (n == 0)
        return ((tar == sum) ? 1 : 0);

    int include = findTargetSumWays_Rec(nums, n - 1, sum - nums[n - 1], tar);
    int exclude = findTargetSumWays_Rec(nums, n - 1, sum + nums[n - 1], tar);

    return include + exclude;
}

int findTargetSumWays_memo(vector<int> &nums, int n, int sum, int tar, vector<vector<int>> &dp)
{
    if (n == 0)
        return dp[n][sum] = ((tar == sum) ? 1 : 0);

    if (dp[n][sum] != -1)
        return dp[n][sum];

    int include = findTargetSumWays_memo(nums, n - 1, sum - nums[n - 1], tar, dp);
    int exclude = findTargetSumWays_memo(nums, n - 1, sum + nums[n - 1], tar, dp);

    return dp[n][sum] = include + exclude;
}

//DP.==========================================================================================

int findTargetSumWays_DP(vector<int> &nums, int s, int sum, 
   vector<vector<int>> &dp)
{
    dp[0][0 + sum] = 1;
    for (int i = 1; i <= nums.size(); i++)
    {
        for (int k = 0; k < 2 * sum + 1; k++)
        {
            if (dp[i - 1][k] != 0)
            {
                dp[i][k + nums[i - 1]] += dp[i - 1][k];
                dp[i][k - nums[i - 1]] += dp[i - 1][k];
            }
        }
    }
    return dp[nums.size()][sum + s];
}

int findTargetSumWays_DP02(vector<int> &nums, int s, int sum)
{
    vector<int> dp(2 * sum + 1, 0);
    vector<int> next(2 * sum + 1, 0);

    dp[0 + sum] = 1;
    for (int i = 1; i <= nums.size(); i++)
    {
        next.clear();
        next.resize(2 * sum + 1, 0);
        for (int k = 0; k < 2 * sum + 1; k++)
        {
            if (dp[k] != 0)
            {
                next[k + nums[i - 1]] += dp[k];
                next[k - nums[i - 1]] += dp[k];
            }
        }
        dp = next;
    }
    return dp[sum + s];
}

int findTargetSumWays(vector<int> &nums, int s)
{
    if (nums.size() == 0)
        return 0;

    int n = nums.size();
    int sum = 0;

    for (int i : nums)
        sum += i;
    if (s > sum || s < -sum)
        return 0;

    vector<vector<int>> dp(nums.size() + 1, vector<int>(2 * sum + 1, -1));

    // return findTargetSumWays_Rec(nums, n, 0, s);
    return findTargetSumWays_memo(nums, n, sum, s + sum, dp);

    // return findTargetSumWays_DP(nums, s,sum,dp);
    // return findTargetSumWays_DP02(nums, s,sum);
}