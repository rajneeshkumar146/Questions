// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *delNodes(TreeNode *root, vector<TreeNode *> &res, unordered_set<int> &map)
{
    if (root == nullptr)
        return nullptr;

    root->left = delNodes(root->left, res, map);
    root->right = delNodes(root->right, res, map);

    if (map.count(root->val) > 0)
    {
        if (root->left != nullptr)
            res.push_back(root->left);
        if (root->right != nullptr)
            res.push_back(root->right);

        return nullptr;
    }

    return root;
}

vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
{
    if (root == nullptr)
        return {};

    unordered_set<int> map(to_delete.begin(), to_delete.end());
    vector<TreeNode *> res;
    TreeNode *node = delNodes(root, res, map);
    if (node != nullptr)
        res.push_back(node);
    return res;
}