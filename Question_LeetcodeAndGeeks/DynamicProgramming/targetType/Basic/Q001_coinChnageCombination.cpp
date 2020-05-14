// #include <cstdlib>
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

int coinChangeRec(vi &coins, int vidx, int target)
{
    if (target <= 0)
        return target == 0 ? 1 : 0;

    int count = 0;
    for (int i = vidx; i < coins.size(); i++)
    {
        if (target - coins[i] >= 0)
            count += coinChangeRec(coins, i, target - coins[i]);
    }

    return count;
}

int coinChangeDP(vector<int> &coins, int target)
{
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int cidx = 0; cidx < coins.size(); cidx++)
        for (int i = 1; i < dp.size(); i++)
        {
            dp[i] += i - coins[cidx] >= 0 ? dp[i - coins[cidx]] : 0;
        }

    return dp[target];
}

void solve()
{
    vi coins = {2, 3, 5};

    cout << coinChangeRec(coins, 0, 100) << endl;
    cout << coinChangeDP(coins, 100) << endl;
}

int main()
{
    solve();
    return 0;
}