#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define scanit(a,n) for(ll indexaa=0; indexaa<n; indexaa++) cin>>a[indexaa];
#define printit(a,n) for(ll indexaa=0; indexaa<n; indexaa++) cout<<a[indexaa]<<" "; cout<<endl;
#define pb push_back
#define vll vector<ll>
#define precision(a) cout<<fixed<<setprecision(a)
#define testcase ll t; cin>>t; while(t--)
#define endl "\n"
#define iendl "\n", cout<<flush // FOR INTERACTIVE PROBLEMS
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;
const ll M = 1000000007;
ll fact[200001] = {}, smallestPrimeFactor[200001] = {}, isPrimeSieve[200001] = {};
mt19937_64 my_rand(chrono::steady_clock::now().time_since_epoch().count());
inline bool comp(ll x,ll y) { return x<y; } // INITIALLY IN DEFAULT INCREASING ORDER (SMALL TO BIG)
inline ll mod(ll x) {ll a1=(x%M); if(a1<0){a1+=M;} return a1;}
inline ll power(ll x, unsigned ll y, ll p = LLONG_MAX) {ll res=1; x=x%p; if(x==0) {return 0;} while(y>0){ if(y&1){res=(res*x)%p;} y=y>>1; x=(x*x)%p;} return res;} // CALCULATING POWER IN LOG(Y) TIME COMPLEXITY
inline ll inversePrimeModular(ll a, ll p) {return power(a,p-2,p);}
inline void calcFact(ll n) { fact[0] = 1; for(ll i=1; i<=n; i++){ fact[i] = fact[i-1]*i; fact[i] = mod(fact[i]); }}
inline ll ncr(ll n, ll r) { if(n<r) return 0; return mod(inversePrimeModular(mod(fact[n-r]*fact[r]),M)*fact[n]); }
struct custom_hash { static uint64_t splitmix64(uint64_t x)  { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); }};
void sieve(ll n) { for(ll i=1; i<=n; i++) smallestPrimeFactor[i] = i; for(ll i=2; (i*i)<=n; i++) { if(smallestPrimeFactor[i]==i) { for(ll j=(i*i); j<=n; j+=i) { smallestPrimeFactor[j] = min(smallestPrimeFactor[j], i); } } } for(ll i=2; i<=n; i++) { if(smallestPrimeFactor[i]==i) isPrimeSieve[i] = 1; } }
void dfs(ll a, ll par, vector<vector<ll>> & adj, vector<ll> & height)
{
    for(ll i=0; i<adj[a].size(); i++)
    {
        if(adj[a][i]!=par)
        {
            dfs(adj[a][i], a, adj, height);
            height[a] = max(height[a], height[adj[a][i]]);
        }
    }
    height[a]++;
}
void dfs1(ll a, ll par, vector<vector<ll>> & adj, vector<ll> & height, vector<ll> & dis)
{
    ll mx1 = 0, mx2 = 0;
    for(ll i=0; i<adj[a].size(); i++)
    {
        if(adj[a][i]!=par)
        {
            if(height[adj[a][i]]>=mx1)
            {
                mx2 = mx1;
                mx1 = height[adj[a][i]];
            }
            else if(height[adj[a][i]]>mx2)
            {
                mx2 = height[adj[a][i]];
            }
        }
    }
    for(ll i=0; i<adj[a].size(); i++)
    {
        if(adj[a][i]!=par)
        {
            if(mx1==height[adj[a][i]])
            {
                dis[adj[a][i]] = 1 + max(1 + mx2, dis[a]);
            }
            else 
            {
                dis[adj[a][i]] = 1 + max(1 + mx1, dis[a]);
            }
            dfs1(adj[a][i], a, adj, height, dis);
        }
    }
}
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n+1);
    for(ll i=0; i<(n-1); i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<ll> height(n+1,0);
    dfs(1,-1,adj,height);
    vector<ll> dis(n+1,0);
    dfs1(1,-1,adj,height,dis);
    for(ll i=1; i<=n; i++)
    {
        cout<<max(height[i],dis[i])-1<<endl;
    }
    timetaken;
    return 0;
}