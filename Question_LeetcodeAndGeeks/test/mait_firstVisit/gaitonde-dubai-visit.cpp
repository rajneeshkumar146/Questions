#include<bits/stdc++.h>
using namespace std;
const long long int mod=1e9+7;
long long int modularExponentiation(long long int x,long long int n,long long int M)
{ 
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;
 
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        string a,b;
        //unsigned long long int a,b;
        cin>>a>>b;
        long long int a1=0,b1=0;
        for(int i=0;i<a.size();i++)
        {
            a1=(a1*10+a[i]-'0')%mod;
        }
        for(int i=0;i<b.size();i++)
        {
            b1=(b1*10+b[i]-'0')%(mod-1);
        }
        
        
        //cout<<a<<" "<<b<<endl;
        cout<<modularExponentiation(a1,b1,mod)<<endl;
    }
    
    return 0;
}