// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

void display(vi &arr)
{
    for (int ele : arr)
        cout << ele << " ";
    cout << endl;
}

void display2D(vii &arr)
{
    for (vi &ar : arr)
        display(ar);
    cout << endl;
}

void solve()
{
    
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}
