// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int characterReplacement(string s, int k)
{
    int n = s.length();
    int ei = 0, si = 0, count = 0, MaxSameChar = 0;
    vector<int> freq(128, 0);
    while (ei < n)
    {
        MaxSameChar = max(MaxSameChar, ++freq[s[ei++]]);
        if ((ei - si) - MaxSameChar > k)
            freq[s[si++]]--;
    }
    return ei - si;
}