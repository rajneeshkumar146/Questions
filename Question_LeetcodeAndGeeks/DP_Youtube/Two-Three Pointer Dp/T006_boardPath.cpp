#include <iostream>
#include <vector>
#include <math.h>
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

int boardPath_memo(int sp, int ep, vi &dp)
{
    if (sp == ep)
    {
        return dp[sp] = 1;
    }

    if (dp[sp] != 0)
        return dp[sp];

    int count = 0;
    for (int dice = 1; dice <= 6 && sp + dice <= ep; dice++)
    {
        count += boardPath_memo(sp + dice, ep, dp);
    }
    return dp[sp] = count;
}

int boardPath_tabu(int SP, int EP, vi &dp)
{
    for (int sp = EP; sp >= SP; sp--)
    {
        if (sp == EP)
        {
            dp[sp] = 1;
            continue;
        }

        for (int dice = 1; dice <= 6 && sp + dice <= EP; dice++)
            dp[sp] += dp[sp + dice];
    }

    return dp[SP];
}

int boardPath_opti(int SP, int EP)
{
    if (EP - SP <= 1)
    {
        return 1; // EP - SP;
    }

    list<int> ll;
    ll.push_front(1);
    ll.push_front(1);
    for (int sp = EP - 2; sp >= SP; sp--)
    {
        if (ll.size() < 7)
            ll.push_front(2 * ll.front());
        else
        {
            ll.push_front(2 * ll.front() - ll.back());
            ll.pop_back();
        }
    }

    return ll.front();
}

int boardPath_opti_02(int SP, int EP)
{
    if (EP - SP <= 1)
    {
        return 1; // EP - SP;
    }

    int len = 7, idx = 1;
    vector<int> arr(len, 0);
    arr[0] = arr[1] = 1;

    while (idx < EP)
    {
        if (idx < 6)
            arr[idx + 1] = 2 * arr[idx];
        else
            arr[(idx + 1) % len] = 2 * arr[idx % len] - arr[(idx + 1) % len];

        idx++;
    }

    display(arr);

    return arr[idx % len];
}

void boardPath()
{
    int sp = 0, ep = 10;
    // vi dp(ep + 1, 0);
    int ans = boardPath_opti_02(sp, ep);
    // display(dp);
    cout << ans << endl;
}

int main()
{
    boardPath();
    return 0;
}
