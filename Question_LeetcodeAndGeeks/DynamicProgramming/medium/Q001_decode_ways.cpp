#include <iostream>
using namespace std;

int numDecodings(string s)
{
    int a = 1;
    int b = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        int sum = 0;
        if (s[i] != '0')
            sum += a;
        if (i + 1 < s.length())
        {
            int val = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (val >= 10 && val <= 26)
                sum += b;
        }

        b = a;
        a = sum;
    }
    return a;
}

void solve()
{
}

int main()
{
    solve();
    return 0;
}