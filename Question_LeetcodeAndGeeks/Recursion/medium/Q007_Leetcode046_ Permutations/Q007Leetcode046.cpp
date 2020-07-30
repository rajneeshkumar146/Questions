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

vector<vector<int>> ans;
vector<int> sans;

void permute(vector<int> &nums, vector<bool> &vis, int count)
{
    if (count == nums.size())
    {
        ans.push_back(sans);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            sans.push_back(nums[i]);
            permute(nums, vis, count + 1);
            sans.pop_back();
            vis[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    if (nums.size() == 0)
        return ans;
    vector<bool> vis(nums.size(), false);
    permute(nums, vis, 0);
}