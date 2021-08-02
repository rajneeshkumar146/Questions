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

int kadanesAlgo(vector<int> &arr)
{
    int maxSum = -1e9, currSum = 0;
    for (int ele : arr)
    {
        currSum += ele;
        currSum = max(currSum, ele);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
{
    int n = matrix.size(), m = matrix[0].size();
    int sum = 0, maxSum = -1e8;
    set<int> bst;
    for (int col = 0; col < m; col++)
    {
        vector<int> prefixSum(n, 0);
        for (int j = col; j < m; j++)
        {
            for (int i = 0; i < n; i++)
                prefixSum[i] += matrix[i][j];
            int kadanesSum = kadanesAlgo(prefixSum);
            if (kadanesSum <= k)
            {
                maxSum = max(maxSum, kadanesSum);
                continue;
            }

            bst.clear();
            sum = 0;
            bst.insert(0);
            for (int i = 0; i < n; i++)
            {
                sum += prefixSum[i];
                auto lowerBound = bst.lower_bound(sum - k);
                if (lowerBound != bst.end())
                    maxSum = max(maxSum, sum - *lowerBound);

                bst.insert(sum);
            }
        }
    }

    return maxSum;
}