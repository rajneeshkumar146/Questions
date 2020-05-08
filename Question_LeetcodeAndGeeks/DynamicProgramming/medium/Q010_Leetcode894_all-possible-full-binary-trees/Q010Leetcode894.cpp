// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

unordered_map<int, vector<TreeNode *>> map;

vector<TreeNode *> allPossibleFBT(int n)
{
    vector<TreeNode *> v;
    if (n == 1)
    {
        v.push_back(new TreeNode(0));
        return v;
    }

    if (map.count(n))
        return map[n];

    for (int len = 1; len <= n - 1; len += 2) // for 1 to 7, cut between (2,6)
    {
        vector<TreeNode *> left = allPossibleFBT(len);
        vector<TreeNode *> right = allPossibleFBT(n - len - 1);

        for (TreeNode *a : left)
        {

            for (TreeNode *b : right)
            {
                TreeNode *node = new TreeNode(0, a, b);
                v.push_back(node);
            }
        }
    }

    return map[n] = v;
}

vector<TreeNode *> allPossibleFBT_DP(int N)
{
    for (int n = 1; n <= N; n += 2)
    {
        vector<TreeNode *> v;
        if (n == 1)
        {
            v.push_back(new TreeNode(0));
            map[n] = v;
            continue;
        }

        for (int len = 1; len <= n - 2; len += 2) // for 1 to 7, cut between (2,6)
        {
            vector<TreeNode *> left = map[(len)];
            vector<TreeNode *> right = map[(n - len - 1)];

            for (TreeNode *a : left)
            {
                for (TreeNode *b : right)
                {
                    TreeNode *node = new TreeNode(0, a, b);
                    v.push_back(node);
                }
            }
        }

        map[n] = v;
    }
    return map[N];
}
