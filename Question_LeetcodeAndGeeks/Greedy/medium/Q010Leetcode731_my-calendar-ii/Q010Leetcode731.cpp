// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

static const auto magic = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class MyCalendarTwo
{
public:
    map<int, int> bst;
    MyCalendarTwo()
    {
        bst.clear();
    }

    bool book(int start, int end)
    {
        bst[start]++;
        bst[end]--;

        int count = 0;
        for (auto &key : bst)
        {
            count += key.second;
            if (count > 2)
            {
                bst[start]--;
                bst[end]++;
                if (bst[start] == 0)
                    bst.erase(start);
                if (bst[end] == 0)
                    bst.erase(end);

                return false;
            }
        }
        return true;
    }
};
