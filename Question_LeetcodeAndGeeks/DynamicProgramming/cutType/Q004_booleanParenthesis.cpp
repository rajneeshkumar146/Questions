// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>
#include <string>

#define vi vector<int>
#define vii vector<vi>
#define ll long long int
#define mod 1003

using namespace std;

 helper(string &str, int k, pair<ll, ll> &left, pair<ll, ll> &right,pair<ll, ll> &ans)
{

    int total_left = left.first % mod + left.second % mod;
    int total_right = right.first % mod + right.second % mod;

    int total = total_left % mod * total_right % mod;

    if (str[k] == '|')
    {
        ans.first += (total % mod - left.second % mod * right.second % mod + mod) % mod;
        ans.second += (left.second % mod * right.second % mod) % mod;
    }
    else if (str[k] == '&')
    {
        ans.first += (left.first % mod * right.first % mod) % mod;
        ans.second += (total % mod - left.first % mod * right.first % mod + mod) % mod;
    }
    else if (str[k] == '^')
    {
        ans.first += (left.first % mod * right.second % mod + left.second % mod * right.first % mod) % mod;
        ans.second += (left.first % mod * right.first % mod + left.second % mod * right.second % mod) % mod;
    }

    ans.first %= mod;
    ans.second %= mod;

}

pair<ll, ll> BP_rec(string &str, int i, int j, vector<vector<pair<ll, ll>>> &dp)
{
    if (i == j)
    {
        pair<ll, ll> base;
        base.first = str[i] == 'T' ? 1 : 0;
        base.second = str[i] == 'F' ? 1 : 0;
        return base;
    }

    if (dp[i][j].first != 0 || dp[i][j].second != 0)
        return dp[i][j];

    pair<ll, ll> ans = {0, 0};
    for (int k = i + 1; k < j; k += 2)
    {
        pair<ll, ll> left = BP_rec(str, i, k - 1, dp);
        pair<ll, ll> right = BP_rec(str, k + 1, j, dp);

        helper(str, k, left, right,ans);
    }

    dp[i][j] = ans;

    return ans;
}

void solve()
{
    int len;
    cin >> len;
    string str;
    cin >> str;

    vector<vector<pair<ll, ll>>> dp(len, vector<pair<ll, ll>>(len, {0, 0}));
    cout << BP_rec(str, 0, len - 1, dp).first % 1003 << endl;
}

int main(int args, char **argv)
{
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}