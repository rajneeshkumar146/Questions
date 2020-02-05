// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

string removeDuplicates(string S)
{

    vector<char> st;
    st.push_back('$');

    bool flag = false;
    int i = 0;

    while (i < S.length())
    {
        while (i < S.length() && st.back() != S[i])
        {
            st.push_back(S[i]);
            i++;
        }

        if (i < S.length() && st.back() == S[i])
        {
            st.pop_back();
            i++;
        }
    }

    string str = "";
    for (i = 1; i < st.size(); i++)
    {
        str += st[i];
    }
    return str;
}

void solve()
{
}
int main()
{
    solve();
    return 0;
}
