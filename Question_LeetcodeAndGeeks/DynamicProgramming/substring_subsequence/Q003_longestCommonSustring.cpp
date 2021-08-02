#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int max_ = 0;
int longestCommonSustring_memo(string &s1, int idx1, string &s2, int idx2, vector<vector<int>> &mdp)
{
    if (idx1 == s1.length() || idx2 == s2.length())
        return 0;

    if (s1[idx1] == s2[idx2])
    {
        int recAns = longestCommonSustring_memo(s1, idx1 + 1, s2, idx2 + 1, mdp);
        max_ = max(max_, recAns + 1);
        return recAns + 1;
    }
    else
    {
        longestCommonSustring_memo(s1, idx1 + 1, s2, idx2, mdp);
        longestCommonSustring_memo(s1, idx1, s2, idx2 + 1, mdp);
    }

    return 0;
}

int longestCommonSustring(string s1, string s2)
{

    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
    int max_ = 0;
    for (int i = s1.length() - 1; i >= 0; i--)
    {
        for (int j = s2.length() - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = dp[i + 1][j + 1] + 1;
                max_ = max(max_, dp[i][j]);
            }
        }
    }

    return max_;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;

    // s1 = "abcdgh";
    // s2 = "acdghr";

    // cout<<longestCommonSustring(s1,s2)<<endl;

    max_ = 0;
    vector<vector<int>> mdp(s1.length(), vector<int>(s2.length(), 0));
    longestCommonSustring_memo(s1, 0, s2, 0, mdp);
    cout << max_ << endl;
}

int main(int args, char **argv)
{
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}