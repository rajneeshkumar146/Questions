// #include <vector>
// #include <algorithm>
// #include <cmath>
// #include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool fits(const vector<double>& areas, double cutsize, int guests) {
    int served = 0;
    for(int i = areas.size() - 1; i >=0 ;i--) {
        double area = areas[i];
        while(area >= cutsize) {     
            area -= cutsize;
            served++;
            if(served == guests)
                return true;
        }
    }
    return false;
}

double cut_cake(vector<int>& cakes,int guest)
{
    vector<double> areas(cakes.size());
    transform(cakes.begin(), cakes.end(), areas.begin(), [](int c) { return  c * c * M_PI;});
    int served = 0;
    double left = *min_element(areas.begin(), areas.end())/guest; // at least smallest cake is split between all
    double right = *max_element(areas.begin(), areas.end());
    if(left == right)
        return left;
    double cutsize = 0.0;
    while(right - left > 1e-5) {
        cutsize = (right + left) / 2;
        if(fits(areas, cutsize, guest))
            left = cutsize;
        else
            right = cutsize;
    }
    return cutsize;
}

string answer(vector<int> cakes,int guests) {
    double res = cut_cake(cakes, guests);
    stringstream stream;
    stream << fixed << setprecision(2) << res;
string s = stream.str();
return s;

}

int main() {
 
   vector<int> cakes = {3,2,1,2,1,1};
    int guests = 6;
    cout<<answer(cakes,guests);

}