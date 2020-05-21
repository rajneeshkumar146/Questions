#include <iostream>
#include <vector>
#include <climits>
using namespace std;

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
