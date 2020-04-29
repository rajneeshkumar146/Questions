// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

// https://practice.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck/0

int countSubsequnence_AiBjCk(string& str)
{
    int emptyCount = 1;
    int aCount = 0;
    int bCount = 0;
    int cCount = 0;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == 'a')
            aCount = aCount + (emptyCount + aCount); // exclude + include

        if (ch == 'b')
            bCount = bCount + (aCount + bCount); // exclude + include

        if (ch == 'c')
            cCount = cCount + (bCount + cCount); // exclude + include
    }

    return cCount;
}

void solve()
{
    string str;
    cin >> str;
    cout<<countSubsequnence_AiBjCk(str)<<endl;
}
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}
