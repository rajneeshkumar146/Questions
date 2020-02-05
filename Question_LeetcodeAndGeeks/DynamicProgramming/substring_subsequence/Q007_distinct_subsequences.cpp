#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int numDistinct(string s1, string s2, int n, int m, vector<vector<int>> &dp)
{
    if ((n == 0 && m == 0) || m == 0)
        return 1;
    else if (n == 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    int ans = 0;
    if (s1[n - 1] == s2[m - 1])
        ans = numDistinct(s1, s2, n - 1, m - 1, dp);
    ans += numDistinct(s1, s2, n - 1, m, dp);

    dp[n][m] = ans;
    return ans;
}

//OS(n2), OT(n2)============================================================

int numDistinct_DP(string s1, string s2)
{

    vector<vector<long long int>> dp(s1.length() + 1, vector<long long int>(s2.length() + 1, 0));

    for (int i = s1.length(); i >= 0; i--)
    {
        for (int j = s2.length(); j >= 0; j--)
        {
            if (i == s1.length() && j == s2.length())
                dp[i][j] = 1;
            else if (j == s2.length())
                dp[i][j] = 1;
            else if (i == s1.length())
                dp[i][j] = 0;

            else if (s1[i] == s2[j])
                dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
            else
                dp[i][j] = dp[i + 1][j];
        }
    }

    return (int)dp[0][0];
}

//OS(n), OT(n2)============================================================

int numDistinct_DP_02(string s1, string s2)
{
    vector<long long int> dp(s2.length(), 0);

    for (int i = s1.length() - 1; i >= 0; i--)
    {
        long long int prev = 1;
        for (int j = s2.length() - 1; j >= 0; j--)
        {
            int temp = dp[j];
            dp[j] = dp[j] + ((s1[i] == s2[j]) ? prev : 0);

            prev = temp;
        }
    }

    return dp[0];
}
void solve()
{
    // int n>>m;
    // cin >> n>>m;
    string s1, s2;
    // cin >> s1>>s2;

    s1 = "babgbag";
    s2 = "bag";

    vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, -1));
    cout << numDistinct(s1, s2, s1.length(), s2.length(), dp) << endl;

    cout << numDistinct_DP(s1, s2) << endl;
    cout << numDistinct_DP_02(s1, s2) << endl;
}

int main(int args, char **argv)
{
    // int t;
    // cin >> t;
    // while (t-- > 0)
    solve();
}