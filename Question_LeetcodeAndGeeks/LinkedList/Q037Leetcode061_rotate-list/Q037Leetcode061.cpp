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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *rotateRight(ListNode *head, int k)
{
    if (head == nullptr || head->next == nullptr || k == 0)
        return head;

    ListNode *tail = head;
    int len = 1;
    while (tail->next != nullptr)
        tail = tail->next, len++;

    k %= len;
    if (k == 0)
        return head;

    ListNode *slow = head, *fast = head; // remove nth node from last concept.
    while (k--)
        fast = fast->next;

    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    tail->next = head;
    head = slow->next;
    slow->next = nullptr;

    return head;
}