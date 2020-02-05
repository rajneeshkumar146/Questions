#include <iostream>
#include <vector>
using namespace std;

int numSquares_(int tar)
{
    vector<int> dp(tar + 1, 1e8);
    dp[0] = 0;
    for (int t = 1; t <= tar; t++)
    {
        for (int i = 1; i * i <= t; i++)
        {
            if (t - i * i >= 0)
                dp[t] = min(dp[t], dp[(t - i * i)] + 1);
        }
    }

    return dp[tar] == 1e8 ? -1 : dp[tar];
}

void solve()
{
    int n;
    cin >> n;
    cout << numSquares_(n) << endl;
}

int main()
{
    solve();
    return 0;
}