// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <stack>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std:: cout.tie(nullptr);
    return nullptr;
}();

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void putAllLeft(TreeNode *node, stack<TreeNode *> &st)
{
    while (node != nullptr)
    {
        st.push(node);
        node = node->left;
    }
}

vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
{
    stack<TreeNode *> st1, st2;
    putAllLeft(root1, st1);
    putAllLeft(root2, st2);

    vector<int> ans;
    while (st1.size() != 0 && st2.size() != 0)
    {
        if (st1.top()->val < st2.top()->val)
        {
            ans.push(st1.top()->val);
            TreeNode *temp = st1.top();
            st1.pop();
            ans.push_back(temp->val);
            putAllLeft(temp->right, st1);
        }
        else
        {
            ans.push(st2.top()->val);
            TreeNode *temp = st2.top();
            st2.pop();
            ans.push_back(temp->val);
            putAllLeft(temp->right, st2);
        }
    }

    while (st1.size() != 0)
    {
        ans.push(st1.top()->val);
        TreeNode *temp = st1.top();
        st1.pop();
        ans.push_back(temp->val);
        putAllLeft(temp->right, st1);
    }

        while (st2.size() != 0)
    {
        ans.push(st2.top()->val);
        TreeNode *temp = st2.top();
        st2.pop();
        ans.push_back(temp->val);
        putAllLeft(temp->right, st2);
    }

    return ans;
}
