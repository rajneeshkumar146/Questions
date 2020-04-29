// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int numberOfArithmeticSlices_01(vector<int> &arr)
{
    if (arr.size() < 3)
        return 0;

    int ans = 0;
    int count = 0;
    for (int i = 1; i < arr.size() - 1; i++)
    {
        int d1 = arr[i] - arr[i - 1];
        int d2 = arr[i + 1] - arr[i];
        if (d1 == d2)
            ans += (++count);
        else
            count = 0;
    }
    return ans;
}

//using formula. ( 1 + 2 + 3 + 4 + 5 + 6 + ..  = n(n+1)/2 )
int numberOfArithmeticSlices_02(vector<int> &arr)
{
    if (arr.size() < 3)
        return 0;

    int ans = 0;
    int count = 0;
    for (int i = 1; i < arr.size() - 1; i++)
    {
        int d1 = arr[i] - arr[i - 1];
        int d2 = arr[i + 1] - arr[i];
        if (d1 == d2)
            count++;
        else
        {
            ans += (count * (count + 1)) / 2;
            count = 0;
        }
    }

    ans += (count * (count + 1)) / 2;
    return ans;
}