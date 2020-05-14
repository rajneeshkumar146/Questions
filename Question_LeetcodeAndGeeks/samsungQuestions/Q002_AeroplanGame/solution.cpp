#include <iostream>
using namespace std;
int board[13][5];
int bombLocation[5][5];

void blast(int row)
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            
        }
}

void solve()
{
    int n, coins, maxCoins;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++)
            cin >> board[i][j];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            bombLocation[i][j] = 0;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}