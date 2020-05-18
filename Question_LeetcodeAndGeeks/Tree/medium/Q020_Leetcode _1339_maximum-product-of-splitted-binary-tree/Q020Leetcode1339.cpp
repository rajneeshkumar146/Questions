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

// int sum[10005];
long long mod = 1e9 + 7;
int dfs(TreeNode *node)
{
    if (node == nullptr)
        return 0;
    int left = dfs(node->left);
    int right = dfs(node->right);

    return node->val = (left + right + node->val);
}

long long ans = 0;
int total;
void dfs2(TreeNode *node)
{
    if (node == nullptr)
        return;

    long long val = ((long long)(total - node->val) * (long long)node->val);
    ans = max(ans, val);
    dfs2(node->left);
    dfs2(node->right);
}

int maxProduct(TreeNode *root)
{
    // memset(sum,0,sizeof(sum));
    total = dfs(root);
    dfs2(root);
    return (int)(ans % mod);
}