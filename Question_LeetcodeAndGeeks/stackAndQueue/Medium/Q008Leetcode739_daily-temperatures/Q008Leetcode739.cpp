// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <stack>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

vector<int> dailyTemperatures(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n, 0);

    stack<int> st;
    st.push(-1);

    for (int i = 0; i < n; i++)
    {
        while (st.top() != -1 && arr[st.top()] < arr[i])
        {
            int x = st.top();
            st.pop();
            ans[x] = i - x;
        }

        st.push(i);
    }
    return ans;
}