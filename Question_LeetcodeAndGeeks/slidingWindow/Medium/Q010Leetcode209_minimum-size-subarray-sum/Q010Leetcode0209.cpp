// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <dequeue>
#include <multiset>
#include <queue>
#include <unordered_map>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

//method_01.=========================================

//method_01.=========================================

int Mathod_01(vector<int> &A, int k)
{
    int n = A.size();
    int ei = 0, si = 0, len = 1e9, sum = 0;

    while (ei < n)
    {
        sum += A[ei++];

        if (sum >= k)
        {
            while (si < ei && sum >= k)
            {
                len = min(len, ei - si);
                sum -= A[si++];
            }
        }
    }

    return len != 1e9 ? len : 0;
}

int minSubArrayLen(int s, vector<int> &nums)
{
    return Mathod_01(nums, s);
}