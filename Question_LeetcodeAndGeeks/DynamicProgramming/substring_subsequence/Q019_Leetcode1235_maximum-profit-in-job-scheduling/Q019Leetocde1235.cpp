#include <iostream>
using namespace std;

vector<vector<int>> pair;
int jobScheduling(vector<int> &start, vector<int> &end, vector<int> &profit)
{
    if (start.size() == 0)
        return 0;

    pair.resize(start.size(), vector<int>(3, 0));
    for (int i = 0; i < start.size(); i++)
    {
        pair[i][0] = start[i];
        pair[i][1] = end[i];
        pair[i][2] = profit[i];
    }

    sort(pair.begin(), pair.end(), [](vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    });

    return LIS_n2();
    // return LIS_logn();
}

int LIS_n2()
{
    vector<int> dp(pair.size(), 0);
    dp[0] = pair[0][2];
    int max_ = pair[0][2];
    for (int i = 1; i < pair.size(); i++)
    {
        dp[i] = max(pair[i][2], dp[i - 1]);
        for (int j = i - 1; j >= 0; j--)
            if (pair[j][1] <= pair[i][0])
            {
                dp[i] = max(dp[i], dp[j] + pair[i][2]);
                break;
            }
        max_ = max(max_, dp[i]);
    }

    return max_;
}

int LIS_logn()
{

    vector<int> endTime;
    vector<int> profit;

    endTime.push_back(0);
    profit.push_back(0);

    for (int i = 0; i < pair.size(); i++)
    {
        int li = 0;
        int ri = profit.size();

        while (li < ri)
        {
            int mid = li + (ri - li) / 2;
            if (endTime[mid] <= pair[i][0])
                li = mid + 1;
            else
                ri = mid;
        }

        int profitOfDoingWork = profit[ri - 1] + pair[i][2];
        int profitOfNotDoingWork = profit.back();

        if (profitOfDoingWork > profitOfNotDoingWork)
        {
            profit.push_back(profitOfDoingWork);
            endTime.push_back(pair[i][1]);
        }
    }

    return profit.back();
}
