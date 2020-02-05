#include <iostream>
#include <vector>
using namespace std;

int longestPalindromeSubseq(string s)
{

    vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));

    for (int gap = 0; gap < s.length(); gap++)
    {
        for (int i = 0, j = gap; i < s.length() && j < s.length(); i++, j++)
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
    cout << longestPalindromeSubseq("bbbab");
}

int main(int args, char **argv)
{
    solve();
}


// https://leetcode.com/problems/longest-palindromic-subsequence/

// bbbab - 4
// cbbd - 2