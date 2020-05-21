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

void reverse(string &str, int i, int j)
{
    while (i < j)
    {
        swap(str[i], str[j]);
        i++;
        j--;
    }
}

string reverseParentheses(string str)
{
    int n = str.length();
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < n; i++)
    {
        if (st.top() != -1 && str[i] == ')' && str[st.top()] == '(')
        {
            reverse(str, st.top(), i);
            st.pop();
        }
        else if (str[i] == '(')
            st.push(i);
    }

    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            ans += str[i];
        }
    }
    return ans;
}