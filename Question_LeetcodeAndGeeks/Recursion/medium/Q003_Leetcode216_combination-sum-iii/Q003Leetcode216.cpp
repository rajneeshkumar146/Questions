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

vector<vector<int>> res;
vector<int> ans;

void combinationSum03_(int k, int pnum, int target) // previous number
{
    if (k == 0)
    {
        if (target == 0)
            res.push_back(ans);
        return;
    }

    for (int num = pnum; num <= 9; num++)
    {
        if (target - num < 0)
            break;
        ans.push_back(num);
        combinationSum03_(k - 1, num + 1, target - num);
        ans.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    combinationSum03_(k, 1, n);
    return res;
}