// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int i = -1, idx = 0, j = n;

    while (idx < j)
    {
        if (nums[idx] == 0)
        {
            swap(nums[idx], nums[++i]);
            idx++;
        }
        else if (nums[idx] == 2)
            swap(nums[idx], nums[--j]);
        else
            idx++;
    }
}