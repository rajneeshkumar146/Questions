#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

#define vi vector<int>
#define vii vector<vi>
void display(vi arr)
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

int main()
{
    vector<int>a{10, 20, 30};
    vector<int>b{10, 20, 3};
    display(min(a,b));
    return 0;
}
