// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

static const auto magic = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

const int N = 100'000;
const int bs = 400;
vector<pair<int, int>> blocks[bs];
int arr[N];

int query(int si, int ei, int num)
{
    int ans = 0;
    while (si % bs && si <= ei)
        if (arr[si++] <= num)
            ans++;

    while (si + bs <= ei)
    {
        ans += lower_bound(blocks[si / bs].begin(), blocks[si / bs].end(), make_pair(num, (int)1e7)) - blocks[si / bs].begin();
        si += bs;
    }

    while (si <= ei)
        if (arr[si++] <= num)
            ans++;
    return ans;
}

void update(int i, int x)
{
    for (auto &key : blocks[i / bs])
    {
        if (key.second == i)
        {
            key.first = x;
            break;
        }
    }
    sort(blocks[i / bs].begin(), blocks[i / bs].end());
    arr[i] = x;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        blocks[i / bs].push_back({num, i});
        arr[i] = num;
    }

    for (int i = 0; i < bs; i++)
        sort(blocks[i].begin(), blocks[i].end());

    while (q--)
    {
        char ch;
        cin >> ch;
        if (ch == 'C')
        {
            int si, ei, num;
            cin >> si >> ei >> num;
            si--, ei--;
            cout << query(si, ei, num) << endl;
        }
        else
        {
            int i, num;
            cin >> i >> num;
            i--;
            update(i, num);
        }
    }
}

int main()
{
    solve();
    return 0;
}