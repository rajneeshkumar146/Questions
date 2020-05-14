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

void combinationSum02_(vector<int> &arr, int idx, int target)
{
    if (target == 0)
    {
        res.push_back(ans);
        return;
    }

    int prev = -1;
    for (int i = idx; i < arr.size(); i++)
    {
        if (prev == arr[i])
            continue;
        if (target - arr[i] < 0)
            break;
        ans.push_back(arr[i]);
        combinationSum02_(arr, i+1, target - arr[i]);
        ans.pop_back();
        
        prev=arr[i];
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    combinationSum02_(candidates, 0, target);
    return res;
}