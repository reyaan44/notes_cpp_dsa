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
      ll n,sum=0,ans=0;
      cin>>n;
      vector<pair<ll,ll>> vect;
      map<ll,ll> m;
      forl(i,0,n)
      {
        ll x;
        cin>>x;
        pair<ll,ll> p = make_pair(x,i+1);
        vect.push_back(p);
      }   
      ll arr[n];   
      forl(i,0,n)
      {
        pair<ll,ll> pa = *(vect.begin()+i);
        ll s = (pa.second)-(pa.first);
        m[s]++;
      }
      for(auto itr = m.begin(); itr!=m.end(); itr++)
      {
        if((itr->second)>=2)
        {
          ans+=(itr->second)*(itr->second-1)/2;
        }
      }
      cout<<ans<<endl;
    }
    timetaken;
    return 0;
}