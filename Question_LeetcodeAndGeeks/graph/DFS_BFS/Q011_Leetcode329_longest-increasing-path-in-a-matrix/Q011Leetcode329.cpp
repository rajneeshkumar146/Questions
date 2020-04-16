#include <iostream>
#include <queue>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int longestIncreasingPath(vector<vector<int>> &matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return 0;

    // return method01(matrix);
    // return method02(matrix);
}

//method01_by_using_simple_recursion_with_memoization.=============================
int method01(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));
    int ans = 1;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            ans = max(ans, dfs(matrix, dp, i, j));
        }
    }
    return ans;
}

int dfs(vii &matrix, vii &dp, int i, int j)
{
    int n = matrix.size();
    int m = matrix[0].size();
    if (dp[i][j] != 0)
        return dp[i][j];

    dp[i][j] = 1;
    for (int d = 0; d < 4; d++)
    {
        int x = i + dir[d][0];
        int y = j + dir[d][1];

        if (x >= 0 && y >= 0 && x < n && y < m && matrix[x][y] > matrix[i][j])
            dp[i][j] = max(dp[i][j], dfs(matrix, dp, x, y) + 1);
    }
    return dp[i][j];
}

//method02_by_using_khans_algo.=====================================================
int method02(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vii indegreeEdges(n, vi(m, 0));

    // making indegreeEdges matrix.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            for (int d = 0; d < 4; d++)
            {
                int x = i + dir[d][0];
                int y = j + dir[d][1];

                if (x >= 0 && y >= 0 && x < n && y < m && matrix[x][y] > matrix[i][j])
                    indegreeEdges[x][y]++;
            }
    }

    //preparing que by puting 0 indegreeEdge vertex same as khans algo.
    queue<pair<int, int>> que;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (indegreeEdges[i][j] == 0)
                que.push({i, j});
        }
    }

    // simple bfs and len will give the answer.
    int len = 0;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            pair<int, int> p = que.front();
            que.pop();
            int i = p.first;
            int j = p.second;

            for (int d = 0; d < 4; d++)
            {
                int x = i + dir[d][0];
                int y = j + dir[d][1];

                if (x >= 0 && y >= 0 && x < n && y < m && matrix[x][y] > matrix[i][j] && --indegreeEdges[x][y] == 0)
                    que.push({x, y});
            }
        }
        len++;
    }

    return len != 0 ? len - 1 : 0;
}
