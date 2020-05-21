// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

string minRemoveToMakeValid(string str)
{
    vector<bool> marked(str.length(), false);
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < str.length(); i++)
    {
        if (st.top() != -1 && str[i] == ')' && str[st.top()] == '(')
        {
            int val = st.top();
            st.pop();
            marked[val] = marked[i] = true;
        }
        else if (str[i] == '(')
            st.push(i);
        else if (str[i] != '(' && str[i] != ')')
            marked[i] = true;
    }

    string ans = "";
    for (int i = 0; i < str.length(); i++)
        if (marked[i])
            ans += str[i];

    return ans;
}

//approach_02.======================================================

string minRemoveToMakeValid(string str)
{
    stack<int> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ')')
        {
            if (st.size() != 0)
                st.pop();
            else
                str[i] = '*';
        }
        else if (str[i] == '(')
            st.push(i);
    }

    while (!st.empty())
    {
        str[st.top()] = '*';
        st.pop();
    }

    string ans = "";
    for (int i = 0; i < str.length(); i++)
        if (str[i] != '*')
            ans += str[i];

    return ans;
}
