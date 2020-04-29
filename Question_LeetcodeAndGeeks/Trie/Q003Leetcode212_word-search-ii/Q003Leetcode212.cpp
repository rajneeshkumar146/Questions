// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node
{
public:
    vector<Node *> childs;
    string word = "";
    bool wordEnd = false;
    Node()
    {
        this->childs.assign(26, nullptr);
        this->wordEnd = false;
    }
};

void addWord(Node *root, string word)
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
    curr->word = word;
    curr->wordEnd = true;
}

vector<vector<int>> dirA = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<string> ansList;
int n, m;

void dfs(int r, int c, Node *root, vector<vector<char>> &board)
{
    if (root->wordEnd)
    {
        root->wordEnd = false;
        ansList.push_back(root->word);
    }

    char ch = board[r][c];
    board[r][c] = '$';
    for (int d = 0; d < 4; d++)
    {
        int x = r + dirA[d][0];
        int y = c + dirA[d][1];
        if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] != '$' && root->childs[board[x][y] - 'a'] != nullptr)
            dfs(x, y, root->childs[board[x][y] - 'a'], board);
    }
    board[r][c] = ch;
}

vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
    if (!board.size() || !board[0].size() || !words.size())
        return {};

    Node *root = new Node();
    for (string &str : words)
        addWord(root, str);

    n = board.size();
    m = board[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (root->childs[board[i][j] - 'a'] != nullptr)
            {
                dfs(i, j, root->childs[board[i][j] - 'a'], board);
            }
        }
    }

    return ansList;
}