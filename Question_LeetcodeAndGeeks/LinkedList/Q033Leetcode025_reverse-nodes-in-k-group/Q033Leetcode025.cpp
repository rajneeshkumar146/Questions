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
ListNode *oH = nullptr, *oT = nullptr;

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

int length(ListNode *node)
{
    int len = 0;
    while (node != nullptr)
    {
        node = node->next;
        len++;
    }
    return len;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == nullptr || head->next == nullptr || k == 0 || k == 1)
        return head;

    int len = length(head);
    if (len < k)
        return head;

    ListNode *curr = head;
    while (curr != nullptr && len >= k)
    {
        int temp = k;
        while (temp-- > 0)
        {
            ListNode *rnode = curr;
            curr = curr->next;
            rnode->next = nullptr;

            addFirstNode(rnode);
        }

        if (oH == nullptr)
        {
            oH = tH;
            oT = tT;
        }
        else
        {
            oT->next = tH;
            oT = tT;
        }

        tH = nullptr;
        tT = nullptr;

        len -= k;
    }

    oT->next = curr;
    return oH;
}