// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>
using namespace std;

//Easy Method and intutive.===========================================================================
vector<int> nsor(vector<int> &arr)
{
    stack<int> st;
    vector<int> ans(arr.size(), arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        while (st.size() != 0 && arr[st.top()] > arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    return ans;
}

vector<int> nsol(vector<int> &arr)
{
    stack<int> st;
    vector<int> ans(arr.size(), -1);

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (st.size() != 0 && arr[st.top()] > arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    vector<int> nsolA = nsol(heights);
    vector<int> nsorA = nsor(heights);

    int max_ = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        int width = nsorA[i] - nsolA[i] - 1;
        int area = heights[i] * width;
        max_ = max(max_, area);
    }
    return max_;
}

//Using stack and little good with previous one.===============================================

int largestRectangleArea_02(vector<int> &heights)
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

//Finding largest area region in array.======================================

vector<int> largestRectangleArea_03(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    st.push(-1);
    int maxArea = 0;

    int lb = 0, rb = 0, h = 0;

    for (int i = 0; i < n; i++)
    {
        while (st.top() != -1 && heights[st.top()] >= heights[i])
        {
            int height = heights[st.top()];
            st.pop();
            int area = height * (i - st.top() - 1);
            if (area > maxArea)
            {
                maxArea = area;
                lb = st.top() + 1;
                rb = i - 1;
                h = height;
            }
        }
        st.push(i);
    }

    while (st.top() != -1)
    {
        int height = heights[st.top()];
        st.pop();
        int area = height * (n - st.top() - 1);
        if (area > maxArea)
        {
            maxArea = area;
            lb = st.top() + 1;
            rb = n - 1;
            h = height;
        }
    }

    return {maxArea, lb, rb, h};
}
