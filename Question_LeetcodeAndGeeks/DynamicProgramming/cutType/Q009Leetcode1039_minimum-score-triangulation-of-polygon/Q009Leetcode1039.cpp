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

int minScoreTriangulation_Rec(vector<int> &arr, int si, int ei, vector<vector<int>> &dp)
{
    if (si + 1 == ei)
        return 0;

    if (dp[si][ei] != 0)
        return dp[si][ei];

    int ans = 1e8;
    for (int cut = si + 1; cut < ei; cut++)
    {
        int leftPart = minScoreTriangulation_Rec(arr, si, cut, dp);
        int rightPart = minScoreTriangulation_Rec(arr, cut, ei, dp);

        int smallAns = leftPart + arr[si] * arr[cut] * arr[ei] + rightPart;
        ans = min(smallAns, ans);
    }

    return dp[si][ei] = ans;
}

int minScoreTriangulation(vector<int> &A)
{
    vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0));
    return minScoreTriangulation_Rec(A, 0, A.size(), dp);
}
