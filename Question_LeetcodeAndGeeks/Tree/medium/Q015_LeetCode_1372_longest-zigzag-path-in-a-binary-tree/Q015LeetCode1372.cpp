#include <iostream>
#include <vector>
#include <unordered_map>

#define pb(val) push_back(val)
#define pair <int, int> pii

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int longestZigZag(TreeNode *root)
{
    dfs(root);
    return ans;
}

int ans = 0;
// pair ke first ne iss node ko as a left contribute krte hue maximum zig-zag path aage bheja hoga.
// pair ke second ne iss node ko as a right contribute krte hue maximum zig-zag path aage bheja hoga.
pair<int, int> dfs(TreeNode *root)
{
    if (root == nullptr)
        return {-1, -1};

    pair<int, int> left = dfs(root->left);
    pair<int, int> right = dfs(root->right);

    ans = max(ans, max(left.second, right.first) + 1);
    return {left.second + 1, right.first + 1};
}
