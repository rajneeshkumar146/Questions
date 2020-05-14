// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

vector<string> words = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> letterCombinations(string &str, int idx)
{
    vector<string> base;
    if (idx == str.length())
    {
        vector<string> base;
        base.push_back("");
        return base;
    }

    int i = str[idx] - '0';
    string &word = words[i];s
    vector<string> recAns = letterCombinations(str, idx + 1);
    int size = recAns.size();

    for (int c = 0; c < word.length(); c++)
        for (int i = 0; i < size; i++)
            base.push_back(word[c] + recAns[i]);

    return base;
}

vector<string> letterCombinations(string str)
{
    if (str.length() == 0)
        return {};

    return letterCombinations(str, 0);
}