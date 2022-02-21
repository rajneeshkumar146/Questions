#include <iostream>
#include <vector>
#include <math.h>
#include <list>
#include <algorithm>

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

int boardPathJumps_memo(int sp, int ep, vi &jumps, vi &dp)
{
    if (sp == ep)
    {
        return dp[sp] = 1;
    }

    if (dp[sp] != 0)
        return dp[sp];

    int count = 0;
    for (int jump : jumps)
    {
        if (sp + jump <= ep)
        {
            count += boardPathJumps_memo(sp + jump, ep, jumps, dp);
        }
        else
            break;
    }

    return dp[sp] = count;
}

int boardPathJumps_tabu(int SP, int ep, vi &jumps, vi &dp)
{
    for (int sp = ep; sp >= 0; sp--)
    {
        if (sp == ep)
        {
            dp[sp] = 1;
            continue;
        }

        int count = 0;
        for (int jump : jumps)
        {
            if (sp + jump <= ep)
            {
                count += dp[sp + jump]; // boardPathJumps_memo(sp + jump, ep, jumps, dp);
            }
            else
                break;
        }

        dp[sp] = count;
    }

    return dp[SP];
}

void boardPathJumps()
{
    int sp = 0, ep = 14;
    vi jumps{5, 2, 7, 9, 8, 11};
    sort(jumps.begin(), jumps.end());

    vi dp(ep + 1, 0);

    int ans = boardPathJumps_tabu(sp, ep, jumps, dp);
    display(dp);
    cout << ans << endl;
}

int main()
{
    boardPathJumps();
    return 0;
}
