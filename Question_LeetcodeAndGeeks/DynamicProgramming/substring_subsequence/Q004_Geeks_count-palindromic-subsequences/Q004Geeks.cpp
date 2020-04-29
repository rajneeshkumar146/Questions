#include <iostream>
#include <vector>
#include <climits>

#define vi vector<int>
#define vii vector<vi>
using namespace std;

// https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1

//Repetition is allowed.==============================================================================

int countOfPalindromicSubsubsequence_Rec(string str, int si, int ei, vii &dp)
{
    if (si > ei)
        return 0;
    if (si == ei)
        return dp[si][ei] = 1;

    if (dp[si][ei] != 0)
        return dp[si][ei];

    int middleString = countOfPalindromicSubsubsequence_Rec(str, si + 1, ei - 1, dp);
    int withoutFirstCharString = countOfPalindromicSubsubsequence_Rec(str, si + 1, ei, dp);
    int withoutLastCharString = countOfPalindromicSubsubsequence_Rec(str, si, ei - 1, dp);

    int rAns = withoutFirstCharString + withoutLastCharString;

    return dp[si][ei] = (str.charAt(si) == str.charAt(ei) ? rAns + 1 : rAns - middleString);
}

int countPalindromicSubsequnence_DP(string &s1)
{
    vector<vector<int>> dp(s1.length(), vector<int>(s1.length(), 0));
    for (int gap = 0; gap < s1.length(); gap++)
    {
        for (int i = 0, j = gap; i < s1.length() && j < s1.length(); i++, j++)
        {
            if (gap == 0)
                dp[i][j] = 1;
            else if (s1[i] == s1[j])
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
            else
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
        }
    }

    return dp[0][s1.length() - 1];
}

void solve()
{
    s1 = "abaab";

    vii dp(s1.length(), vi(s1.length(), -1));
    cout << countOfPalindromicSubsubsequence_Rec(s1, 0, s1.length() - 1, dp) << endl;
    cout << countPalindromicSubsequnence_DP(s1) << endl;
}

int main(int args, char **argv)
{
    // int t;
    // cin >> t;
    // while (t-- > 0)
    solve();
}