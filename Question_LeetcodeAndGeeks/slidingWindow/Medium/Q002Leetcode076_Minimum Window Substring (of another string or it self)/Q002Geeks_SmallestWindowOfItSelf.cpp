#include <iostream>
using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int minWindow(string s)
{
    int n = s.length();
    int freq[128] = {0};
    for (int i = 0; i < n; i++)
        freq[s[i]] = 1;

    int count = 0;
    for (int i = 0; i < 128; i++)
        count += freq[i];

    int si = 0, ei = 0, len = 1e9;
    int head = 0;

    while (ei < n)
    {
        if (freq[s[ei++]]-- == 1)
            count--;

        while (count == 0)
        {
            if (ei - si < len)
                len = (ei - (head = si));

            if (freq[s[si++]]++ == 0)
                count++;
        }
    }

    return len == 1e9 ? -1 : len;
}

void solve()
{
    string s;
    cin >> s;
    cout << minWindow(s) << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}