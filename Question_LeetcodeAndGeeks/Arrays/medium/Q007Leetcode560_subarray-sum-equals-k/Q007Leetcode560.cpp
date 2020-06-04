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

//using prefix sum.O(n2)===========================================
int subarraySum_01(vector<int> &nums, int k)
{
    int n = nums.size();
    for (int i = 1; i < n; i++) //prefix sum.
        nums[i] += nums[i - 1];

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= -1; j--)
            if (nums[i] - (j != -1 ? nums[j] : 0) == k)
                count++;
    }
    return count;
}

// using_hashMap_O(n)==============================================

int subarraySum_02(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    map[0] = 1;
    int count = 0, sum = 0;
    for (int ele : nums)
    {
        sum += ele;
        count += map[sum - k];
        map[sum]++;
    }
    return count;
}

int subarraySum(vector<int> &nums, int k)
{
    return subarraySum_01(nums, k);
    // return subarraySum_02(nums, k);
}