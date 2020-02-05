#include<iostream>
#include<vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void reverse(vector<int>& arr,int si,int ei){
    while(si<ei){
        swap(arr[si],arr[ei]);
        si++;
        ei--;
    }
}

void solve(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) arr[i]=i*2+1;

    // Seed srand
    srand(time(0));
    int pivot= rand()%n;
    reverse(arr,0,pivot-1);
    reverse(arr,pivot,n-1);
    reverse(arr,0,n-1);

    cout<<n <<endl;
    for (int n : arr)
    {
        cout << n << " ";
    }
    int num=rand()%n;
    cout << endl<<num<<endl;

    int res=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==num){
           res=i;
           break; 
        }
    }
    cout<<res;
}

int main(int args,char** argv){
solve();
return 0;
}
