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

int lengthOfLongestSubstringTwoDistinct(string s)
{
    int n = s.length();
    vector<int> freq(128, 0);
    int si = 0, ei = 0, count = 0, len = 0;
    while (ei < n)
    {
        if (freq[s[ei++]]++ == 0)
            count++;
        while (count > 2)
            if (freq[s[si++]]-- == 1)
                count--;
        len = max(len, ei - si);
    }
    return len;
}
