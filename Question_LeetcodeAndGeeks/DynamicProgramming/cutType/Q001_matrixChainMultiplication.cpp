// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

void display(vii &dp)
{
    for (vi ar : dp)
    {
        for (int ele : ar)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}

int mcmRec(vi &arr, int i, int j, vii &dp)
{
    if (i == j)
        return 0;

    if (dp[i][j] != 0)
        return dp[i][j];

    int mincost = INT_MAX;
    for (int idx = i; idx < j; idx++)
    {
        int firstPart = mcmRec(arr, i, idx, dp);
        int secondPart = mcmRec(arr, idx + 1, j, dp);

        int cost = firstPart + arr[i - 1] * arr[idx] * arr[j] + secondPart;
        if (cost < mincost)
            mincost = cost;
    }

    dp[i][j] = mincost;

    return mincost;
}

int mcmDp(vi &arr)
{
    vii dp(arr.size(), vi(arr.size(), 0));

    for (int gap = 2; gap < arr.size(); gap++)
    {
        for (int i = 0, j = i + gap; j < arr.size(); i++, j++)
        {
            dp[i][j] = INT_MAX;
            for (int cut = i + 1; cut < j; cut++)
            {
                dp[i][j] = min(dp[i][j], dp[i][cut] + arr[i] * arr[cut] * arr[j] + dp[cut][j]);
            }
        }
    }

    display(dp);

    return dp[0][arr.size() - 1];
}

void solve()
{
    // int size; cin >> size;
    //     vi arr(size,0);
    //     for(int i=0;i<size;i++) cin>>arr[i];

    vi arr = {1, 2, 3, 4, 5};   //30
    // vi arr = {40, 20, 30, 10, 30}; //26000

    vii dp(arr.size(), vi(arr.size(), 0));
    // cout << mcmRec(arr, 1, arr.size() - 1, dp) << endl;

    // display(dp);

    cout << mcmDp(arr) << endl;
}
int main()
{
    // int t;
    // cin >> t;
    // while (t-- > 0)
        solve();
    return 0;
}
