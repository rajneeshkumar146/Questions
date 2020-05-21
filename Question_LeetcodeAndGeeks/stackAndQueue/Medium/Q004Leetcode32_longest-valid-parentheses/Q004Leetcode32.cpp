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
    stack<int> st;
    st.push(-1);
    int max_ = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (st.top() != -1 && str[i] == ')' && str[st.top()] == '(')
        {
            st.pop();
            if (max_ < i - st.top())
                max_ = i - st.top();
        }
        else
            st.push(i);
    }

    return max_;
}