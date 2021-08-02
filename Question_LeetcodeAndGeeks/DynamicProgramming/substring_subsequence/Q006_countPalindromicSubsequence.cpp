#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int countPS_memo(string &str, int i, int j, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if ((j - 1) == 1)
    {
        if (str[i] == str[j]) // ex: aa
            dp[i][j] = 3;
        else
            dp[i][j] = 2;

        return dp[i][j];
    }

    int ans = 0;

    if (i == j)
        ans = 1;
    else if (str[i] == str[j])
        ans = countPS_memo(str, i + 1, j, dp) + countPS_memo(str, i, j - 1, dp) + 1;
    else
        ans = countPS_memo(str, i + 1, j, dp) + countPS_memo(str, i, j - 1, dp) - countPS_memo(str, i + 1, j - 1, dp);

    dp[i][j] = ans;
    return ans;
}

//O(n2)======================================================

int countPalindromicSubsequnence(string &s1)
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
    // int n;
    // cin >> n;
    string s1;
    // cin >> s1;

    s1 = "abaab";

    vector<vector<int>> dp(s1.length(), vector<int>(s1.length(), -1));
    cout << countPS_memo(s1, 0, s1.length() - 1, dp) << endl;

    cout << countPalindromicSubsequnence(s1) << endl;
}

int main(int args, char **argv)
{
    // int t;
    // cin >> t;
    // while (t-- > 0)
    solve();
}