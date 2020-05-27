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
vector<int> ans;

//using PQ -> (NlogN)=============================

void method_01(vector<int> &nums, int k)
{
    int n = nums.size();
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        while (pq.size() != 0 && pq.top().second <= i - k)
            pq.pop();

        pq.push({nums[i], i});
        if (i >= k - 1)
            ans.push_back(pq.top().first);
    }
}

//using MultiSet->NlogK.======================================

void method_02(vector<int> &nums, int k)
{

    int n = nums.size();
    multiset<int> set;
    for (int i = 0; i < n; i++)
    {
        if (i >= k)
            set.erase(set.find(nums[i - k]));

        set.insert(nums[i]);
        if (i >= k - 1)
            ans.push_back(*set.rbegin());
    }
}

//using dqueue ->O(N).===============================

void method_03(vector<int> &nums, int k)
{
    int n = nums.size();
    deque<int> que;
    for (int i = 0; i < n; i++)
    {
        while (que.size() != 0 && i - k > que.front())
            que.pop_front();
        while (que.size() != 0 && nums[que.back()] <= nums[i])
            que.pop_back();

        que.push_back(i);
        if (i >= k - 1)
            ans.push_back(nums[que.front()]);
    }
}

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    if (nums.size() <= 1 || k <= 1)
        return nums;
    // method_01(nums,k);
    // method_02(nums, k);
    method_03(nums, k);

    return ans;
}