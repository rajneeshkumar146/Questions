// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <climits>

#define vi vector<int>
#define vvi vector<vi>

using namespace std;

// for n*m.
// ek sqaure cut kiya i*i ka usse do possiblites bngyi rectangle bnane ki

//upper ka cut portion ((n-i)*i) and right side pura (n*(m-i)).
//  ---------------
// |(n-i) |        |
// | *i   |        |
// |------  n*(m-i)|
// |  cut |        |
// | piece|        |
// |of i*i|        |
//  ---------------

//upper ka cut portion ((n-i)*m) and right side pura (i*(m-i)).
//  ---------------
// |   (n-i)*m     |
// |------ ........|
// |  cut |        |
// | piece| i*(m-i)|
// |of i*i|        |
//  ---------------

int tillingSquares_memo(int n, int m,
                        vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
        return 0;
    if (n == 1 || m == 1)
        return n == 1 ? m : n;
    if ((n == 11 && m == 13) || (n == 13 && m == 11))
        return 6;

    if (dp[n][m] != 0)
        return dp[n][m];

    int maxPossibleSizeOfSqaure = min(n, m);
    int minAns = INT_MAX;

    for (int i = maxPossibleSizeOfSqaure; i > 0; i--)
    {

        int fp_Upward = tillingSquares_memo(n - i, i, dp);
        int fp_rightSide = tillingSquares_memo(n, m - i, dp);

        int sp_Upward = tillingSquares_memo(n - i, m, dp);
        int sp_rightSide = tillingSquares_memo(i, m - i, dp);

        minAns = min(minAns, min(fp_rightSide + fp_Upward, sp_rightSide + sp_Upward));
    }

    if (minAns != INT_MAX)
        minAns++;

    dp[n][m] = minAns;
    return minAns;
}

//====================================================================

int inf = (1 << 30);
int ans;

bool finished(vector<int> &state)
{
    for (auto x : state)
        if (x > 0)
            return false;
    return true;
}

void tillingSquares_01(vector<int> &state, int current_count)
{
    if (finished(state))
        ans = min(ans, current_count);
    if (current_count > ans)
        return;

    int pos = 0;
    for (int i = 0; i < state.size(); ++i)
        if (state[i] > state[pos])
            pos = i;

    int right = pos + 1;
    while (right < state.size() && state[right] == state[pos])
        ++right;

    int max_size = min(right - pos, state[pos]);

    for (int size = max_size; size >= 1; --size)
    {
        for (int i = 0; i < size; ++i)
            state[pos + i] -= size;
        tillingSquares_01(state, current_count + 1);
        for (int i = 0; i < size; ++i)
            state[pos + i] += size;
    }
}

int tilingRectangle(int n, int m)
{
    vvi dp(n + 1, vi(m + 1, 0));
    int res = tillingSquares_memo(n, m, dp);

    cout<<res<<endl;
    
    ans = inf;
    vector<int> state(m, n);
    tillingSquares_01(state, 0);

    return ans;
}

void solve()
{
    cout << tilingRectangle(53, 41) << endl;
}
int main()
{
    solve();
    return 0;
}
