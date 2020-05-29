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

//method_01.====================================================
void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int j = 0;
    for (int i = 0; i < n; i++, j++)
    {
        if (nums[i] == 0)
        {
            while (j < n && nums[j] == 0)
                j++;
            
            if (j < n)
                swap(nums[i], nums[j]);
        }
    }
}

//method_02.====================================================
void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if(nums[i]!=0) swap(nums[i],nums[j++]);
    }
}

