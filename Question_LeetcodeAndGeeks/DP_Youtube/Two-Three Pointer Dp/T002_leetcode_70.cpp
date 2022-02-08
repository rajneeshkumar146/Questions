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

int climbStairs_memo(int n, vi &dp)
{
    if (n <= 1)
    {
        return dp[n] = 1;
    }

    if (dp[n] != 0)
        return dp[n];

    return dp[n] = climbStairs_memo(n - 1, dp) + climbStairs_memo(n - 2, dp);
}

int climbStairs_tabu(int N, vi &dp)
{
    for (int n = 0; n <= N; n++)
    {
        if (n <= 1)
        {
            dp[n] = 1;
            continue;
        }

        dp[n] = dp[n - 1] + dp[n - 2];
    }
    return dp[N];
}

int climbStairs_opti(int n)
{
    long a = 1, b = 1;
    for (int i = 1; i <= n; i++)
    {
        long c = a + b;
        a = b;
        b = c;
    }

    return a;
}

int climbStairs(int n)
{
    vi dp(n + 1, 0);
    int ans = climbStairs_memo(n, dp);
    display(dp);
    return ans;
}

int main()
{
    climbStairs(10);
    return 0;
}
