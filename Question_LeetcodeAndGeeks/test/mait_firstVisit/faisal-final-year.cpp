#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cout << x << "\n"
#define debug2(x, y) cout << x << " " << y << "\n"
#define debug3(x, y, z) cout << x << " " << y << " " << z << "\n"
#define nl cout << "\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cout << "abcd\n";
#define pi pair<ll, ll>
#define pii pair<int, pi>
#define pb push_back
#define mxn 200005

ll modexp(ll x, ll n, ll m = mod)
{
    ll r = 1LL;
    while (n)
    {
        if (n & 1)
            r = (1LL * r * x) % m;
        x = (x * x) % m;
        n >>= 1;
    }
    return r;
}

ll inv(ll x) { return modexp(x, mod - 2); }

ll pqinv(ll p, ll q)
{
    return (1LL * p * inv(q)) % mod;
}

int main()
{
    sp;
    ll n;
    cin >> n;
    ll nn = n;
    ll ans = 0;
    vector<int> v;
    for (ll i = 2; i * i <= n; ++i)
        if (n % i == 0)
        {
            v.pb(i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        v.pb(n);
    int n1 = v.size();
    int p1 = (1 << n1);
    for (int i = 1; i < p1; ++i)
    {
        ll temp = 1LL, y = 0, z = 0;
        for (int j = 0; j < n1; ++j)
        {
            if (i & (1 << j))
            {
                temp = 1LL * temp * v[j];
                y ^= 1;
            }
            if (temp > nn)
            {
                z = 1;
                break;
            }
        }
        if (z == 0)
        {
            // cout<<temp<<" "<<y<<" "<<(nn/temp)<<"\n";
            ll temp1 = nn / temp;
            if (y == 1)
                ans += temp1;
            else
                ans -= temp1;
            if (ans < 0)
                (ans += mod);
            ans %= mod;
        }
    }
    cout << pqinv(ans, nn);

    return 0;
}