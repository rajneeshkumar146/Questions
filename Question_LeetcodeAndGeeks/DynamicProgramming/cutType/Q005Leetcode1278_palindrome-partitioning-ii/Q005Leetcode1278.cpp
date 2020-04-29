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

int palindromePartition(string s, int k)
{
    int n = s.length();
    vector<vector<int>> pdp(n, vector<int>(n, 0));

    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
            {
                pdp[i][j] = 0;
                continue;
            }
            pdp[i][j] = pdp[i + 1][j - 1];
            if (s[i] != s[j])
                pdp[i][j] += 1;
        }
    }
}
