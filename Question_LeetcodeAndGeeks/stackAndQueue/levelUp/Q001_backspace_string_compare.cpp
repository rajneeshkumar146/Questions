// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <stack>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

stack<char> stringReframe(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '#')
            st.push(s[i]);
        else if (st.size() != 0)
            st.pop();
    }

    return st;
}

bool backspaceCompare(string S, string T)
{

    stack<char> st1 = stringReframe(S);
    stack<char> st2 = stringReframe(T);

    if (st1.size() != st2.size())
        return false;
    else
        while (st1.size() != 0)
        {
            if (st1.top() != st2.top())
                return false;
            st1.pop();
            st2.pop();
        }

    return true;
}

void solve()
{
}
int main()
{
    solve();
    return 0;
}
