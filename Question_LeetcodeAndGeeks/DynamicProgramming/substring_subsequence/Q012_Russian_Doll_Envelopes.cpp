#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxEnvelopes(vector<vector<int>> &arr)
{
    if (arr.size() <= 1)
        return arr.size();
    sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });

    vector<int> list;
    for (int i = 0; i < arr.size(); i++)
    {
        int val = arr[i][1];
        int li = 0;
        int ri = list.size();

        while (li < ri)
        {
            int mid = li + (ri - li) / 2;
            if (list[mid] < val)
                li = mid + 1;
            else
                ri = mid;
        }
        if (list.size() != ri)
            list[ri] = val;
        else
            list.push_back(val);
    }
    return list.size();
}

//===============================================

void solve()
{
}

int main(int args, char **argv)
{
    solve();
}