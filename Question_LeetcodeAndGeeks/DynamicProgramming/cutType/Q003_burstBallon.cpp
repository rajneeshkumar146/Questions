// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

int burstBallon(vi &arr, int i, int j, vii &dp)
{
    if (dp[i][j] != -1)
        return dp[i][j];

    int left = i - 1 < 0 ? 1 : arr[i - 1];
    int right = j + 1 >= arr.size() ? 1 : arr[j + 1];

    int max_ = 0;
    for (int mid = i; mid <= j; mid++)
    {
        int l = mid == i ? 0 : burstBallon(arr, i, mid - 1, dp);
        int r = mid == j ? 0 : burstBallon(arr, mid + 1, j, dp);

        int val = l + left * arr[mid] * right + r;
        max_ = max(max_, val);
    }
    dp[i][j] = max_;
    return max_;
}

int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int ans = burstBallon(nums, 0, n - 1, dp);

    return ans;
}

//=====================================================

int burstBallon_DP(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = i + gap; j < n; j++, i++)
        {
            int l = i - 1 <= -1 ? 1 : arr[i - 1];
            int r = j + 1 >= n ? 1 : arr[j + 1];

            for (int cut = i; cut <= j; cut++)
            {
                int left = cut == i ? 0 : dp[i][cut - 1];
                int right = cut == j ? 0 : dp[cut + 1][j];

                dp[i][j] = max(dp[i][j], left + l * arr[cut] * r + right);
            }
        }
    }

    return dp[0][arr.size()-1];
}

void solve()
{
    vi arr = {3, 1, 5, 8};
    cout << maxCoins(arr) << endl;
    cout<<burstBallon_DP(arr)<<endl;
}
int main()
{
    solve();
    return 0;
}
