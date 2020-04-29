// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

string s, p;
vector<vector<bool>> dp;

bool isMatch_rec(int i, int j, int &n, int &m)
{
    if (j == m && i==n)
        return dp[i][j]= true;
    if(j==m)
         return dp[i][j] =false;

    if (dp[i][j])
        return true;

    bool res = false;
    if (p[j + 1] != '*')
    {
        if (i<n && (s[i] == p[j] || p[j] == '.'))
            res = isMatch_rec(i + 1, j + 1, n, m);
    }
    else
    {
        res = res || isMatch_rec(i, j + 2, n, m); // all preceding element in pattern string count is zero.
        while (!res && (i < n && (s[i] == p[j] || p[j] == '.')))
            res = res || isMatch_rec(++i, j + 2, n, m);
    }

    return dp[i][j] = res;
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
    
    p+="$";
    dp.resize(n + 1, vector<bool>(m + 1, false));
    return isMatch_rec(0,0,n, m);
}