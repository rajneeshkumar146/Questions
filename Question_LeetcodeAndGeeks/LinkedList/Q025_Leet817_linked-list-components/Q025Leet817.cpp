// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int numComponents(ListNode *head, vector<int> &G)
{
    unordered_set<int> map;
    for (const int &ele : G)
        map.insert(ele);

    int count = 0;
    while (head != nullptr)
    {
        if (map.find(head->val) != map.end() && 
            (head->next == nullptr || map.find(head->next->val) == map.end()))
            count++;
        head = head->next;
    }
    return count;
}
