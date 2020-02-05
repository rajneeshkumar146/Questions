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

void mcmDp(vi &arr)
{
    vii dp(arr.size(), vi(arr.size(), 0));
    vector<vector<string>> ans(arr.size(), vector<string>(arr.size(), ""));

    for (int i = 0, j = 1; j < arr.size(); i++, j++)
        ans[i][j] = string(1, (char)('A' + i));

    for (int gap = 2; gap < arr.size(); gap++)
    {
        for (int i = 0, j = i + gap; j < arr.size(); i++, j++)
        {
            string smallAns;
            int minAns = INT_MAX;

            for (int cut = i + 1; cut < j; cut++)
            {
                int val = dp[i][cut] + arr[i] * arr[cut] * arr[j] + dp[cut][j];
                if (val < minAns)
                {
                    minAns = val;
                    smallAns="("+ans[i][cut]+ans[cut][j]+")";
                }
            }

            dp[i][j] = minAns;
            ans[i][j] = smallAns;
        }
    }

    cout<<dp[0][arr.size()-1] <<" "<<ans[0][arr.size()-1]<<endl;
}

void solve()
{
    // int size;
    // cin >> size;
    // vi arr(size, 0);
    // for (int i = 0; i < size; i++)
    //     cin >> arr[i];

    vi arr = {1, 2, 3, 4, 5};   //30
    // vi arr = {40, 20, 30, 10, 30}; //26000

    mcmDp(arr);


}
int main()
{
    // int t;
    // cin >> t;
    // while (t-- > 0)
        solve();
    return 0;
}
