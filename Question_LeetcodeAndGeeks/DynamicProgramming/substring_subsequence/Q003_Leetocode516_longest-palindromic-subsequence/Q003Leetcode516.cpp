#include <iostream>
#include <vector>
using namespace std;

//Recursive.===============================================================================

int dp[1003][1003];
string s;

int longestPalindromeSubseq_Rec(int si, int ei)
{
    if (si > ei)
        return 0;
    if (si == ei)
        return 1;
    if (dp[si][ei] != -1)
        return dp[si][ei];

    if (s[si] == s[ei])
        return dp[si][ei] = longestPalindromeSubseq_Rec(si + 1, ei - 1) + 2;
    return dp[si][ei] = max(longestPalindromeSubseq_Rec(si + 1, ei), longestPalindromeSubseq_Rec(si, ei - 1));
}

int longestPalindromeSubseq(string &str)
{
    ios::sync_with_stdio(false);

    int n = str.length();
    s = str;
    memset(dp, -1, sizeof dp);
    return longestPalindromeSubseq_Rec(0, n - 1);
}

//Dp.===============================================================================

int longestPalindromeSubseq(string s)
{

    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (i == j)
                dp[i][j] = 1;
            else if (s[i] == s[j])
                dp[i][j] = 2 + dp[i + 1][j - 1];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][s.length() - 1];
}

void solve()
{
    // bbbab - 4
    // cbbd - 2
    cout << longestPalindromeSubseq("bbbab");
}

int main(int args, char **argv)
{
    solve();
}
