#include <iostream>
#include <vector>

using namespace std;

//Time: O(n^2)===========================================================

int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size();
    if (n <= 1)
        return n;

    int dp[n];
    int count[n];

    int maxLen = 0;
    int rans = 0;

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        count[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }
                else if (dp[j] + 1 == dp[i])
                    count[i] += count[j];
            }
        }

        if (maxLen < dp[i])
        {
            maxLen = dp[i];
            rans = count[i];
        }
        else if (maxLen == dp[i])
            rans += count[i];
    }

    return rans;
}

//Time: O(nlong)===========================================================



void solve()
{
    vector<int> arr = {1, 2};
    cout << findNumberOfLIS(arr) << endl;
}

int main()
{
    solve();
}