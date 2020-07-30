// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    st.push(-1);
    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        while (st.top() != -1 && heights[st.top()] >= heights[i])
        {
            int height = heights[st.top()];
            st.pop();
            int area = height * (i - st.top() - 1);
            if (area > maxArea)
                maxArea = area;
        }
        st.push(i);
    }

    while (st.top() != -1)
    {
        int height = heights[st.top()];
        st.pop();
        int area = height * (n - st.top() - 1);
        if (area > maxArea)
            maxArea = area;
    }

    return maxArea;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    if (matrix.size() == 0 || matrix[0].size() == 0)
        return 0;

    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> heights(m, 0);

    int maxArea = 0;

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
            heights[c] += ((matrix[r][c] == '1') ? 1 : 0);

        maxArea = max(maxArea, largestRectangleArea(heights));
    }

    return maxArea;
}
