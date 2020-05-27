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

int Method_01(vector<int> &A, int k)
{
    int n = A.size();
    int ei = 0, si = 0, count = 0, sum = 0;

    while (ei < n)
    {
        sum += A[ei++];
        while (si < ei && sum > k)
            sum -= A[si++];

        count += ei - si;
    }

    return count;
}

//method_02.=========================================

int Method_02(vector<int> &A, int k)
{
    int n = A.size();
    int count = 0, sum = 0;
    unordered_map<int, int> map;
    map[0] = 1;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        count += map[sum - k];
        map[sum]++;
    }

    return count;
}

int numSubarraysWithSum(vector<int> &A, int S)
{
    // return Method_01(A, S) - Method_01(A, S - 1);
    return method_02(A, S);
}