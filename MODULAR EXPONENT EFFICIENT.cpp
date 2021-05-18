#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define precision(a) cout<<fixed<<setprecision(a)
#define testcase ll t; cin>>t; while(t--)
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,b) for(ll i=a; i<b; ++i)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;
const ll M = 1000000007;
ll ans(ll x, unsigned ll y, ll p) // CALCULATING POWER IN LOG(Y) TIME COMPLEXITY
{
    ll res = 1;
    x=x%p;
    if(x==0) return 0;
    while(y>0)
    {
        if(y&1)
            res = (res*x) % p;

        y=y>>1;
        x=(x*x)%p;
    }
    return res;
}
ll mod(ll x)
{
    return (x%M + M)%M;
}
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    testcase
    {
        ll n;
        cin>>n;
        cout<<ans(2,n-1,M)<<endl;
    }
    timetaken;
    return 0;
}