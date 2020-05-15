#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class pair_
{
public:
    int age;
    int wt;

    pair_(int age, int wt)
    {
        this->age = age;
        this->wt = wt;
    }

    bool operator<(pair_ const &p1) const // override lesser
    {
        return this->age < p1.age; //default
        // return p1.age < this->age; //reverse of default
        
    }
};


bool compartor(pair_ const &p1, pair_ const &p2)
{
    return p1.age < p2.age; //default
    // return p2.age < p1.age; //reverse of default
}

void method_01()
{
    vector<pair_> arr;

    pair_ p1(10, 10);
    arr.push_back(p1);

    pair_ p2(2, 16);
    arr.push_back(p2);

    pair_ p3(5, 560);
    arr.push_back(p3);

    pair_ p4(20, 2340);
    arr.push_back(p4);

    pair_ p5(-8, 340);
    arr.push_back(p5);

    sort(arr.begin(), arr.end(), compartor); // this replace with "<" in both conditions.
    for (pair_ p : arr)
        cout << p.age << " " << p.wt << endl;
}


int main()
{
    method_01();
    return 0;
}