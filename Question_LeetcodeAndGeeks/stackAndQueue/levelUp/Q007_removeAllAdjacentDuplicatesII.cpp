// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

string removeDuplicates(string s, int k)
{
    vector<pair<char, int>> st;

    int i = 0;
    while (i < s.length())
    {
        if (st.size() == 0 || st.back().first != s[i])  //gar while loop lgate to else if bhi manage krna pdta kisi bool ki help se.
            st.push_back({s[i], 1});
        else if (++st.back().second == k)
            st.pop_back();

        i++;
    }

    string ans = "";
    for (pair<char, int> &s : st)
    {
        ans += string(s.second, s.first);
    }

    return ans;
}

void solve()
{
}
int main()
{
    solve();
    return 0;
}
