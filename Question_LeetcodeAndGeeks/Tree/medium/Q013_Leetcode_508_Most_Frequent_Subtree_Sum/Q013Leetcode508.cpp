#include <iostream>
#include <vector>
#include <unordered_map>

#define pb(val) push_back(val)

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

unordered_map<int, int> map;
int maxFreq = 0;

vector<int> findFrequentTreeSum(TreeNode *node)
{
    if (node == nullptr)
        return {};

    dfs(node);
    vector<int> ans;
    for (pair<int, int> key : map)
    {
        if (key.second == maxFreq)
            ans.pb(key.first);
    }

    return ans;
}

int dfs(TreeNode *node)
{
    if (node == nullptr)
        return 0;

    int sum = dfs(node->left) + dfs(node->right) + node->val;

    map[sum]++;
    if (map[sum] > maxFreq)
        maxFreq = map[sum];

    return sum;
}