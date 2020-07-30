#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

static const auto magic = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

string removeDuplicateLetters(string str)
{
    int n = str.length();
    vector<int> freq(26, 0);
    vector<bool> seen(26, false);

    for (int i = 0; i < n; i++)
        freq[str[i] - 'a']++;

    string st = "0"; // use string as a stack.
    for (int i = 0; i < n; i++)
    {
        freq[str[i] - 'a']--;
        if (seen[str[i] - 'a'])
            continue;

        while (st.back() > str[i] && freq[st.back() - 'a'] > 0)
        {
            seen[st.back() - 'a'] = false;
            st.pop_back();
        }

        st += str[i];
        seen[str[i] - 'a'] = true;
    }
    return st.substr(1);
}
