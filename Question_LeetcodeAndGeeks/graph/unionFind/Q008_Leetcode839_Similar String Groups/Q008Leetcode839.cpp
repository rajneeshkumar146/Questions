// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> par;
int find(int i)
{
    if (i != par[i])
        par[i] = find(par[i]);
    return par[i];
}

bool similar(string &a, string &b)
{
    int n = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i] && ++n > 2)
            return false;
    return true;
}

int numSimilarGroups(vector<string> &A)
{

    for (int i = 0; i < A.size(); i++)
        par.push_back(i);
    int count = A.size();
    for (int i = 0; i < A.size(); i++)
        for (int j = i + 1; j < A.size(); j++)
            if (similar(A[i], A[j]))
            {
                int p1 = find(i);
                int p2 = find(j);
                if (p1 != p2)
                {
                    par[p1] = p2;
                    count--;
                }
            }

    return count;
}