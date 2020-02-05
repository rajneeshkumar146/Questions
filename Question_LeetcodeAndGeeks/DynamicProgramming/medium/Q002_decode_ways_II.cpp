#include <iostream>
#include <vector>
using namespace std;

int m = 1e9 + 7;
typedef long long int ll;

ll numDecodingsII_recu(string &s, int idx, vector<ll> &dp)
{
    if (idx == s.length())
        return 1;

    if (dp[idx] != 0)
        return dp[idx];

    ll count = 0;
    if (s[idx] == '*')
    {
        count = (count + 9 * numDecodingsII_recu(s, idx + 1, dp)) % m;
        if (idx + 1 < s.length() && (s[idx + 1] >= '0' && s[idx + 1] <= '6'))
            count = (count + 2 * numDecodingsII_recu(s, idx + 2, dp)) % m;
        else if (idx + 1 < s.length() && s[idx + 1] > '6' && s[idx + 1] <= '9')
            count = (count + numDecodingsII_recu(s, idx + 2, dp)) % m;
        else if (idx + 1 < s.length() && s[idx + 1] == '*')
            count = (count + 15 * numDecodingsII_recu(s, idx + 2, dp)) % m;
    }
    else if (s[idx] > '0')
    {
        count = (count + numDecodingsII_recu(s, idx + 1, dp)) % m;
        if (idx + 1 < s.length())
        {
            if (s[idx + 1] == '*')
            {
                if (s[idx] == '1')
                    count = (count + 9 * numDecodingsII_recu(s, idx + 2, dp)) % m;
                else if (s[idx] == '2')
                    count = (count + 6 * numDecodingsII_recu(s, idx + 2, dp)) % m;
            }
            else
            {
                int val = (s[idx] - '0') * 10 + (s[idx + 1] - '0');
                if (val < 27)
                    count = (count + numDecodingsII_recu(s, idx + 2, dp)) % m;
            }
        }
    }

    dp[idx] = count;
    return count;
}

//DP.=========================================================================

ll numDecodingsII_DP(string &s)
{

    ll count = 0;
    ll a = 1;
    ll b = 0;
    for (int idx = s.length() - 1; idx >= 0; idx--)
    {
        if (s[idx] == '*')
        {
            count = (count + 9 * a) % m;
            if (idx + 1 < s.length() && (s[idx + 1] >= '0' && s[idx + 1] <= '6'))
                count = (count + 2 * b) % m;
            else if (idx + 1 < s.length() && s[idx + 1] > '6' && s[idx + 1] <= '9')
                count = (count + b) % m;
            else if (idx + 1 < s.length() && s[idx + 1] == '*')
                count = (count + 15 * b) % m;
        }
        else if (s[idx] > '0')
        {
            count = (count + a) % m;
            if (idx + 1 < s.length())
            {
                if (s[idx + 1] == '*')
                {
                    if (s[idx] == '1')
                        count = (count + 9 * b) % m;
                    else if (s[idx] == '2')
                        count = (count + 6 * b) % m;
                }
                else
                {
                    int val = (s[idx] - '0') * 10 + (s[idx + 1] - '0');
                    if (val < 27)
                        count = (count + b) % m;
                }
            }
        }

        b = a;
        a = count;
    }

    return a;
}

void solve()
{
    // * - 9
    // ** - 96
    //**********1111111111 - 133236775

    string str;
    cin >> str;
    vector<ll> dp(str.length() + 1, 0);
    cout << bendl;
}

int main()
{
    solve();
    return 0;
}