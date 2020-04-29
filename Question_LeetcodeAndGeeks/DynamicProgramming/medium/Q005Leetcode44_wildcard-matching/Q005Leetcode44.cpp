// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

string s, p;
vector<vector<bool>> dp;

bool isMatch_(int idx1, int idx2, int n, int m)
{
    if (idx1 == n && idx2 == m)
        return dp[idx1][idx2] = true;
    if (idx2 == m || idx1 == n)
    {
        if (idx1 != n)
            return dp[idx1][idx2] = false;
        return dp[idx1][idx2] = (p[idx2] == '*' && m-idx2==1? true : false);
    }

    if (dp[idx1][idx2])
        return true;

    bool res = false;
    if (s[idx1] == p[idx2])
        res = isMatch_(idx1 + 1, idx2 + 1, n, m);
    else if (p[idx2] == '?')
        res = isMatch_(idx1 + 1, idx2 + 1, n, m);
    else if (p[idx2] == '*')
    {
        res = res || isMatch_(idx1, idx2 + 1, n, m); //emptyStringMapping
        res = res || isMatch_(idx1 + 1, idx2, n, m); //sequneceMapping
    }

    return dp[idx1][idx2] = res;
}

bool isMatch02_(int n, int m)
{
    if (!n && !m)
        return dp[n][m] = true;
    if (!n || !m)
    {
        if (!m)
            return dp[n][m] = false;
        return dp[n][m] = (p[m - 1] == '*') && m - 1 == 0;
    }

    if (dp[n][m])
        return true;

    bool res = false;
    if (s[n - 1] == p[m - 1])
        res = isMatch02_(n - 1, m - 1);
    else if (p[m - 1] == '?')
        res = isMatch02_(n - 1, m - 1);
    else if (p[m - 1] == '*')
    {
        res = res || isMatch02_(n, m - 1); //emptyStringMapping
        res = res || isMatch02_(n - 1, m); //sequneceMapping
    }

    return dp[n][m] = res;
}

bool isMatch_DP(int N, int M)
{
    for (int n = 0; n <= N; n++)
    {
        for (int m = 0; m <= M; m++)
        {
            if (!n && !m)
            {
                dp[n][m] = true;
                continue;
            }

            if (!n || !m)
            {
                if (!m)
                    dp[n][m] = false;
                else
                    dp[n][m] = (p[m - 1] == '*') && m - 1 == 0;

                continue;
            }

            bool res = false;
            if (s[n - 1] == p[m - 1])
                res = dp[n - 1][m - 1];
            else if (p[m - 1] == '?')
                res = dp[n - 1][m - 1];
            else if (p[m - 1] == '*')
            {
                res = res || dp[n][m - 1]; //emptyStringMapping
                res = res || dp[n - 1][m]; //sequneceMapping
            }

            dp[n][m] = res;
        }
    }

    return dp[N][M];
}

string removeStar(string &str)
{
    string ans = "";
    bool firstStar = false;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '*')
        {
            if (!firstStar)
                ans += str[i];
            firstStar = true;
        }
        else
        {
            ans += str[i];
            firstStar = false;
        }
    }
    return ans;
}

bool isMatch(string str, string ptr)
{
    p = removeStar(ptr);

    s = str;
    int n = s.length();
    int m = p.length();

    dp.resize(n + 1, vector<bool>(m + 1, false));
    return isMatch02_(n, m);
}