// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr || l2 == nullptr)
        return l1 == nullptr ? l2 : l1;

    ListNode *head = new ListNode(-1); // dummy Node.
    ListNode *prev = head;

    ListNode *c1 = l1, *c2 = l2;

    while (c1 != nullptr && c2 != nullptr)
    {
        if (c1->val <= c2->val)
        {
            prev->next = c1;
            prev = c1;
            c1 = c1->next;
        }
        else
        {
            prev->next = c2;
            prev = c2;
            c2 = c2->next;
        }
    }

    if (c2 != nullptr)
        prev->next = c2;
    else
        prev->next = c1;

    return head->next;
}