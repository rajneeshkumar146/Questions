#include <iostream>
#include <cstdlib>
using namespace std;

void generate()
{
    int n = (rand() % 8) + 5;
    cout << n << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << rand() % 3 << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << n % 15 << endl;
    while (n-- > 0)
        generate();
    return 0;
}