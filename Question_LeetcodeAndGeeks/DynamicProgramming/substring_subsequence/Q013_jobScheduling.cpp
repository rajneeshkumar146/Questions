#include <iostream>
using namespace std;

typedef vector<int> vi;

// n2 solution.===============================

int jobScheduling_n2(vector<int> &start, vector<int> &end, vector<int> &profit)
{
    if (start.size() == 0)
        return 0;

    vector<vector<int>> pair(start.size(), vector<int>(3, 0));
    for (int i = 0; i < start.size(); i++)
    {
        pair[i][0] = start[i];
        pair[i][1] = end[i];
        pair[i][2] = profit[i];
    }

    sort(pair.begin(), pair.end(), [](vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    });

    vector<int> dp(start.size(), 0);
    dp[0] = pair[0][2];
    int max_ = pair[0][2];
    for (int i = 1; i < start.size(); i++)
    {
        dp[i] = max(pair[i][2], dp[i - 1]);
        for (int j = i - 1; j >= 0; j--)
            if (pair[j][1] <= pair[i][0])
            {
                dp[i] = max(dp[i], dp[j] + pair[i][2]);
                break;
            }
        max_ = max(max_, dp[i]);
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