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

    if (dp[sidx] != 0)
        return dp[sidx];

    int len = 1;
    int recAns = 0;
    if (prev < nums[sidx])
        recAns = 1 + LISRec_Sub(nums, sidx + 1, nums[sidx], dp, ans + to_string(nums[sidx]) + " ");

    int recExclude = LISRec_Sub(nums, sidx + 1, prev, dp, ans);

    len = max(recExclude, recAns);

    return dp[sidx] = len;
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

void solve()
{
    // vector<int> nums = {10, 22, 9, 33, 1, 50, 41, 60, 80, 1};
    // vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> nums = {-2, -1};
    // vector<int> nums = {4, 10, 4, 3, 8, 9};

    recursion(nums);
}

int main(int args, char **argv)
{
    // int t;
    // cin >> t;
    // while (t-- > 0)
    solve();
}