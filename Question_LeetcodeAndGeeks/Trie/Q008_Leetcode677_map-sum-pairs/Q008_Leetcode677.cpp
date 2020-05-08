// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
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

class Node
{
public:
    int val;
    vector<Node *> childs;
    Node()
    {
        this->childs.assign(26, nullptr);
        this->val = 0;
    }
};

Node *root = nullptr;
unordered_map<string, int> map;
MapSum()
{
    root = new Node();
}

void insert(string key, int val)
{

    Node *curr = root;

    int delta = val - (map.count(key) != 0 ? map[key] : 0);
    map[key] = val;

    int n = key.length();
    for (int i = 0; i < n; i++)
    {
        int idx = key[i] - 'a';
        if (curr->childs[idx] == nullptr)
            curr->childs[idx] = new Node();
        curr = curr->childs[idx];
        curr->val += delta;
    }
}

int sum(string prefix)
{
    Node *curr = root;
    int n = prefix.length();
    for (int i = 0; i < n; i++)
    {
        int idx = prefix[i] - 'a';
        curr = curr->childs[idx];
        if (curr == nullptr)
            return 0;
    }
    return curr->val;
}