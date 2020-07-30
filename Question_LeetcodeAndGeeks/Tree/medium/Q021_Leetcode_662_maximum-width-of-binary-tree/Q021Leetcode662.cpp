// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

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


int widthOfBinaryTree(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    queue<pair<TreeNode *, int>> que;
    que.push({root, 1});
    long ans = 0;

    while (que.size() != 0)
    {
        int size = que.size();

        long first = que.front().second;
        long second = -1;

        while (size-- > 0)
        {
            auto p = que.front();

            TreeNode *curr = p.first;
            second = p.second;

            que.pop();

            if (curr->left != nullptr)
                que.push({curr->left, 2 * second});
            if (curr->right != nullptr)
                que.push({curr->right, 2 * second + 1});
        }

        ans = max(ans, second - first + 1);
    }

    return ans;
}