// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define lli long long int

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<lli>> dp(m + 1, vector<lli>(n + 1, 0));
    return (int)uniquePaths(0, 0, m - 1, n - 1, obstacleGrid, dp);

    // return uniquePathsDP(m, n, obstacleGrid);
}

lli uniquePaths(int r, int c, int m, int n, vector<vector<int>> &obstacleGrid, vector<vector<lli>> &strg)
{
    if (obstacleGrid[r][c] == 1)
        return 0;

    if (r == m && c == n)
        return 1;

    if (strg[r][c] != 0)
        return strg[r][c];

    lli count = 0;
    if (r + 1 <= m)
        count += uniquePaths(r + 1, c, m, n, obstacleGrid, strg);
    if (c + 1 <= n)
        count += uniquePaths(r, c + 1, m, n, obstacleGrid, strg);
    return strg[r][c] = count;
}

int uniquePathsDP(int m, int n, vector<vector<int>> &obstacleGrid)
{
    vector<vector<lli>> dp(m + 1, vector<lli>(n + 1, 0));

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (obstacleGrid[i][j] == 1)
            {
                dp[i][j] = 0;
                continue;
            }

            if (i == m - 1 && j == n - 1)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        }
    }
    return (int)dp[0][0];
}