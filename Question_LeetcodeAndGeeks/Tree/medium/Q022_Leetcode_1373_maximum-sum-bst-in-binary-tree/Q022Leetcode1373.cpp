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

//Void Type.===================================================================

int maxSum = 0;
// isBSt=1/0, maxEle,minEle,Sum
vector<int> maxSumBST_(TreeNode *root)
{
    if (root == nullptr)
    {
        return {1, (int)-1e8, (int)1e8, 0};
    }

    vector<int> la = maxSumBST_(root->left);
    vector<int> ra = maxSumBST_(root->right);

    bool isBST = la[0] == 1 && ra[0] == 1 && la[1] < root->val && root->val < ra[2];
    int sum = la[3] + ra[3] + root->val;
    if (isBST)
        maxSum = max(maxSum, sum);

    return {isBST ? 1 : 0, max(root->val, max(la[1], ra[1])), min(root->val, min(la[2], ra[2])), sum};
}

//Return Type.===================================================================
vector<int> maxSumBST_02(TreeNode *root)
{
    if (root == nullptr)
    {
        return {1, (int)-1e8, (int)1e8, 0, 0};
    }

    vector<int> la = maxSumBST_02(root->left);
    vector<int> ra = maxSumBST_02(root->right);

    bool isBST = la[0] == 1 && ra[0] == 1 && la[1] < root->val && root->val < ra[2];
    int sum = la[3] + ra[3] + root->val;
    int maxSum = 0;
    if (isBST)
        maxSum = max(sum, max(la[4], ra[4]));
    else
        maxSum = max(la[4], ra[4]);

    return {isBST ? 1 : 0, max(root->val, max(la[1], ra[1])), min(root->val, min(la[2], ra[2])), sum, maxSum};
}

int maxSumBST(TreeNode *root)
{
    return maxSumBST_02(root)[4];
}
