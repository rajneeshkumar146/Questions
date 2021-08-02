// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> dp;
int minJumps(vector<int> &arr, int idx, string ans)
{
    if (idx == arr.size())
    {
        cout << ans << endl;
        return 0;
    }

    if (dp[idx] != 0)
        return dp[idx];

    int minCost = 1e8;
    if (idx - 1 >= 0)
        minCost = min(minCost, minJumps(arr, idx - 1, ans + to_string(arr[idx])) + arr[idx]);
    if (idx + 2 < arr.size())
        minCost = min(minCost, minJumps(arr, idx + 2, ans + to_string(arr[idx])) + arr[idx]);

    return dp[idx] = minCost;
}

void solve()
{
    vector<int> arr ={ 2, 8, 3, 6, 9, 3, 0, 0, 1, 3,0};
    dp.resize(arr.size(),0);

    cout<<minJumps(arr,0,"")<<endl;

    
}

int main()
{
    solve();
    return 0;
}