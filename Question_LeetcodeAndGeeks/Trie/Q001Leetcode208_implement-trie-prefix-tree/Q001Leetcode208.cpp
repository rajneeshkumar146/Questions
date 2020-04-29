// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node
{
public:
    vector<Node *> childs;
    int partOfWord = 0;
    int wordEnd = 0;
    Node()
    {
        childs.assign(26, nullptr);
    }
};

void insert(Node *root, string &word)
{
    Node *curr = root;
    int idx = 0;
    int n = word.length();
    curr->partOfWord++;
    for (int i = 0; i < n; i++)
    {
        idx = word[i] - 'a';
        if (curr->childs[idx] == nullptr)
            curr->childs[idx] = new Node();

        curr = curr->childs[idx];
        curr->partOfWord++;
    }
    curr->wordEnd++;
}

void erase(Node *root, string &word)
{

    Node *curr = root;
    int idx = 0;
    int n = word.length();
    curr->partOfWord--;
    for (int i = 0; i < n; i++)
    {
        idx = word[i] - 'a';
        curr = curr->childs[idx];
        curr->partOfWord--;
    }
    curr->wordEnd--;
}

bool search(Node *root, string &word)
{
    Node *curr = root;
    int idx = 0;
    int n = word.length();
    for (int i = 0; i < n; i++)
    {
        idx = word[i] - 'a';
        curr = curr->childs[idx];
        if (curr == nullptr || curr->partOfWord == 0)
            return false;
    }

    return curr->wordEnd != 0;
}

bool startsWith(Node *root, string &prefix)
{
    Node *curr = root;
    int idx = 0;
    int n = prefix.length();

    for (int i = 0; i < n; i++)
    {
        idx = prefix[i] - 'a';
        curr = curr->childs[idx];
        if (curr == nullptr || curr->partOfWord == 0)
            return false;
    }

    return true;
}
