#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//recursion Solution.===========================================

int deleteOperation(string &str1, string &str2, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0)
        return m;
    if (m == 0)
        return n;

    if (dp[n][m] != 0)
        return dp[n][m];

    if (str1[n - 1] == str2[m - 1])
        return dp[n][m] = deleteOperation(str1, str2, n - 1, m - 1, dp);
    int a = deleteOperation(str1, str2, n - 1, m, dp);
    int b = deleteOperation(str1, str2, n, m - 1, dp);

    return dp[n][m] = min(a, b) + 1;
}

//LCS solution.==================================================
int longestCommonSubsequnece(string s1, string s2)
{

    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
    for (int i = s1.length() - 1; i >= 0; i--)
    {
        for (int j = s2.length() - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
                dp[i][j] = dp[i + 1][j + 1] + 1;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }

    return dp[0][0];
}

int minDistance(string word1, string word2)
{

    vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), 0));
    cout << deleteOperation(word1, word2, 0, 0, dp) << endl;

    // return word1.length() + word2.length() -  2*longestCommonSubsequnece(word1,word2);
}