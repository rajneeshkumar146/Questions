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

class Node
{
public:
    TreeNode *node = nullptr;
    int level = 0;
    Node(TreeNode *node, int level)
    {
        this->node = node;
        this->level = level;
    }

    bool operator<(Node const &o) const
    {
        if (this->level == o.level)
            return this->node->val > o.node->val;
        return this->level > o.level;
    }
};

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> result;
    if (root == nullptr)
        return result;

    vector<int> mm(2, 0);
    getMinMax(root, mm, 0);

    int len = mm[1] - mm[0] + 1;
    result.resize(len, vector<int>());

    priority_queue<Node> q1;
    priority_queue<Node> q2;

    Node n(root, -mm[0]);
    q1.push(n);

    while (q1.size() != 0)
    {
        int size = q1.size();
        while (size-- > 0)
        {
            Node rn = q1.top();
            q1.pop();

            result[rn.level].push_back(rn.node->val);

            if (rn.node->left != nullptr)
            {
                Node n(rn.node->left, rn.level - 1);
                q2.push(n);
            }
            if (rn.node->right != nullptr)
            {
                Node n(rn.node->right, rn.level + 1);
                q2.push(n);
            }
        }

        priority_queue<Node> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    return result;
}

void getMinMax(TreeNode *node, vector<int> &mm, int order)
{
    if (node == nullptr)
    {
        return;
    }

    mm[0] = min(mm[0], order);
    mm[1] = max(mm[1], order);

    getMinMax(node->left, mm, order - 1);
    getMinMax(node->right, mm, order + 1);
}
