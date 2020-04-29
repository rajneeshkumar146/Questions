// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int longestArithSeqLength(vector<int> &arr)
{
    int n = arr.size();
    if (n <= 2)
        return n;

    vector<unordered_map<int, int>> dp(n, unordered_map<int, int>());
    int maxLen = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = arr[i] - arr[j];
            int maxLenIncludingMe = dp[j].count(diff) ? dp[j][diff] + 1 : 2; // atleast it will be length of 2.
            int anyLenEndingToMe = dp[i].count(diff) ? dp[i][diff] : 0;

            dp[i][diff] = max(maxLenIncludingMe, dp[i][diff]);
            maxLen = max(maxLen, dp[i][diff]);
        }
    }

    return maxLen;
}