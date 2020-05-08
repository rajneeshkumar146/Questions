// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int palindromePartition(string s, int K)
{
    int n = s.length();
    vector<vector<int>> pdp(n, vector<int>(n, 0));    // palindrom dp which shows min changes to convert (i,j) substring into palindrome.
    vector<vector<int>> dp(K + 1, vector<int>(n, 0)); // this dp maintain min changes to convert string into k set of plaindrome string.

    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
            {
                pdp[i][j] = 0;
                continue;
            }
            pdp[i][j] = pdp[i + 1][j - 1];
            if (s[i] != s[j])
                pdp[i][j] += 1;
        }
    }

    for (int k = 0; k <= K; k++)
    {
        for (int si = 0, ei = 0; ei < s.length(); ei++) // si is fix to 0,only ei vary.
        {
            if (k <= 1)
            {
                dp[k][ei] = ((k == 0) ? 0 : pdp[0][ei]);
                continue;
            }

            if (si == ei)
            {
                dp[k][ei] = 0;
                continue;
            }

            int min_ = (ei - si) + 1; // total character in between si to ei.
            for (int cut = si + 1; cut <= ei; cut++)
                min_ = min(min_, dp[k - 1][cut - 1] + pdp[cut][ei]);

            dp[k][ei] = min_;
        }
    }

    return dp[K][s.length() - 1];
}