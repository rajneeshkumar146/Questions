// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

// https://cp-algorithms.com/data_structures/sqrt_decomposition.html

int bs, n; // bs: block size, n is input.
vector<int> blocks,arr;

void Build()
{
    bs = (int)sqrt(n + 0.0) + 1;
    blocks.resize(bs,0);

    for (int i = 0; i < arr.size(); i++)
        blocks[i / bs] += arr[i];
}

long query(int li, int ri)
{
    long sum = 0;
    while (li < ri && li % bs != 0 && li != 0)
        sum += arr[li++];

    while (li + bs <= ri)
    {
        sum += blocks[li / bs];
        li += bs;
    }
    while (li <= ri)
        sum += arr[li++];

    return sum;
}

int update(int idx, int value)
{
    blocks[idx / bs] += value - arr[idx];
    arr[idx] = value;
}

void solve()
{
    arr.clear();
    blocks.clear();

    vector<int> input = {1, 2, 6, 7, 9, 3, 1, 9}; //{1,5,2,4,6,1,3,5,7};
    n=input.size();
    for(int ele: input) arr.push_back(ele);

    Build();

    cout << query(1, 6) << endl;
    update(5, 7);
    cout << query(2, 6) << endl;

    
}

int main()
{
    solve();
    return 0;
}