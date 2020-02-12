#include <iostream>
#include <vector>
#include <unordered_map>

#define pb(val) push_back(val)

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *random;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

void copyTree(Node *node)
{
    if (node == nullptr)
        return;

    Node *nnode = new Node(node->data);
    nnode->left = node->left;
    node->left = nnode;

    copyTree(node->left->left);
    copyTree(node->right);
}

void copyRandoms(Node *node)
{
    if (node == nullptr)
        return;

    Node *rnode = node->random;
    node->left->random = rnode->left;

    copyRandoms(node->left->left);
    copyRandoms(node->right);
}

Node *extractTree(Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    Node *rnode = node->left;
    Node *oLeftTree = rnode->left;

    Node *cLeftTree = extractTree(node->left->left);
    Node *cRightTree = extractTree(node->right);

    rnode->left = cLeftTree;
    rnode->right = cRightTree;

    node->left = oLeftTree;

    return rnode;
}
