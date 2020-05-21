// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
size_t len;
unordered_set<string_view> words;
vector<bool> dp;

vector<string> res;

void dfs(string &str, int idx, string ans)
{
    if (idx == str.length())
    {
        res.push_back(ans.substr(0, ans.length() - 1));
        return;
    }

    for (int l = 1; idx + l <= str.length() && l <= len; l++)
    {
        if (dp[idx + l] && words.count(str.substr(idx, l)))
            dfs(str, idx + l, ans + str.substr(idx, l) + " ");
    }
}

vector<string> wordBreak(string s, vector<string> &wordDict)
{
    string_view str(s);
    len = 0;
    for (string &s : wordDict)
    {
        words.insert(s);
        len = max(len, s.length());
    }

    dp.resize(s.length() + 1, false);
    dp[0] = true;
    for (int i = 0; i <= str.length(); i++)
    {
        if (!dp[i])
            continue;

        for (int l = 1; i + l <= str.length() && l <= len; l++)
        {
            if (words.count(str.substr(i, l)))
                dp[i + l] = true;
        }
    }

    if (!dp[s.length()])
        return {};
    dfs(s, 0, "");
    return res;
}