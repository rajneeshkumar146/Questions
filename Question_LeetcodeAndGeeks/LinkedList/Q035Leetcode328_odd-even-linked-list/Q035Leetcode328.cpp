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

ListNode *oddEvenList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *ehead = head->next;
    ListNode *curr1 = head;
    ListNode *curr2 = head->next;
    while (curr1->next != nullptr && curr2->next != nullptr)
    {

        curr1->next = curr2->next;
        curr1 = curr2->next;

        curr2->next = curr1->next;
        curr2 = curr1->next;
    }

    curr1->next = ehead;
    return head;
}