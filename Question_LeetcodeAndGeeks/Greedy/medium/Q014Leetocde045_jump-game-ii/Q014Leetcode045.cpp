// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

static const auto magic = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

//Memoization: O(n2) solution.=========================================
int jump_memo(vector<int> &nums, int si, vector<int> &dp)
{
    if (si >= nums.size() - 1)
        return 0;

    if (dp[si] != 1e8)
        return dp[si];
    if (nums[si] == 0)
        return 1e8;

    int minJumps = 1e8;
    for (int i = 1; si + i < nums.size() && i <= nums[si]; i++)
    {
        int recAns = jump_memo(nums, si + i, dp);
        if (recAns != 1e8 && recAns + 1 < minJumps)
            minJumps = recAns + 1;
    }
    return minJumps;
}

//DP: O(n2) Solution====================================================

int jump_DP(vector<int> &nums, vector<int> &dp)
{
    for (int si = nums.size() - 1; si >= 0; si--)
    {
        if (si == nums.size() - 1)
        {
            dp[si] = 0;
            continue;
        }
        if (nums[si] == 0)
            continue;

        int minJumps = 1e8;
        for (int i = 1; si + i < nums.size() && i <= nums[si]; i++)
        {
            int recAns = dp[si + i];
            if (recAns != 1e8 && recAns + 1 < minJumps)
                minJumps = recAns + 1;
        }
        dp[si] = minJumps;
    }
    return dp[0];
}

//Greedy: O(n) Solution.================================================
//DP: O(n2) Solution====================================================
int jump_greedy(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    int maxPossibleJump = 0;
    int currEnd = 0;

    for (int i = 0; i < n - 1; i++)
    {
        maxPossibleJump = max(maxPossibleJump, i + nums[i]);
        if (i == currEnd)
        {
            currEnd = maxPossibleJump;
            count++;
        }
    }

    return count;
}

int jump(vector<int> &nums)
{
    vector<int> dp(nums.size(), 1e8);
    // return jump_memo(nums, 0, dp);
    // return jump_DP(nums, dp);
    return jump_greedy(nums);
}
