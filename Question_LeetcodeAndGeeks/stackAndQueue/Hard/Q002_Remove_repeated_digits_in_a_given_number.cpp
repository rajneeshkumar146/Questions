// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

void solve()
{
    string str;
    cin >> str;
    vector<char> st;
    st.push_back('$'); // dummy.
    for (int i = 0; i < str.length(); i++)
    {
        if (st.back() != str[i])
            st.push_back(str[i]);
    }

    str = "";
    for (int i = 1; i < st.size(); i++)
    {
        str += st[i];
    }
    cout << str << endl;
}
int main()
{
    int n;
    cin >> n;
    while (n-- )
        solve();
    return 0;
}
