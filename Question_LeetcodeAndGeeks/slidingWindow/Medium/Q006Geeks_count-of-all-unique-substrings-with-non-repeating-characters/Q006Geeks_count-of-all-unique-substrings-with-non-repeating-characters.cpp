// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int countOfLongestSubstring(string s)
{
    int n = s.length();
    unordered_set<string> map;
    
    for (int i = 0; i < n; i++)
    {
        string str="";
        vector<int> freq(128,0);
    
        for (int j = i; j < n; j++)
        {
            if(freq[s[j]]++ == 1) break;
            str+=s[j];
            map.insert(str);
        }
    }
    return map.size();
}

void solve()
{
    string s;
    cin >> s;
    cout << countOfLongestSubstring(s) << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}