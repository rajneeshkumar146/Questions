#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int countDS_DP(string &s)
{
    vector<int> dp(s.length() + 1, 0);
    int freq[26] = {0};
    int mod = 1e9 + 7;
    dp[0] = 1;

    for (int i = 1; i <= s.length(); i++)
    {
        dp[i] = (2 * dp[i - 1]) % mod;
        int idx = s[i - 1] - 'a';
        if (freq[idx] != 0)
            dp[i] -= dp[freq[idx] - 1];

        freq[idx] = i;
    }

    return dp[s.length()];
}

void solve()
{
    // int n;
    // cin >> n;
    string s1;
    // cin >> s1;

    s1 = "abab";
    cout << countDS_DP(s1) << endl;
}

int main(int args, char **argv)
{
    // int t;
    // cin >> t;
    // while (t-- > 0)
    solve();
}