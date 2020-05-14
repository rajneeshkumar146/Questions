// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int kSum(vector<int> &A, int idx, int k, int target, vector<vector<int>> &dp)
{
    if (k == 0)
        return dp[k][target] = 1 = target == 0 ? 1 : 0;
    
}

int kSum(vector<int> &A, int k, int target)
{
}