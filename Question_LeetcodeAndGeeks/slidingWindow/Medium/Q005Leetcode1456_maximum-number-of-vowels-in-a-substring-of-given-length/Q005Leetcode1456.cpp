// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <list>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

bool isVowels(char ch)
{
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

//using circular Queue.=======================================================
int maxVowels(string s, int k)
{
    list<int> que;
    int si = 0, ei = 0, count = 0, len = 0, n = s.length();
    while (ei < n)
    {
        que.push_back(ei);
        if (isVowels(s[ei++]))
            count++;

        if (que.size() == k)
        {
            len = max(len, count);
            if (isVowels(s[que.front()]))
                count--;
            que.pop_front();
        }
    }

    return len;
}

//using two pointers.=======================================================
int maxVowels_02(string s, int k)
{
    int si = 0, ei = 0, count = 0, len = 0, n = s.length();
    while (ei < n)
    {
        if (isVowels(s[ei++]))
            count++;

        if (ei - si == k)
        {
            len = max(len, count);
            if (isVowels(s[si++]))
                count--;
        }
    }

    return len;
}