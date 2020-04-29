// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


bool wordBreak_memo(string s, int idx)
{
    if (idx == s.length())
        return dp[idx] = true;

    if (dp[idx])
        return true;

    bool res = false;
    for (int &len : wordLen)
    {
        if (idx + len <= s.length() && words.count(s.substr(idx, len)))
        {
            res = res || wordBreak_memo(s, idx + len);
        }
    }

    return dp[idx] = res;
}

bool wordBreak_DP(string s, vector<string> &wordDict)
{
    string_view sv(s);
    unordered_set<string_view> word_set(wordDict.begin(), wordDict.end());

    size_t max_length = 0;
    for (string &word : wordDict)
    {
        max_length = max(max_length, word.length());
    }

    int n = s.length();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;                  // empty string
    for (int i = 0; i < n; i++) // string start
    {
        if (!dp[i])
            continue;
        for (int l = 1; l <= n - i && l <= max_length; l++) // string length
        {
            if (word_set.count(sv.substr(i, l)))
                dp[i + l] = 1;
        }
    }
    return dp[n];
}

bool wordBreak(string s, vector<string> &wordDict)
{
    for (string &word : wordDict)
    {
        words.insert(word);
    }

    dp.resize(s.length() + 1, false);
    return wordBreak_memo(s, 0);
}
