#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void countPalindromicSubstring(string &s1)
{
    vector<string> ans;
    vector<vector<int>> dp(s1.length(), vector<int>(s1.length(), 0));
    for(int gap=0;gap<s1.length();gap++){
      for(int i=0,j=gap;i<s1.length() && j<s1.length();i++,j++){
          if(gap==0){
             dp[i][j]=true;
             ans.push_back(s1.substr(i,j-i+1));   
          }else if(gap==1 && s1[i]==s1[j]){
              dp[i][j]=true;
              ans.push_back(s1.substr(i,j-i+1));
          }else if(s1[i]==s1[j] && dp[i+1][j-1]){
              dp[i][j]=true;
              ans.push_back(s1.substr(i,j-i+1));
          }
      }
    }

    for(string s:ans) cout<<s<<" ";
}

void solve()
{
    // int n;
    // cin >> n;
    string s1;
    // cin >> s1;

    s1 = "abaab";

    countPalindromicSubstring(s1);
}

int main(int args, char **argv)
{
    // int t;
    // cin >> t;
    // while (t-- > 0)
    solve();
}