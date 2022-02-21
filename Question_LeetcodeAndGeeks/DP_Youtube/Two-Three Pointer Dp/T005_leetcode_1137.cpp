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

int tribonacci_memo(int n, vi &dp)
{
    if (n <= 2)
    {
        return dp[n] = (n <= 1 ? n : 1);
    }

    if (dp[n] != 0)
        return dp[n];
    return dp[n] = tribonacci_memo(n - 1, dp) + tribonacci_memo(n - 2, dp) + tribonacci_memo(n - 3, dp);
}

int tribonacci_tabu(int N, vi &dp)
{
    for (int n = 0; n <= N; n++)
    {
        if (n <= 2)
        {
             dp[n] = (n <= 1 ? n : 1);
             continue;
        }

        
        dp[n] = dp[n - 1] + dp[n - 2] + dp[n - 3];//tribonacci_memo(n - 1, dp) + tribonacci_memo(n - 2, dp) + tribonacci_memo(n - 3, dp);
    }
      return dp[N];
}

int tribonacci_opti(int N)
{
    long a = 0, b  = 1, c = 1;
    for (int n = 2; n <= N; n++)
    {
        long d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
      return (int)a;
}

int tribonacci(int n)
{
    vi dp(n + 1, 0);
    int ans = tribonacci_memo(n, dp);
    return ans;
}

int main()
{
    return 0;
}
