#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

#define vi vector<int>
#define vii vector<vi>

vii dp(1000, vi(100000, -1));
int maximumCoins(int idx, int ie, vi &energy, vi &coins)
{
    if (idx == coins.size())
        return dp[idx][ie] = 0;
    if (dp[idx][ie] != 0)
        return dp[idx][ie];
    if (ie == 0)
    {
        return dp[idx][ie] = maximumCoins(idx + 1, ie + energy[idx] - 1, coins);
    }
    else
    {
        int a = maximumCoins(idx + 1, ie - 1, coins, dp) + coins[idx];
        int b = maximumCoins(idx + 1, ie + energy[idx] - 1, coins);
        return dp[idx][ie] = max(a, b);
    }
}

int minTime(vector<int> &processTime, vector<int> &taskTime)
{
    sort(taskTime.begin(), taskTime.end());
    sort(processTime.begin(), processTime.end());

    int idx = taskTime.size() - 1;
    int ans = 0;
    for (int ele : processTime)
    {
        ans = max(ans, ele + taskTime[idx]);
        idx-=4;
        if(idx<0) break;
    }
    return ans;
}

int main()
{
    vector<int> a{2, 1, 1};
    vector<int> b{11, 5, 7};
    cout <<

        return 0;
}
