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

int maximalRectangle(vector<vector<char>> &matrix)
{
    if (matrix.size() == 0)
        return 0;
    vector<int> ar(matrix[0].size(), 0);

    int max_ = 0;
    for (int r = 0; r < matrix.size(); r++)
    {
        for (int c = 0; c < matrix[0].size(); c++)
            ar[c] = matrix[r][c] == '0' ? 0 : ar[c] + 1;

        max_ = max(largestRectangleArea(ar), max_);
    }

    return max_;
}

void solve()
{
}
int main()
{
    solve();
    return 0;
}
