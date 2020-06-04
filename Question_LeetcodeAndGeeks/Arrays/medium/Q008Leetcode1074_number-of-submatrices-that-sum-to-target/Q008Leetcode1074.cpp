// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

static const auto magic = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

//using hashMap.============================================================
int numSubmatrixSumTarget_01(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] += matrix[i - 1][j];

    unordered_map<int, int> map;
    int count = 0, sum = 0;
    for (int row = 0; row < n; row++)
    {
        for (int i = row; i < n; i++)
        {
            map.clear();
            map[0] = 1;
            sum = 0;
            for (int j = 0; j < m; j++)
            {
                sum += matrix[i][j] - (row != 0 ? matrix[row - 1][j] : 0);
                count += map.find(sum - target) != map.end() ? map[sum - target] : 0;
                map[sum]++;
            }
        }
    }

    return count;
}

//treating array as a hashmap.=============================================
int numSubmatrixSumTarget_02(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] += matrix[i - 1][j];

    static int map[200'000'002] = {0};
    const int offset = 100'000'000;
    int count = 0, sum = 0;
    for (int row = 0; row < n; row++)
    {
        for (int i = row; i < n; i++)
        {
            map[offset] = 1;
            sum = 0;
            for (int j = 0; j < m; j++)
            {
                sum += matrix[i][j] - (row != 0 ? matrix[row - 1][j] : 0);
                count += map[offset + sum - target];
                map[offset + sum]++;
            }

            sum = 0;
            for (int j = 0; j < m; j++)
            {
                sum += matrix[i][j] - (row != 0 ? matrix[row - 1][j] : 0);
                map[offset + sum] = 0;
            }
        }
    }

    return count;
}

//treating array as a hashmap and base is coloumn.=============================================
int numSubmatrixSumTarget_03(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();

    static int map[200'000'002] = {0};
    const int offset = 100'000'000;
    int count = 0, sum = 0;
    for (int col = 0; col < m; col++)
    {
        vector<int> prefixSum(n,0);
        for (int j = col; j < m; j++)
        {
            for(int i=0;i<n;i++) prefixSum[i]+=matrix[i][j];

            map[offset] = 1;
            sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += prefixSum[i];
                count += map[offset + sum - target];
                map[offset + sum]++;
            }

            sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += prefixSum[i];
                map[offset + sum] = 0;
            }
        }
    }

    return count;
}
