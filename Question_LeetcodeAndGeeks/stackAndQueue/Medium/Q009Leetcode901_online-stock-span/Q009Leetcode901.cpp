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

class StockSpanner
{
public:
    stack<pair<int, int>> st;
    int i;
    StockSpanner()
    {
        st.push({-1, -1});
        i = 0;
    }

    int next(int price)
    {
        int ans = 1;
        while (st.top().second != -1 && st.top().first <= price)
        {
            st.pop();
            ans = i - st.top().second;
        }

        st.push({price, i});
        i++;
        return ans;
    }
};
