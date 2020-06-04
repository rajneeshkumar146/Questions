// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

static const auto magic = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

//Greedy: O(n) Solution.================================================
bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int maxPossibleJump = 0;
    for (int i = 0; i < n; i++)
    {
        if (maxPossibleJump < i)
            return false;
        maxPossibleJump = max(maxPossibleJump, i + nums[i]);
    }

    return true;
}