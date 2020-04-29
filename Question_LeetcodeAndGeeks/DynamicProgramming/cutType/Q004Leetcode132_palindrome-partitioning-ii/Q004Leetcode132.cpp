// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <climits>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

void palidromeSubstring(string &str, vii &isPalindrome)
{
    for (int gap = 0; gap < str.length(); gap++)
    {
        for (int i = 0, j = gap; j < str.length(); j++, i++)
        {
            if (gap == 0)
                isPalindrome[i][j] = 1;
            else if (gap == 1 && str[i] == str[j])
                isPalindrome[i][j] = 1;
            else
                isPalindrome[i][j] = isPalindrome[i + 1][j - 1] && str[i] == str[j];
        }
    }
}

//O(n^3).====================================================================
int minCut_On3(int i, int j, vii &isPalindrome, vii &dp)
{
    if (isPalindrome[i][j])
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int min_ = 1000000;

    for (int cut = i; cut < j; cut++)
    {
        int left = minCut_On3(i, cut, isPalindrome, dp);
        int right = minCut_On3(cut + 1, j, isPalindrome, dp);
        min_ = min(min_, left + right + 1);
    }

    dp[i][j] = min_;
    return min_;
}

int minCut_dp_On3(string &str, vii &isPalindrome)
{
    vii dp(str.length(), vi(str.length(), -1));
    for (int gap = 1; gap < str.length(); gap++)
    {
        for (int i = 0, j = gap; j < str.length(); j++, i++)
        {
            if (isPalindrome[i][j])
            {
                dp[i][j] = 0;
                continue;
            }

            int min_ = INT_MAX;
            for (int cut = i; cut < j; cut++)
            {
                int left = dp[i][cut];
                int right = dp[cut + 1][j];

                int cost = left + right + 1;
                min_ = min(min_, cost);
            }
            dp[i][j] = min_;
        }
    }

    return dp[0][str.length() - 1];
}

//O(n^2).====================================================================

int minCut_On2(int st, int end, vector<int> &dp, vii &isPalindrome)
{
    if (st > end)
        return -1; // because ye string ke end pe ek cut lga dete hai isliye idhar hum -1 return krenge vo cut countable nahi hai.
    if (dp[st] != -1)
        return dp[st];

    int min_ = (int)1e8;
    for (int cut = st; cut <= end; cut++)
    {
        if (isPalindrome[st][cut])
        {
            int cuts_ = minCut_On2(cut + 1, end, dp, isPalindrome) + 1;
            min_ = Math.min(min_, cuts_);
        }
    }

    return dp[st] = min_;
}

int minCut_dp_On2(int st, int end, vector<int> &dp, vii &isPalindrome)
{
    for (st = end; st >= 0; st--)
    {
        int min_ = (int)1e8;
        for (int cut = st; cut <= end; cut++)
        {
            if (isPalindrome[st][cut])
            {
                int cuts_ = ((cut + 1 == end + 1) ? -1 : dp[cut + 1]) + 1;
                min_ = Math.min(min_, cuts_);
            }
        }

        dp[st] = min_;
    }
    return dp[0];
}

void solve()
{
    string str = "abccbc";
    vii isPalindrome(str.length(), vi(str.length(), 0));
    palidromeSubstring(str, isPalindrome);

    //O(n3).===============
    vii dp(str.length(), vi(str.length(), -1));
    cout << minCut_On3(0, str.length() - 1, isPalindrome, dp) << endl;
    cout << minCut_dp_On3(str, isPalindrome) << endl;

    //O(n2).================
    vi dp(str.length(), 0);
    cout << minCut_On2(0, str.length() - 1, dp, isPalindrome) << endl;
    cout << minCut_dp_On2(str, isPalindrome) << endl;
}

int main()
{
    solve();
    return 0;
}
