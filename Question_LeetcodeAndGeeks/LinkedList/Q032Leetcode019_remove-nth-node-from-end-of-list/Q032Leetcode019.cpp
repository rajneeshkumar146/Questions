// #include <bits/stdc++->h>
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

static const auto magic = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (n == 0 || head == nullptr)
        return head;
    if (n == 1 && head->next == nullptr)
        return nullptr;

    ListNode *slow = head, *fast = head;
    while (n-- > 0)
    {
        fast = fast->next;
    }

    if (fast == nullptr)
        return slow->next;

    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode *forw = slow->next;
    slow->next = slow->next->next;
    forw->next = nullptr;
    return head;
}