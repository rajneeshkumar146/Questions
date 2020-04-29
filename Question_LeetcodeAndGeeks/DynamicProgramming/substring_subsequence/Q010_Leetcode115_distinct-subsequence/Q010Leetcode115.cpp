#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<long long int>> dp;
string str1, str2;

int numDistinct_01(int n, int m)
{
    if (m == 0)
        return dp[n][m] = 1;
    if (n < m)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (str1[n - 1] == str2[m - 1])
        return dp[n][m] = numDistinct_01(n - 1, m - 1) +
                          numDistinct_01(n - 1, m);

    return dp[n][m] = numDistinct_01(n - 1, m);
}

int numDistinct_02(int i, int j)
{
    if (j == str2.length())
        return dp[i][j] = 1;
    if (i == str1.length())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (str1[i] == str2[j])
        return dp[i][j] = numDistinct_02(i + 1, j + 1) +
                          numDistinct_02(i + 1, j);

    return dp[i][j] = numDistinct_02(i + 1, j);
}

int numDistinct_DP()
{
    int n = str1.length();
    int m = str2.length();
    for (int i = n; i >= 0; i--)
    {
        for (int j = m; j >= 0; j--)
        {
            if (j == m)
            {
                dp[i][j] = 1;
                continue;
            }
            if (i == n)
            {
                dp[i][j] = 0;
                continue;
            }

            if (str1[i] == str2[j])
                dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
            else
                dp[i][j] = dp[i + 1][j];
        }
    }

    return dp[0][0];
}

int numDistinct(string s, string t)
{
    dp.resize(s.length() + 1, vector<long long int>(t.length() + 1, -1));
    str1 = s;
    str2 = t;

    // return numDistinct_01(s.length(), t.length());
    // return numDistinct_01(s.length(), t.length());
    return numDistinct_DP();
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

    cout << numDistinct_DP_02(s1, s2) << endl;
}

int main(int args, char **argv)
{
    // int t;
    // cin >> t;
    // while (t-- > 0)
    solve();
}