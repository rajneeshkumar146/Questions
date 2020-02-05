#include <iostream>
#include <vector>
using namespace std;

int substringGenerate(string s, int si, int ei, vector<string> &ans)
{
    if (si == ei)
    {
        for (string st : ans)
        {
            cout << st << " ";
        }
        return 0;
    }

    int count_ = 0;
    for (int i = si; i < ei; i++)
    {
        string ss = s.substr(si, i - si + 1);
        ans.push_back(ss);
        count_++;
    }

    count_ += substringGenerate(s, si + 1, ei, ans);

    return count_;
}

bool isPalindrome(string &s)
{
    for (int i = 0, j = s.length() - 1; i < j; i++, j--)
    {
        if (s[i] != s[j])
            return false;
    }
    return true;
}

string lss = "";
int palindromicSubstringGenerate(string s, int si, int ei, vector<string> &ans)
{
    if (si == ei)
    {
        for (string st : ans)
        {
            cout << st << " ";
        }
        return 0;
    }

    int count_ = 0;
    for (int i = si; i < ei; i++)
    {
        string ss = s.substr(si, i - si + 1);
        if (isPalindrome(ss))
        {
            ans.push_back(ss);
            count_++;
        }
    }

    count_ += palindromicSubstringGenerate(s, si + 1, ei, ans);

    return count_;
}

//O(n2).==========================================================================

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

        if(ans.size()>maxAns.size())
          maxAns=ans;
    }

return maxAns;

}



void solve()
{
    vector<string> ans;
    // cout << substringGenerate("abcd", 0, 4, ans);
    cout << palindromicSubstringGenerate("aab", 0, 3, ans);
}

int main(int args, char **argv)
{
    solve();
}

// https://leetcode.com/problems/longest-palindromic-substring/
