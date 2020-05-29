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
    if (n <= 1)
        return n;
    int si = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[si] != nums[i])
            nums[++si] = nums[i];
    }
    return si + 1;
}