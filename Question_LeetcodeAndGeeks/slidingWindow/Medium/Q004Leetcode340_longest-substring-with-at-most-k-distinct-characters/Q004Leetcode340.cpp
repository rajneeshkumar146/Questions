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

int lengthOfLongestSubstringKDistinct(string s, int k)
{
    int n = s.length();
    vector<int> freq(128, 0);
    int si = 0, ei = 0, count = 0, len = 0;
    while (ei < n)
    {
        if (freq[s[ei++]]++ == 0)
            count++;
        while (count > k)
            if (freq[s[si++]]-- == 1)
                count--;
        len = max(len, ei - si);   // while loop se bahar hone ki wajh se ye 'k' ya usse kam ki length ko calculate krega.
    }
    return len;
}
