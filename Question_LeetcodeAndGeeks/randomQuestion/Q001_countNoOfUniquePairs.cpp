#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const int size = 1000;
int prime[size] = {0};
vector<int> ans;

void SieveOfErathosthenes()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i < size; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j < size; j += i)
            {
                prime[j] = 1;
            }
            ans.push_back(i);
        }
    }
}

ll numPf(ll n) {

		int pf_idx = 0;
		int pf = ans[pf_idx];
        vector<pair<int,int>> fac;

		while (n != 1 && pf * pf <= n) {
            pair<int,int> p={pf,0};
			while(n % pf == 0) {
                n/=pf;
                p.second++;
			}
			pf = ans[++pf_idx];
            if(p.second!=0){
                fac.push_back(p);
            }
		}
        int power=1;
       for(int i=0;i<fac.size();i++){
           if(i==0){
             power=fac[i].second;
           }
           else if(power!=fac[i].second) return 1;
           else if(fac[i]%2!=0) return 1;
       }

       int countPow=0;
       while(power!=0){
           countPow++;
           power/=2;
       }


		return countPow;
	}

void solve()
{
    ll n; cin>>n;
    cout<<numPf(n)<<endl;
}

int main()
{
    SieveOfErathosthenes();
    int t; cin>>t;
    while(t-->0)
    solve();
    return 0;
}