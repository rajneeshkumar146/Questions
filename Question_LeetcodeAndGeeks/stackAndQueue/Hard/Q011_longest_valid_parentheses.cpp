#include <iostream>
#include <stack>

using namespace std;

int longestVallidParen(string str)
{
    stack<int> st;
    st.push(-1);
    int max_ = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (st.top() != -1 && str[i] == ')' && str[st.top()] == '(')
        {
            st.pop();
            max_ = max(max_, i - st.top());
        }
        else
            st.push(i);
    }

    return max_;
}

void solve()
{
    string str;
    cin >> str;
    cout << longestVallidParen(str) << endl;
}

int main()
{
    int n;
    cin >> n;
    while (n-- > 0)
        solve();

    return 0;
}