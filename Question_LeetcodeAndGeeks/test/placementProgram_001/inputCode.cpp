
#include <vector>
#include <random>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

using namespace std;

void solve()
{
    int n; cin>>n;
    vector<int> arr(n,0);
     int max_=-1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        max_=max(max_,arr[i]);
    }

    for(int i=max_;i>0;i--){
        for(int j=0;j<arr.size();j++){
            if(i<=arr[j]) cout<<"*"<<" ";
            else cout<<"  ";
        }
        cout<<endl;
    }
}

int main()
{
    solve();
    return 0;
}