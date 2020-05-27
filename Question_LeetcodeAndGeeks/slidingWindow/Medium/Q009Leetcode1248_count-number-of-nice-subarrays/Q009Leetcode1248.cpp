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

//Link 1: https://leetcode.com/problems/count-number-of-nice-subarrays/discuss/419378/JavaC%2B%2BPython-Sliding-Window-atMost(K)-atMost(K-1)

//method_01.=========================================

int atMostK_ODD(vector<int> &A, int k)
{
    int n = A.size();
    int si = 0, ei = 0, count = 0, res = 0;
    while (ei < n)
    {
        if ((A[ei++] & 1))
            count++;

        while (count > k)
            if ((A[si++] & 1))
                count--;

        res += ei - si;
    }
    return res;
}

//Link: https://leetcode.com/problems/count-number-of-nice-subarrays/discuss/419545/JavaC%2B%2B-with-picture-deque

//method_02.=========================================
int numberOfNiceSubarrays(vector<int> &A, int k)
{
    int n = A.size();
    int si = 0, ei = 0, count = 0, res = 0, prefix = 0;
    while (ei < n)
    {
        if ((A[ei++] & 1))
            count++;

        if (count > k)
            if ((A[si++] & 1))
                count--, prefix = 0;

        while (si < ei && !(A[si] & 1))
            prefix++,si++;

        if (count == k)
            res += prefix + 1;
    }
    return res;
}

int numberOfSubarrays(vector<int> &A, int k)
{
    return atMostK_ODD(A, k) - atMostK_ODD(A, k - 1);
    // return numberOfNiceSubarrays(A, k);
}