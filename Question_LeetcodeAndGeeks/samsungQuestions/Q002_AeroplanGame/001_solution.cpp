#include <iostream>
#include <vector>
using namespace std;

int board[13][5] = {0};
int originalBoard[13][5] = {0};
int dirA[3] = {-1, 0, 1};

void blastBoard(int row, int n)
{
    for (int i = row, count = 0; count < 5 && i >= 0; count++, i--)
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] == 2)
                board[i][j] = 0;
        }
}

void unBlastBoard(int row, int n)
{
    for (int i = row, count = 0; count < 5 && i >= 0; count++, i--)
        for (int j = 0; j < 5; j++)
        {
            if (originalBoard[i][j] == 2)
                board[i][j] = 2;
        }
}

int maxCoins;
void dfs(int n, int c, int coins)
{

    if (n == 0 || coins == -1)
    {
        maxCoins = max(maxCoins, coins);
        return;
    }

    if (board[n - 1][c] == 1)
        coins += 1;
    else if (board[n - 1][c] == 2)
        coins -= 1;

    for (int d = 0; d < 3; d++)
    {
        int y = c + dirA[d];
        if (y >= 0 && y < 5)
            dfs(n - 1, y, coins);
    }
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++)
        {
            cin >> board[i][j];
            originalBoard[i][j] = board[i][j];
        }

    maxCoins = -1;
    for (int i = n - 1; i > 0; i--)
    {
        blastBoard(i, n);
        dfs(n, 2, 0);
        unBlastBoard(i, n);
    }
    cout << maxCoins << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}