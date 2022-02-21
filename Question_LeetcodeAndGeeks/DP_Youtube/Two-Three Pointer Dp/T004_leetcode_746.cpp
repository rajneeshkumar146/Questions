#include <iostream>
#include <vector>
#include <math.h>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

// 1. Faith -> (Math Relation)
// 2. Recursive Tree (Recursive Code with Tree)
// 3. Recursive Code -> Memoization
// 4. Observation
// 5. Memoization -> Tabulation
// 6. Optimization

void display(vi &dp)
{
    for (int ele : dp)
    {
        cout << ele << " ";
    }
    cout << endl;
}

void display2D(vii &dp)
{
    for (vi &d : dp)
    {
        display(d);
    }
    cout << endl;
}

int mcs(int n, vi &cost, vi &dp)
{
    if (n <= 1)
    {
        return dp[n] = cost[n];
    }

    if (dp[n] != 0)
        return dp[n];

    return dp[n] = min(mcs(n - 1, cost, dp), mcs(n - 2, cost, dp)) + cost[n];
}

int mcs_tabu(int N, vi &cost, vi &dp)
{
    for (int n = 0; n <= N; n++)
    {
        if (n <= 1)
        {
            dp[n] = cost[n];
            continue;
        }

        dp[n] = min(dp[n - 1], dp[n - 2]) + cost[n];
    }
    return dp[N];
}

int mcs_opti(int N,vi& cost){
    int a = cost[0], b = cost[1];
    for(int n = 2; n < N;n++){
        int c = min(a,b) + cost[n];
        a = b;
        b = c;
    }

    return min(a,b);
}

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    cost.push_back(0);
    vi dp(n + 1, 0);
    int ans = mcs(n, cost, dp);
    display(dp);
    return ans;
}

int main()
{
    return 0;
}
