#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <list>

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

int numDecodings_memo(string &s, int n, vi &dp)
{

    if (n == 0)
    {
        return dp[n] = 1;
    }

    if (dp[n] != -1)
        return dp[n];

    int count = 0;
    if (s[n - 1] != '0')
        count += numDecodings_memo(s, n - 1, dp);

    if (n > 1 && stoi(s.substr(n - 2, 2)) >= 10 && stoi(s.substr(n - 2, 2)) <= 26)
        count += numDecodings_memo(s, n - 2, dp);

    return dp[n] = count;
}

int numDecodings_tabu(string &s, int N, vi &dp)
{

    for (int n = 0; n <= N; n++)
    {
        if (n == 0)
        {
            dp[n] = 1;
            continue;
        }

        int count = 0;
        if (s[n - 1] != '0')
            count += dp[n - 1]; // numDecodings_memo(s, n - 1, dp);

        if (n > 1 && stoi(s.substr(n - 2, 2)) >= 10 && stoi(s.substr(n - 2, 2)) <= 26)
            count += dp[n - 2]; // numDecodings_memo(s, n - 2, dp);

        dp[n] = count;
    }

    return dp[N];
}

int numDecodings_opti(string &s, int N, vi &dp)
{

    int a = 0, b = 1;
    for (int n = 1; n <= N; n++)
    {

        int count = 0;
        if (s[n - 1] != '0')
            count += b;

        if (n > 1 && stoi(s.substr(n - 2, 2)) >= 10 && stoi(s.substr(n - 2, 2)) <= 26)
            count += a;

        a = b;
        b = count;
    }

    return b;
}

int numDecodings(string s)
{
    int n = s.length();
    vi dp(n + 1, -1);
    int ans = numDecodings_memo(s, n, dp);
    display(dp);
    return ans;
}

int main()
{
}