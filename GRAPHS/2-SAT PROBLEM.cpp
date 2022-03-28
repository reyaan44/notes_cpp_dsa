/* Code by Reyaan Jagnani (reyaan44) */
#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define scanit(a,n) for(ll indexaa=0; indexaa<n; indexaa++) cin>>a[indexaa];
#define printit(a,n) for(ll indexaa=0; indexaa<n; indexaa++) cout<<a[indexaa]<<" "; cout<<endl;
#define pb push_back
#define precision(a) cout<<fixed<<setprecision(a)
#define testcase ll t; cin>>t; while(t--)
#define endl "\n"
#define iendl "\n", cout<<flush // FOR INTERACTIVE PROBLEMS
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;
const ll M = 1000000007;
const ll maxN = 200001;
const ll BLK = 700;
ll fact[maxN] = {}, smallestPrimeFactor[maxN] = {}, isPrimeSieve[maxN] = {};
mt19937_64 my_rand(chrono::steady_clock::now().time_since_epoch().count());
inline bool comp(ll x,ll y) { return x<y; } // INITIALLY IN DEFAULT INCREASING ORDER (SMALL TO BIG)
inline ll mod(ll x) {ll a1=(x%M); if(a1<0){a1+=M;} return a1;}
inline ll power(ll x, unsigned ll y, ll p = LLONG_MAX) {ll res=1; x=x%p; if(x==0) {return 0;} while(y>0){ if(y&1){res=(res*x)%p;} y=y>>1; x=(x*x)%p;} return res;} // CALCULATING POWER IN LOG(Y) TIME COMPLEXITY
inline ll inversePrimeModular(ll a, ll p) {return power(a,p-2,p);}
inline void calcFact(ll n) { fact[0] = 1; for(ll i=1; i<=n; i++){ fact[i] = fact[i-1]*i; fact[i] = mod(fact[i]); }}
inline ll ncr(ll n, ll r) { if(n<r) return 0; return mod(inversePrimeModular(mod(fact[n-r]*fact[r]),M)*fact[n]); }
vector<ll> LIS(vector<ll> &vect) { ll n = vect.size();vector<ll> dp(n+1,LLONG_MAX), curr_idx(n+1,0), prev_idx(n,-1); dp[0] = LLONG_MIN; for(ll i=0; i<n; i++) { ll j = lower_bound(all(dp), vect[i]) - dp.begin(); if(dp[j]>vect[i]) { dp[j] = vect[i]; curr_idx[j] = i; if(dp[j-1]!=LLONG_MIN) prev_idx[i] = curr_idx[j-1]; } } for(ll i=n; i>=0; i--) { if(dp[i]<LLONG_MAX) { ll pos = curr_idx[i]; vector<ll> seq; while(pos!=-1) { seq.pb(vect[pos]); pos = prev_idx[pos]; } reverse(all(seq)); return seq; } } return {vect[0]}; }
struct custom_hash { static uint64_t splitmix64(uint64_t x)  { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); }};
void sieve(ll n) { for(ll i=1; i<=n; i++) smallestPrimeFactor[i] = i; for(ll i=2; (i*i)<=n; i++) { if(smallestPrimeFactor[i]==i) { for(ll j=(i*i); j<=n; j+=i) { smallestPrimeFactor[j] = min(smallestPrimeFactor[j], i); } } } for(ll i=2; i<=n; i++) { if(smallestPrimeFactor[i]==i) isPrimeSieve[i] = 1; } }
#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x << " : "; _print_(x);cerr << endl;
#else
#define dbg(x)
#endif
void _print_(ll t) {cerr << t;}
void _print_(int t) {cerr << t;}
void _print_(string t) {cerr << t;}
void _print_(char t) {cerr << t;}
void _print_(ld t) {cerr << t;}
void _print_(double t) {cerr << t;}
template <class T, class V> void _print_(pair <T, V> p);
template <class T> void _print_(vector <T> v);
template <class T> void _print_(set <T> v);
template <class T, class V> void _print_(map <T, V> v);
template <class T> void _print_(multiset <T> v);
template <class T, class V> void _print_(pair <T, V> p) {cerr << "{"; _print_(p.ff); cerr << ","; _print_(p.ss); cerr << "}";}
template <class T> void _print_(vector <T> v) {cerr << "[ "; for (T i : v) {_print_(i); cerr << " ";} cerr << "]";}
template <class T> void _print_(set <T> v) {cerr << "[ "; for (T i : v) {_print_(i); cerr << " ";} cerr << "]";}
template <class T> void _print_(multiset <T> v) {cerr << "[ "; for (T i : v) {_print_(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print_(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print_(i); cerr << " ";} cerr << "]";}
ll n,m;
vector<vector<ll>> adj(2e5+2);
vector<vector<ll>> tra(2e5+2); 
vector<ll> out;
vector<ll> visited(2e5+2,0);
map<ll,ll> connected_component;
void dfs(ll a, ll par)
{
    visited[a] = 1;
    for(auto child: adj[a])
    {
        if(visited[child]) continue;
        dfs(child, par);
    }
    out.pb(a);
}
void dfs1(ll a, ll curr)
{
    dbg(a);
    visited[a] = 1;
    connected_component[a] = curr;
    for(auto child: tra[a])
    {
        if(visited[child]) continue;
        dfs1(child, curr);
    }
}
/*
2-SAT PROBLEM - CSES - GIANT PIZZA
FIND STRONGLY CONNECTED COMPONENTS
IF X GOES TO X+N, MAKE X AS FALSE
ELSE MAKE X AS TRUE
IF X AND X+N IN SAME CONNECTED COMPONENTS, ANSWER NOT POSSIBLE
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    cin>>m>>n;
    for(ll i=0; i<m; i++)
    {
        char a1, a2;
        ll b1, b2;
        cin>>a1>>b1>>a2>>b2;
        if(a1=='+')
        {
            if(a2=='+')
            {
                adj[b2+n].pb(b1);
                adj[b1+n].pb(b2);
                tra[b1].pb(b2+n);
                tra[b2].pb(b1+n);
            }
            else
            {
                adj[b2].pb(b1);
                adj[b1+n].pb(b2+n);
                tra[b1].pb(b2);
                tra[b2+n].pb(b1+n);
            }
        }
        else
        {
            if(a2=='+')
            {
                adj[b2+n].pb(b1+n);
                adj[b1].pb(b2);
                tra[b1+n].pb(b2+n);
                tra[b2].pb(b1);
            }
            else
            {
                adj[b2].pb(b1+n);
                adj[b1].pb(b2+n);
                tra[b1+n].pb(b2);
                tra[b2+n].pb(b1);
            }
        }
    }
    for(ll i=1; i<=n*2; i++)
    {
        if(!visited[i])
        {
            dfs(i,i);
        }
    }
    visited.assign(2e5+2, 0);
    reverse(all(out));
    ll curr = 1;
    for(ll i=0; i<out.size(); i++)
    {
        if(!visited[out[i]])
        {
            dfs1(out[i], curr);
            curr++;
        }
    }
    bool check = 1;
    map<ll,char> ans;
    for(ll i=1; i<=n; i++)
    {
        if(connected_component[i]==connected_component[i+n]) check = 0;
        else if(connected_component[i]<connected_component[i+n]) ans[i] = '-';   
        else ans[i] = '+';
    }
    if(check)
    {
        for(auto i: ans) cout<<i.ss<<" ";
        cout<<endl;
    }
    else cout<<"IMPOSSIBLE"<<endl;
    timetaken;
    return 0;
}
/*


1. Binary Search / Binary Search on Answer
2. Bit
3. Parity (Odd / Even)
4. DP / Greedy
5. Graph / Bi-Partite
*/