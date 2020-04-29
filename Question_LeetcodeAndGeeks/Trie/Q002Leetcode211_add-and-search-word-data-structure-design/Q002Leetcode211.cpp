// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node
{
public:
    vector<Node *> childs;
    int wordEnd = 0;
    Node()
    {
        childs.assign(26, nullptr);
    }
};

Node *root = nullptr;
WordDictionary()
{
    root = new Node();
}

void addWord(string word)
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
    curr->wordEnd++;
}

bool search_(Node *node, int si, string &word)
{
    if (node == nullptr)
        return false;
    if (si == word.length())
        return node->wordEnd != 0;

    bool res = false;
    if (word[si] == '.')
    {
        for (int i = 0; i < 26 && !res; i++)
        {
            if (node->childs[i] != nullptr)
                res = res || search_(node->childs[i], si + 1, word);
        }
    }
    else
        res = res || search_(node->childs[word[si] - 'a'], si + 1, word);

    return res;
}

bool search(string word)
{
    return search_(root,0,word);
}
