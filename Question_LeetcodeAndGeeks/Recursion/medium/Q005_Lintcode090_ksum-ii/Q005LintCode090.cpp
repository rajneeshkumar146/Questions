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

void combinationSum03_(vector<int> &A, int idx, int k, int target) // previous number
{
    if (k == 0)
    {
        if (target == 0)
            res.push_back(ans);
        return;
    }

    for (int i = idx; i < A.size(); i++)
    {
        if (target - A[i] < 0)
            break;
        ans.push_back(A[i] );
        combinationSum03_(A, i + 1, k - 1, target - A[i]);
        ans.pop_back();
    }
}

vector<vector<int>> kSumII(vector<int> &A, int k, int target)
{
    combinationSum03_(A, 0, k, target);
    return res;
}