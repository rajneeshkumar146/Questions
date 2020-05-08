// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define uint unsigned int

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
    vector<Node *> childs;
    Node()
    {
        this->childs.assign(2, nullptr);
    }
};
Node *root = nullptr;

void insert(uint num, int len)
{
    Node *curr = root;
    int index = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        index = (num >> i) & 1; //either it is '1' or '0'.
        if (curr->childs[index] == nullptr)
            curr->childs[index] = new Node();
        curr = curr->childs[index];
    }
}

int search(uint num, int len)
{
    Node *cur = root;
    uint res = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        int index = (num >> i) & 1;
        res <<= 1;
        if (cur->childs[index ^ 1])
        {
            res |= 1; // idhar bits different hai  so bit '1' set hojyegi uske liye just add krdiya.
            cur = cur->childs[index ^ 1];
        }
        else
        {
            cur = cur->childs[index];
        }
    }
    return res;
}

int noOfbits(uint num)
{
    int count = 0;
    while (num != 0)
    {
        num >>= 1;
        count++;
    }
    return count;
}

int findMaximumXOR(vector<int> &nums)
{
    root = new Node();
    int max_ = nums[0];
    for (int ele : nums)
        max_ = max(max_, ele);
    int bitCount = noOfbits(max_);

    for (int ele : nums)
        insert(ele, bitCount);

    int ans = 0;
    for (int ele : nums)
        ans = max(ans, search(ele, bitCount));

    return ans;
}