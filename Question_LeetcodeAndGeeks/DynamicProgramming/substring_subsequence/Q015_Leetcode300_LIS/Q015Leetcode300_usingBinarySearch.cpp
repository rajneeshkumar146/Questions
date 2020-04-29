#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int lengthOfLIS(vector<int> &arr)
{
    if (arr.empty())
        return 0;

    vector<int> list;
    for (int i = 0; i < arr.size(); i++)
    {
        int val = arr[i];
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
}

void LIS_logn(vector<int> &nums)
{
    lengthOfLIS(nums);
}

void solve()
{
    // vector<int> nums = {10, 22, 9, 33, 1, 50, 41, 60, 80, 1};
    // vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> nums = {-2, -1};
    // vector<int> nums = {4, 10, 4, 3, 8, 9};
}

int main(int args, char **argv)
{
    // int t;
    // cin >> t;
    // while (t-- > 0)
    solve();
}