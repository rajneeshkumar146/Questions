#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//recursion.=========================================

int LISRecursion(vector<int> &nums, int eidx, int &max_, vector<int> &dp)
{
    if (eidx == 0)
        return 1;

    if (dp[eidx] != 0)
        return dp[eidx];
    int currLongestLIS = 1;
    for (int i = 0; i < eidx; i++)
    {
        int recLongestLIS = LISRecursion(nums, i, max_, dp);
        if (nums[i] < nums[eidx] && recLongestLIS + 1 > currLongestLIS)
            currLongestLIS = recLongestLIS + 1;
    }
    dp[eidx] = currLongestLIS;
    max_ = max(max_, currLongestLIS);
    return currLongestLIS;
}

int LISRec_Sub(vector<int> &nums, int sidx, int prev, vector<int> &dp, string ans)
{
    if (sidx == nums.size())
    {
        // cout << ans << endl;
        return 0;
    }

    // if (dp[sidx] != 0)
    //     return dp[sidx];

    int len = 1;
    int recAns = 0;
    if (prev < nums[sidx])
        recAns = 1 + LISRec_Sub(nums, sidx + 1, nums[sidx], dp, ans + to_string(nums[sidx]) + " ");

    int recExclude = LISRec_Sub(nums, sidx + 1, prev, dp, ans);

    len = max(recExclude, recAns);

    // dp[sidx] = len;
    return len;
}

void recursion(vector<int> &nums)
{
    if (nums.size() == 0)
        cout << 0 << endl;

    int max_ = 1;
    vector<int> dp(nums.size(), 0);

    LISRecursion(nums, nums.size() - 1, max_, dp);
    cout << max_ << endl;

    cout << LISRec_Sub(nums, 0, -1e6, dp, "") << endl;
}

//Dp. of LIS and LDS==================================================

int lengthOfLIS(vector<int> &nums)
{

    vector<int> dp(nums.size() - 1, 0);

    int max_ = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] < nums[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
        max_ = max(max_, dp[i]);
    }
    return max_;
}

int lengthOfLDS(vector<int> &nums)
{

    vector<int> dp(nums.size(), 0);
    int max_ = 0;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        dp[i] = 1;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }

        max_ = max(max_, dp[i]);
    }

    return max_;
}

//Binary Search Log(n) solution.================================

int lengthOfLIS(vector<int> &arr)
{
    if (arr.empty())
        return 0;

    vector<int> list;
    for (int i = 0; i < arr.size(); i++)
    {
        int val = arr[i];
        int li = 0;
        int ri = list.size();

        while (li < ri)
        {
            int mid = li + (ri - li) / 2;
            if (list[mid] < val)
                li = mid + 1;
            else
                ri = mid;
        }

        if (list.size() != ri)
            list[ri] = val;
        else
            list.push_back(val);
    }

    return list.size();
}
}

void LIS_logn(vector<int> &nums)
{
    lengthOfLIS(nums);
}

void dp(vector<int> &nums)
{
    // cout << lengthOfLIS(nums) << endl;
    // cout << lengthOfLDS(nums) << endl;
}

void solve()
{
    // vector<int> nums = {10, 22, 9, 33, 1, 50, 41, 60, 80, 1};
    // vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> nums = {-2, -1};
    // vector<int> nums = {4, 10, 4, 3, 8, 9};

    recursion(nums);
    dp(nums);
}

int main(int args, char **argv)
{
    // int t;
    // cin >> t;
    // while (t-- > 0)
    solve();
}