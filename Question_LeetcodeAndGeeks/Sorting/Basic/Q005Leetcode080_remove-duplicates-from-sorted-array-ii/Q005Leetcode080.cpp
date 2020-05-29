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

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 2)
        return n;
    int si = 2;
    for (int i = 2; i < n; i++)
    {
        if (nums[i] != nums[si - 2])
            nums[si++] = nums[i];
    }
    return si;
}