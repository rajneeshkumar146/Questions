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

ListNode *detectCycle(ListNode *head)
{
    ios_base::sync_with_stdio(false);
    if (head == nullptr || head->next == nullptr)
        return nullptr;

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    if (slow == fast)
    {
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

    return nullptr;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{

    if (headA == nullptr || headB == nullptr)
        return nullptr;
    if (headA->next == nullptr && headB->next == nullptr && headA->val == headB->val)
        return headA;

    ListNode *tail = nullptr;
    ListNode *curr = headA;
    while (curr != nullptr)
    {
        tail = curr;
        curr = curr->next;
    }

    tail->next = headB; //cycle

    ListNode *ans = detectCycle(headA);
    tail->next = nullptr;
    return ans != nullptr ? ans : nullptr;
}
