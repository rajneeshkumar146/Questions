#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int longestCommonSusequence_memo(string &s1, int idx1, string &s2, int idx2, vector<vector<int>> &mdp)
{
    if (idx1 == s1.length() || idx2 == s2.length())
        return 0;

    if (mdp[idx1][idx2] != 0)
        return mdp[idx1][idx2];

    int ans = 0;
    if (s1[idx1] == s2[idx2])
        ans = longestCommonSusequence_memo(s1, idx1 + 1, s2, idx2 + 1, mdp) + 1;
    else
        ans = max(longestCommonSusequence_memo(s1, idx1 + 1, s2, idx2, mdp), longestCommonSusequence_memo(s1, idx1, s2, idx2 + 1, mdp));

    mdp[idx1][idx2] = ans;
    return ans;
}

int longestCommonSubstring(string s1, string s2)
{

    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
    for (int i = s1.length() - 1; i >= 0; i--)
    {
        for (int j = s2.length() - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = dp[i + 1][j + 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    return dp[0][0];
}

void solve()
{
    // int n, m;
    // cin >> n >> m;
    string s1, s2;
    // cin >> s1 >> s2;

    s1 = "AGGTAB";
    s2 = "GXTXAYB";

    vector<vector<int>> mdp(s1.length(), vector<int>(s2.length(), 0));

    // cout << longestCommonSusequence_memo(s1, 0, s2, 0, mdp) << endl;
    cout<<longestCommonSubstring(s1,s2)<<endl;
}

int main(int args, char **argv)
{
    // int t;
    // cin >> t;
    // while (t-- > 0)
    solve();
}