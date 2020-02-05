// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <climits>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

void palidromeSubstring(string &str, vii &isPalindrome)
{
    for (int gap = 0; gap < str.length(); gap++)
    {
        for (int i = 0, j = gap; j < str.length(); j++, i++)
        {
            if (gap == 0)
                isPalindrome[i][j] = 1;
            else if (gap == 1 && str[i] == str[j])
                isPalindrome[i][j] = 1;
            else
                isPalindrome[i][j] = isPalindrome[i + 1][j - 1] && str[i] == str[j];
        }
    }
}

int minPalindromicCut_On3(int i, int j, vii &isPalindrome, vii &dp)
{
    if (isPalindrome[i][j])
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int min_ = 1000000;

    for (int cut = i; cut < j; cut++)
    {
        int left = minPalindromicCut(i, cut, isPalindrome, dp);
        int right = minPalindromicCut(cut + 1, j, isPalindrome, dp);
        min_ = min(min_, left + right + 1);
    }

    dp[i][j] = min_;
    return min_;
}

int minPalindromicCut_dp_On3(string &str, vii &isPalindrome)
{
    vii dp(str.length(), vi(str.length(), -1));
    for (int gap = 1; gap < str.length(); gap++)
    {
        for (int i = 0, j = gap; j < str.length(); j++, i++)
        {
            if (isPalindrome[i][j])
            {
                dp[i][j] = 0;
                continue;
            }

            int min_ = INT_MAX;
            for (int cut = i; cut < j; cut++)
            {
                int left = dp[i][cut];
                int right = dp[cut + 1][j];

                int cost = left + right + 1;
                min_ = min(min_, cost);
            }
            dp[i][j] = min_;
        }
    }

    return dp[0][str.length() - 1];
}

int minPalindromicCut_dp_On2(string &str, vii &isPalindrome){
    vi cuts(str.length(),0);
    int n=str.length();
    for(int i=0;i<n;i++){
        if(isPalindrome[0][i])
          cuts[i]=0;
        else{
        int max_=INT_MAX;
        for(int j=0;j<i;j++){
           if(isPalindrome[j+1][i]) max_=min(cuts[j]+1,max_);
        }
        cuts[i]=max_;
        }
    }
    return cuts[n-1];

}

void solve()
{
    string str = "abccbc";
    vii isPalindrome(str.length(), vi(str.length(), 0));
    palidromeSubstring(str, isPalindrome);

    //O(n3).===============
    vii dp(str.length(), vi(str.length(), -1));
    cout << minPalindromicCut_On3(0, str.length() - 1, isPalindrome, dp) << endl;
    cout << minPalindromicCut_dp_On3(str, isPalindrome) << endl;

    //O(n2).===============

}
int main()
{
    solve();
    return 0;
}
