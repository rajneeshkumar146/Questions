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

int longestValidParentheses(string str)
{
    int n = str.length();
    stack<int> st;
    st.push(-1);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (st.top() != -1 && str[i] == ')' && str[st.top()] == '(')
        {
            st.pop();
            ans = max(ans, i - st.top());
        }
        else
            st.push(i);
    }

    return ans;
}