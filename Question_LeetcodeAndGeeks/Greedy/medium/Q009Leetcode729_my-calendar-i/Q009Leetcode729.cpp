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


//solution01.==========================================
// fast solution.
class MyCalendar
{
public:
    map<int, int> bst;
    MyCalendar()
    {
        bst.clear();
    }

    bool book(int start, int end)
    {
        auto ub = bst.upper_bound(start);
        if (ub != bst.end() && end > (*ub).second)
            return false;
        bst.insert({end, start});
        return true;
    }
};

//solution02.===============================================
// easy but time taking.
class MyCalendar
{
public:
    map<int, int> bst;
    MyCalendar()
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
            if (count > 1)
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
