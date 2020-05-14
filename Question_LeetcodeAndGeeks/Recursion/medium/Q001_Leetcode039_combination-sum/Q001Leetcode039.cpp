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

void combinationSum_(vector<int> &arr, int idx, int target)
{
    if (target == 0)
    {
        res.push_back(ans);
        return;
    }

    for (int i = idx; i < arr.size(); i++)
    {
        if (target - arr[i] < 0)
            break;
        ans.push_back(arr[i]);
        combinationSum_(arr, i, target - arr[i]);
        ans.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    combinationSum_(candidates, 0, target);
    return res;
}
