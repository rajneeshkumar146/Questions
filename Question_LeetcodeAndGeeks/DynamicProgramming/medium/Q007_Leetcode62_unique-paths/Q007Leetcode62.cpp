// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

  int uniquePaths(int m, int n)
{
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	return uniquePaths(1, 1, m, n, dp);
}

int uniquePaths(int r, int c, int m, int n, vector<vector < int>> &dp)
{
	if (r == m && c == n)
		return 1;

	if (dp[r][c] != 0)
		return dp[r][c];

	int count = 0;
	if (r + 1 <= m)
		count += uniquePaths(r + 1, c, m, n, dp);
	if (c + 1 <= n)
		count += uniquePaths(r, c + 1, m, n, dp);
	dp[r][c] = count;
	return count;
}