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

int lengthOfLongestSubstring(string s)
{
    if (s.length() <= 1)
        return s.length();
    unordered_map<char, int> lastIndex;
    int st = -1;
    int len = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (lastIndex.count(s[i]) != 0)
            st = max(st, lastIndex[s[i]]);

        lastIndex[s[i]] = i;
        len = max(len, i - st);
    }
    return len;
}

//method02.=====================================================
int lengthOfLongestSubstring_02(string s)
{
    if (s.length() <= 1)
        return s.length();
    vector<int> map(128, 0);
    int si = 0, ei = 0, count = 0;
    int len = 0;
    while (ei < s.length())
    {
        if (map[s[ei++]]++ > 0)
            count++; // idhar mene phele hi ei increase krdiya hai so length easily ayegi by ei-si;
        while (count > 0)
            if (map[s[si++]]-- > 1)
                count--;
        len = max(len, ei - si);
    }

    return len;
}