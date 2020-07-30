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

ListNode *tH = nullptr, *tT = nullptr;

void addFirstNode(ListNode *node)
{
    if (tT == nullptr)
    {
        tH = node;
        tT = node;
    }
    else
    {
        node->next = tH;
        tH = node;
    }
}

ListNode *reverseBetween(ListNode *head, int m, int n)
{
    if (head == nullptr || head->next == nullptr || n == m)
        return head;

    int i = 1;
    ListNode *curr = head;
    ListNode *prev = nullptr;

    while (curr != nullptr)
    {
        while (i >= m && i <= n)
        {
            ListNode *rnode = curr;
            curr = curr->next;
            rnode->next = nullptr;
            addFirstNode(rnode);
            i++;
        }

        if (i > n)
        {
            if (prev != nullptr)
                prev->next = tH;
            else
                head = tH;
            tT->next = curr;
            break;
        }

        prev = curr;
        curr = curr->next;
        i++;
    }

    return head;
}