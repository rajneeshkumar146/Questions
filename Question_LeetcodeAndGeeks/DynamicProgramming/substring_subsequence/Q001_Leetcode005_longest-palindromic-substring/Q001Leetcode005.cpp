#include <iostream>
#include <vector>
using namespace std;

string palindromicSS_DP(string s)
{
    vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
    string ans = "";
    string maxAns = "";
    for (int gap = 0; gap < s.length(); gap++)
    {
        for (int i = 0, j = gap; i < s.length() && j < s.length(); i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = true;
                ans = s.substr(i, j - i + 1);
            }
            else if (gap == 1 && s[i] == s[j])
            {
                dp[i][j] = true;
                ans = s.substr(i, j - i + 1);
            }
            else if (s[i] == s[j] && dp[i + 1][j] == dp[i][j - 1])
            {
                dp[i][j] = true;
                ans = s.substr(i, j - i + 1);
            }
        }

        if (ans.size() > maxAns.size())
            maxAns = ans;
    }

    return maxAns;
}

string palindromicSS_DP_02(string s)
{
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int si = 0;
    int len = 0;
    int maxsi = 0;
    int maxlen = 0;

    for (int gap = 0; gap < s.length(); gap++)
    {
        for (int i = 0, j = gap; i < s.length() && j < s.length(); i++, j++)
        {
            if (gap == 0)
                dp[i][j] = 1;
            else if (gap == 1 && s[i] == s[j])
                dp[i][j] = 2;
            else if (s[i] == s[j] && dp[i + 1][j - 1] != 0)
                dp[i][j] = dp[i + 1][j - 1] + 2;

            if (dp[i][j])
            {
                si = i;
                len = dp[si][ei];
            }
        }

        if (len > maxlen)
        {
            maxlen = len;
            simax = si;
        }
    }

    return s.substr(maxsi, maxsi + maxlen);
}

void solve()
{
}

int main(int args, char **argv)
{
    solve();
}
