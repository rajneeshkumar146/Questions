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

class Node
{
public:
    int val;
    Node *next;

    Node() {}

    Node(int _val)
    {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node *_next)
    {
        val = _val;
        next = _next;
    }
};

Node *insert(Node *head, int insertVal)
{
    if (head == nullptr)
    {
        Node *node = new Node(insertVal);
        node->next = node;
        return node;
    }

    Node *prev = head;
    Node *curr = head->next;
    Node *node = new Node(insertVal);

    bool connect = false;
    while (curr != head)
    {
        if (prev->val <= insertVal && insertVal <= curr->val)
            connect = true;
        else if (prev->val > curr->val)
            if (insertVal >= prev->val || insertVal <= curr->val)
                connect = true;

        if (connect)
        {
            node->next = curr;
            prev->next = node;
            return head;
        }

        prev = curr;
        curr = curr->next;
    }

    node->next = curr;
    prev->next = node;

    return insertVal >= prev->val ? head : node;
}