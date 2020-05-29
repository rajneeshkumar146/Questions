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

int longestOnes_(vector<int> &arr, int k)
{
    int n = arr.size();
    int si = 0, ei = 0, count = 0, len = 0;

    while (ei < n)
    {
        if (arr[ei++] == 0)
            count++;

        while (count > k)
            if (arr[si++] == 0)
                count--;

        len = max(len, ei - si);
    }
    return len;
}

int longestOnes(vector<int> &A, int K)
{
    return longestOnes_(A, K);
}