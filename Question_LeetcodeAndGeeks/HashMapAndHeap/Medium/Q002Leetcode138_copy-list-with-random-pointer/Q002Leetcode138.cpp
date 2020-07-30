// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//Solution_02.
Node *copyRandomList(Node *head)
{

    copyList(head);
    setRandomPointers(head);
    return extractLL(head);
}

//Step 01 : CopyList
void copyList(Node *node)
{
    Node *curr = node;
    while (curr != nullptr)
    {
        Node *forw = curr->next;
        Node *node = new Node(curr->val);

        curr->next = node;
        node->next = forw;

        curr = forw;
    }
}

void setRandomPointers(Node *node)
{
    Node *curr = node;
    while (curr != nullptr)
    {
        if (curr->random != nullptr)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }
}

Node *extractLL(Node *node)
{
    Node *head = new Node(-1);
    Node *curr1 = node;
    Node *curr2 = head;
    while (curr1 != nullptr)
    {
        Node *forw = curr1->next->next;

        Node *copyNode = curr1->next;
        curr1->next = forw;
        curr2->next = copyNode;

        curr2 = copyNode;
        curr1 = forw;
    }

    return head->next;
}