// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int max_ = 0;
    stack<int> st;
    st.push(-1);
    int i = 0;
    for (; i < heights.size(); i++)
    {
        while (st.top() != -1 && heights[st.top()] >= heights[i])
        {
            int idx = st.top();
            st.pop();
            int area = heights[idx] * (i - st.top() - 1);
            if (max_ < area)
                max_ = area;
        }

        st.push(i);
    }

    while (st.top() != -1)
    {
        int idx = st.top();
        st.pop();
        int area = heights[idx] * (i - st.top() - 1);
        if (max_ < area)
            max_ = area;
    }

    return max_;
}

void solve()
{
    // vector<int> arr = {2, 3, 3, 3, 5, 5, 5, 4, 2, 2, 1};
    vector<int> arr = {2, 1, 5, 6, 2, 3};
}
int main()
{
    solve();
    return 0;
}
