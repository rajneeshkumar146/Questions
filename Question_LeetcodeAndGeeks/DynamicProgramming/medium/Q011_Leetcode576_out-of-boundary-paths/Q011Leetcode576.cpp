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

//recuursion.======================================================================

#define mod 1000000007

int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int dp[52][52][52];

int findPaths_(int m, int n, int N, int i, int j)
{
    if ((i < 0 || j < 0 || i >= m || j >= n))
        return N >= 0 ? 1 : 0;
    if (N == 0)
        return 0;
    if (dp[i][j][N] != -1)
        return dp[i][j][N];
    int count = 0;
    for (int d = 0; d < 4; d++)
    {
        int x = i + dir[d][0];
        int y = j + dir[d][1];

        count = (count + findPaths_(m, n, N - 1, x, y)) % mod;
    }
    return dp[i][j][N] = count;
}

//DP.==============================================================================

int dp_[51][51] = {0};
int ndp_[51][51] = {0};

int findPaths_DP(int m, int n, int N)
{
    int res = 0;
    while (N--)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int d = 0; d < 4; d++)
                {
                    int x = i + dir[d][0];
                    int y = j + dir[d][1];

                    if (x < 0 || y < 0 || x >= n || y >= m)
                        res = (res + dp_[i][j]) % mod;
                    else
                        ndp_[i][j] = (ndp_[i][j] + dp_[i][j]) % mod;
                }
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                dp_[i][j] = ndp_[i][j];
                ndp_[i][j] = 0;
            }
    }

    return res;
}

int findPaths(int m, int n, int N, int i, int j)
{
    // memset(dp, -1, sizeof dp);
    // return findPaths_(m, n, N, i, j);

    return findPaths_DP(m, n, N);
}
