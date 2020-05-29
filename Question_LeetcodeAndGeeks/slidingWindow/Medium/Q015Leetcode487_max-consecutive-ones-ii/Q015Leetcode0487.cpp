// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <dequeue>
#include <multiset>
#include <queue>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int n = nums.size();
    int si = 0, ei = 0, count = 0, len = 0;

    while (ei < n)
    {
        if (nums[ei++] == 0)
            count++;

        while (count > 1)
            if (nums[si++] == 0)
                count--;

        len = max(len, ei - si);
    }
    return len;
}