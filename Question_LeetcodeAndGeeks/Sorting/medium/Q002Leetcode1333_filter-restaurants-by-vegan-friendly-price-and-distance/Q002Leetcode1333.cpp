// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

vector<int> filterRestaurants(vector<vector<int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance)
{

    int i = -1, j = 0;
    int n = restaurants.size();
    while (j < n)
    {
        if (veganFriendly)
        {
            if (restaurants[j][2] == 1 && restaurants[j][3] <= maxPrice && restaurants[j][4] <= maxDistance)
            {
                i++;
                swap(restaurants[i], restaurants[j]);
            }
        }
        else
        {
            if (restaurants[j][3] <= maxPrice && restaurants[j][4] <= maxDistance)
            {
                i++;
                swap(restaurants[i], restaurants[j]);
            }
        }
        j++;
    }

    if (i == -1)
        return {};

    //sort(si,length from si, comparable);
    sort(restaurants.begin(), restaurants.begin() + (i + 1), [](auto &a, auto &b) {
        if (a[1] == b[1])
            return a[0] > b[0];
        return a[1] > b[1];
    });

    vector<int> ans;
    for (int k = 0; k <= i; k++)
    {
        ans.push_back(restaurants[k][0]);
    }
    return ans;
}