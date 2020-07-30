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

ListNode *middleNodeByINDEX(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode *mergeTwoLists(ListNode *A, ListNode *B)
{
    if (A == nullptr)
        return B;
    if (B == nullptr)
        return A;

    ListNode *head = new ListNode(0); // dummyNode;
    ListNode *curr = head;

    while (A != nullptr && B != nullptr)
    {
        if (A->val <= B->val)
        {
            curr->next = A;
            A = A->next;
        }
        else
        {
            curr->next = B;
            B = B->next;
        }
        curr = curr->next;
    }

    if (A != nullptr)
        curr->next = A;
    else if (B != nullptr)
        curr->next = B;

    return head->next;
}

ListNode *sortList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *mid = middleNodeByINDEX(head);
    ListNode *nhead = mid->next;
    mid->next = nullptr;

    ListNode *a = sortList(head);
    ListNode *b = sortList(nhead);
    return mergeTwoLists(a, b);
}