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

ListNode *mergeTwoLinkedList(ListNode *A, ListNode *B)
{
    if (A == nullptr)
        return B;
    else if (B == nullptr)
        return A;

    ListNode *head = new ListNode(-1);
    ListNode *curr = head;

    while (A != nullptr && B != nullptr)
    {
        if (A->val <= B->val)
        {
            curr->next = A;
            curr = A;
            A = A->next;
        }
        else
        {
            curr->next = B;
            curr = B;
            B = B->next;
        }
    }

    if (A != nullptr)
        curr->next = A;
    else if (B != nullptr)
        curr->next = B;

    return head->next;
}

ListNode *mergeKLists_(vector<ListNode *> &lists, int si, int ei)
{
    if (si == ei)
        return lists[si];
    else if (si + 1 == ei)
        return mergeTwoLinkedList(lists[si], lists[ei]);

    int mid = (si + ei) >> 1;
    ListNode *left = mergeKLists_(lists, si, mid);
    ListNode *right = mergeKLists_(lists, mid + 1, ei);

    return mergeTwoLinkedList(left, right);
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return nullptr;

    return mergeKLists_(lists, 0, lists.size() - 1);
}
