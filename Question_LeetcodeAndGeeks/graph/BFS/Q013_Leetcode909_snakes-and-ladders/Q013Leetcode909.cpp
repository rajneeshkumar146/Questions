// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int n, m;
bool isfirst = true;

int getValueOverBoard(vector<vector<int>> &board, int num)
{
    int r = (num - 1) / n;

    int x = (n - 1) - r;
    int y = r % 2 == 0 ? num - 1 - r * n : n - (num - r * n);

    board[x][y] = num;
    return board[x][y];
}

int snakesAndLadders(vector<vector<int>> &board)
{
    n = board.size();
    m = board[0].size();

    queue<int> que;
    que.push(1);

    vector<int> vis(n * m + 1, false);
    int moves = 0;

    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int step = que.front();
            que.pop();
            if (vis[step])
                continue; //cycle.

            if (step == n * m)
                return moves;

            vis[step] = true; //mark it true.
            for (int i = 1; i <= 6 && step + i <= n * m; i++)
            {
                int num = step + i;
                int value = getValueOverBoard(board, num);
                if (value > 0)
                    num = value;
                if (vis[step])
                    que.push(num);
            }
        }
        moves++;
    }
    return -1;
}

void TestingOfIdx()
{
    n = 8, m = 8;
    vector<vector<int>> board(n, vector<int>(m, 0));
    for (int i = 1; i <= n * m; i++)
        getValueOverBoard(board, i);

    for (vector<int> &ar : board)
    {
        for (int ele : ar)
            cout << ele << " ";
        cout << endl;
    }
}

int main()
{
    TestingOfIdx();
    return 0;
}