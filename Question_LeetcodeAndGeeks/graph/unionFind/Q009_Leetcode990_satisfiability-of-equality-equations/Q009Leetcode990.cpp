// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> par;
int findPar(int u)
{
    return par[u] == u ? u : findPar(par[u]);
}

bool equationsPossible(vector<string> &equations)
{
    for (int i = 0; i < 26; i++)
        par.push_back(i);

    for (string &s : equations)
    {
        if (s[1] == '=')
            par[findPar(s[0] - 'a')] = findPar(s[3] - 'a');
    }

    for (string &s : equations)
    {
        if (s[1] == '!' && findPar(s[0] - 'a') == findPar(s[3] - 'a'))
            return false;
    }

    return true;
}