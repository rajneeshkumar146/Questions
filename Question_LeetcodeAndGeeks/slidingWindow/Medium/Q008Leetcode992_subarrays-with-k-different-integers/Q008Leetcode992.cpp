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

//Link 1: https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/523136/JavaC%2B%2BPython-Sliding-Window

//method_01.=========================================

int atMostKDistinct(vector<int> &A, int k)
{
    int n = A.size();
    int si = 0, ei = 0, count = 0, res = 0;
    vector<int> freq(20002, 0);
    while (ei < n)
    {
        if (freq[A[ei++]]++ == 0)
            count++;

        while (count > k)
            if (freq[A[si++]]-- == 1)
                count--;

        res += ei - si;
    }
    return res;
}

//Link: https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/235235/C%2B%2BJava-with-picture-prefixed-sliding-window

//method_02.=========================================
int subarraysWithKDistinct_(vector<int> &A, int k)
{
    int n = A.size();
    int si = 0, ei = 0, count = 0, res = 0, prefix = 0;
    vector<int> freq(20002, 0);
    while (ei < n)
    {
        if (freq[A[ei++]]++ == 0)
            count++;

        if (count > k)
            freq[A[si++]]--, count--, prefix = 0;

        while (freq[A[si]] > 1)
        {
            freq[A[si++]]--;
            prefix++;
        }

        if (count == k)
            res += prefix + 1;
    }
    return res;
}

int subarraysWithKDistinct(vector<int> &A, int k)
{
    // return atMostKDistinct(A, k) - atMostKDistinct(A, k - 1);
    return subarraysWithKDistinct_(A, k);
}