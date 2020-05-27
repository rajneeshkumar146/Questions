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

//method_01_=================================================================
string minWindow(string s, string t)
{
    int ns = s.length();
    int ts = t.length();
    int freq[128] = {0};
    for (int i = 0; i < ts; i++)
        freq[t[i]]++;

    int count = ts;
    int si = 0, ei = 0, len = 1e9;
    int head = 0;

    while (ei < ns)
    {
        if (freq[s[ei]] > 0)
            count--;
        freq[s[ei]]--;
        ei++;

        while (count == 0)
        {
            if (ei - si < len)
            {
                len = ei - si;
                head = si;
            }

            if (freq[s[si]] == 0)
                count++;
            freq[s[si]]++;
            si++;
        }
    }

    return len == 1e9 ? "" : s.substr(head, len);
}

//method_02_=================================================================
string minWindow_02(string s, string t)
{
    int ns = s.length();
    int ts = t.length();
    int freq[128] = {0};
    for (int i = 0; i < ts; i++)
        freq[t[i]]++;

    int count = ts;
    int si = 0, ei = 0, len = 1e9;
    int head = 0;

    while (ei < ns)
    {
        if (freq[s[ei++]]-- > 0)
            count--;

        while (count == 0)
        {
            if (ei - si < len)
                len = (ei - (head = si));

            if (freq[s[si++]]++ == 0)
                count++;
        }
    }

    return len == 1e9 ? "" : s.substr(head, len);
}
