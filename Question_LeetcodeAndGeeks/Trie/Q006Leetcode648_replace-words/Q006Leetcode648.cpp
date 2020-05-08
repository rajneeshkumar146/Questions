// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <stringstream>

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
    string word = "";
    Node()
    {
        this->childs.assign(26, nullptr);
        this->wordEnd = false;
        this->word = "";
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
        else if (curr->childs[idx]->wordEnd)
        {
            curr = nullptr;
            break;
        }

        curr = curr->childs[idx];
    }
    if (curr != nullptr)
    {
        curr->wordEnd = true;
        curr->word = word;
    }
}

string replaceWord_(string &word)
{
    Node *cur = root;
    string res = "";
    for (char c : word)
    {
        cur = cur->childs[c - 'a'];
        if (cur == NULL)
            break;
        if (cur->wordEnd == true)
        {
            res = cur->word;
            break;
        }
    }
    if (res != "")
        return res;
    return word;
}

string replaceWord_(string &word)
{
    Node *curr = root;
    int idx = 0;
    int n = word.length();

    for (int i = 0; i < n; i++)
    {
        idx = word[i] - 'a';
        if (curr->childs[idx] == nullptr)
            return word;
        if (curr->childs[idx]->wordEnd)
            return curr->childs[idx]->word;

        curr = curr->childs[idx];
    }
    return word;
}

string replaceWords(vector<string> &dict, string sentence)
{
    root = new Node();
    for (auto &word : dict)
        addWord(word);

    stringstream str(sentence);
    string token;
    string res = "";

    while (getline(str, token, ' '))
    {
        res += replaceWord_(token);
        res += " ";
    }

    return res.substr(0, res.length() - 1);
}