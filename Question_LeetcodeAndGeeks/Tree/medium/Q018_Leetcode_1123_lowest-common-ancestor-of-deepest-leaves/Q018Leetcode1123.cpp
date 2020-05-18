// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

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

//solution_01.===============================================

int height(TreeNode *node)
{
    if (node == nullptr)
        return -1;
    return max(height(node->left), height(node->right))+1;
}

TreeNode *lcaDeepestLeaves_(TreeNode *root, int depth)
{
    if (root == nullptr)
        return;

    if (depth == 0)
        return root;

    TreeNode *left  = lcaDeepestLeaves_(root->left, depth - 1);
    TreeNode *right = lcaDeepestLeaves_(root->right, depth - 1);
    if (left != nullptr && right != nullptr)
        return root;
    return left ? left : right;
}

TreeNode *lcaDeepestLeaves(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;
    int h = height(root);
    unordered_map<TreeNode *, int> map;
    lcaDeepestLeaves_(root, map, h);
    return (lca->left && lca->right) ? lca : !lca->left ? lca->left ? lca->right;
}