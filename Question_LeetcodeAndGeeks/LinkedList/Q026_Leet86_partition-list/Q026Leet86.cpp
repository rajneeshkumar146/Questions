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

ListNode *partition(ListNode *head, int x)
{
    ListNode *small = new ListNode(-1);
    ListNode *curr1 = small;

    ListNode *larger = new ListNode(-1);
    ListNode *curr2 = larger;

    while (head != nullptr)
    {
        if (head->val < x)
        {
            curr1->next = head;
            curr1 = head;
        }
        else
        {
            curr2->next = head;
            curr2 = head;
        }
        head = head->next;
    }

    curr2->next = nullptr;
    curr1->next = larger->next;
    return small->next;
}