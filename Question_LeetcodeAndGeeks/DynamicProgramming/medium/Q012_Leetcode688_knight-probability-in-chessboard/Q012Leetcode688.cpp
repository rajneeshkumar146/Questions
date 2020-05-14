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

//Recursion Using memoization.====================================================================

int dir[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
vector<vector<vector<double>>> dp;

double knightProbability_(int N, int K, int r, int c)
{
    if (K == 0)
        return dp[K][r][c] = 1.0;
    if (dp[K][r][c] != 0.0)
        return dp[K][r][c];
    double count = 0;
    for (int d = 0; d < 8; d++)
    {
        int x = r + dir[d][0];
        int y = c + dir[d][1];

        if ((x < N && y < N) && (x >= 0 && y >= 0))
            count += knightProbability_(N, K - 1, x, y);
    }

    return dp[K][r][c] = count / 8.0;
}

// DP===============================================================

double knightProbability_DP(int N, int K, int r, int c)
{
    dp[0][r][c] = 1.0;

    for (int k = 1; k <= K; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                double count = 0;
                for (int d = 0; d < 8; d++)
                {
                    int x = i + dir[d][0];
                    int y = j + dir[d][1];

                    if ((x < N && y < N) && (x >= 0 && y >= 0))
                        count += dp[k - 1][x][y];
                }

                dp[k][i][j] = count / 8.0;
            }
        }
    }

    double sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sum += dp[K][i][j];
        }
    }
    return sum;
}

double knightProbability(int N, int K, int r, int c)
{
    dp.assign(K + 1, vector<vector<double>>(N + 1, vector<double>(N + 1, 0.0)));
    return knightProbability_(N, K, r, c);
    // return knightProbability_DP(N, K, r, c);
}