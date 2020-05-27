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

int totalFruit_(vector<int> &arr)
{
    int n = arr.size();
    int si = 0, ei = 0, count = 0, len = 0;
    vector<int> freq(40002, 0); // 1 <= arr.length, arr[i] <= 40000

    while (ei < n)
    {
        if (freq[arr[ei++]]++ == 0)
            count++;

        while (count > 2)
        {
            if (freq[arr[si++]]-- == 1)
                count--;
        }
        len = max(len, ei - si);
    }
    return len;
}

int totalFruit(vector<int> &tree)
{
    return totalFruit_(tree);
}