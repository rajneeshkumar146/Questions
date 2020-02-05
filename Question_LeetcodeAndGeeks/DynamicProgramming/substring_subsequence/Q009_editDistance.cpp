#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minimum(int a, int b, int c)
{
    return min(a, min(b, c));
}

int editdistance(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
    if (j == 0 || i == 0)
        return max(i, j);

    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 0;
    if (s1[i - 1] == s2[j - 1])
        ans = editdistance(s1, s2, i - 1, j - 1, dp);
    else
        ans = minimum(editdistance(s1, s2, i - 1, j - 1, dp), editdistance(s1, s2, i, j - 1, dp), editdistance(s1, s2, i - 1, j, dp)) + 1;
    dp[i][j] = ans;
    return ans;
}

int editdistance_DP(string &s1, string &s2)
{

    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
    for (int i = 0; i <= s1.length(); i++)
    {
        for (int j = 0; j <= s2.length(); j++)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = minimum(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1; //replace,remove,insert.
        }
    }

    return dp[s1.length()][s2.length()];
}

void solve()
{
    // int n,m;
    // cin >> n>>m;
    string s1, s2;
    // cin >> s1 >>s2;

    s1 = "sunday";
    s2 = "saturday";

    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
    cout << editdistance(s1, s2, s1.length(), s2.length(), dp) << endl;

    cout << editdistance_DP(s1, s2);
}

int main(int args, char **argv)
{
    // int t;
    // cin >> t;
    // while (t-- > 0)
    solve();
}