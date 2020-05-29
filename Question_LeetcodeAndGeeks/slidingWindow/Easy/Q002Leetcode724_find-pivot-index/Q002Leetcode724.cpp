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

int pivotIndex(vector<int> &nums)
{
    int rightSum = 0, leftSum = 0, n = nums.size();
    
    for (int &ele : nums)
        rightSum += ele;
    
    for (int i = 0; i < n; i++)
    {
        if (rightSum - leftSum - nums[i] == 0)
            return i;
        leftSum += nums[i];
        rightSum -= nums[i];
    }
    return -1;
}