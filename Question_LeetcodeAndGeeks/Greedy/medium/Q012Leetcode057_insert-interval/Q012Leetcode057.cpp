// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

static const auto magic = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    int n = intervals.size();
    stack<pair<int, int>> st;
    st.push({newInterval[0], newInterval[1]});

    for (int i = 0; i < n; i++)
    {
        if (st.top().second < intervals[i][0])
            st.push({intervals[i][0], intervals[i][1]});
        else if (intervals[i][1] < st.top().first)
        {
            pair<int, int> p = st.top();
            st.pop();
            st.push({intervals[i][0], intervals[i][1]});
            st.push(p);
        }
        else
        {
            pair<int, int> p = st.top();
            st.pop();
            st.push({min(intervals[i][0], p.first), max(intervals[i][1], p.second)});
        }
    }

    int m = st.size();
    vector<vector<int>> res(m);
    int i = res.size() - 1;
    while (st.size() != 0)
    {
        res[i] = {st.top().first, st.top().second};
        st.pop();
        i--;
    }
    return res;
}