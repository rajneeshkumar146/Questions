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

ListNode *OddEvenListByValue(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *even = new ListNode(-1);
    ListNode *eitr = even;

    ListNode *odd = new ListNode(-1);
    ListNode *oitr = odd;

    while (head != nullptr)
    {
        if (head->val % 2 == 0)
        {
            eitr->next = head;
            eitr = eitr->next;
        }
        else
        {
            oitr->next = head;
            oitr = oitr->next;
        }
        head = head->next;
    }

    oitr->next = nullptr;
    eitr->next = odd->next;
    return even->next;
}

void constructLL()
{
    int n;
    cin >> n;
    ListNode *head = new ListNode(-1);
    ListNode *curr = head;

    while (n--)
    {
        int val;
        cin >> val;
        ListNode *node = new ListNode(val);
        curr->next = node;
        curr = curr->next;
    }

    head = OddEvenListByValue(head->next);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
        constructLL();
}

int main()
{
    solve();
    return 0;
}