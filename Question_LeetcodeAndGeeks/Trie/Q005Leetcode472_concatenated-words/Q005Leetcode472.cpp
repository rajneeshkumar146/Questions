// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

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
    bool wordEnd = false;
    Node()
    {
        this->childs.assign(26, nullptr);
        this->wordEnd = false;
    }
};
Node *root = nullptr;

void addWord(string &word)
{
    Node *curr = root;
    int idx = 0;
    int n = word.length();

    for (int i = 0; i < n; i++)
    {
        idx = word[i] - 'a';
        if (curr->childs[idx] == nullptr)
            curr->childs[idx] = new Node();

        curr = curr->childs[idx];
    }
    curr->wordEnd = true;
}

bool dfs(string &word, int n, int nidx, int count)
{
    Node *curr = root;
    for (int i = nidx; i < n; i++)
    {
        int idx = word[i] - 'a';
        if (curr->childs[idx] == nullptr)
            return false;

        if (curr->childs[idx]->wordEnd)
        {
            if (i == n - 1)
                return count >= 1;

            if (dfs(word, n, i + 1, count + 1))
                return true;
        }
        curr = curr->childs[idx];
    }
    return false;
}

vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
{
    if (words.size() < 1)
        return {};
    root = new Node();
    for (auto &word : words)
    {
        addWord(word);
    }

    std::vector<string> res;
    for (auto &word : words)
    {
        int n = word.length();
        if (dfs(word, n, 0, 0))
            res.push_back(word);
    }
    return res;
}