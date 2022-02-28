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
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    /*
        FINDING NEGATIVE CYCLE (ANY ONE) USING BELLMAN-FORD ALGORITHM
    */
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> edge;
    vector<ll> prev(n+1,-1);
    vector<ll> dis(n+1,LLONG_MAX);
    for(ll i=0; i<m; i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        edge.pb({a,b,c});
    }
    for(ll k=1; k<=n; k++)  // WHEN ROOT IS NOT DEFINED/GIVEN
    {
        if(dis[k]!=LLONG_MAX) continue;
        bool check = 1;
        dis[k] = 0;
        for(ll i=0; i<n-1 && check; i++)
        {
            check = 0;  // TO REDUCE AVERAGE TIME COMPLEXITY. WHEN NO B IS UPDATED WITH A, IT IS NOT OPTIMAL TO DO ALL N-1 OPERATIONS
            for(ll j=0; j<m; j++)
            {
                ll a = edge[j][0];
                ll b = edge[j][1];
                ll len = edge[j][2];
                if(dis[a]!=LLONG_MAX && (dis[a] + len < dis[b]))
                {
                    dis[b] = dis[a] + len;
                    prev[b] = a;
                    check = 1;
                }
            }
        }
        ll node = -1;
        for(ll j=0; j<m; j++)   // FINDING NEGATIVE CYCLE NODE
        {
            ll a = edge[j][0];
            ll b = edge[j][1];
            ll len = edge[j][2];
            if(dis[a]!=LLONG_MAX && (dis[a] + len < dis[b]))
            {
                node = b;
                prev[b] = a;
                break;
            }
        }
        if(node==-1) continue;
        for(ll i=0; i<n; i++) node = prev[node];    // TO GET NODE INTO CYCLE
        vector<ll> cycle;
        for(ll curr = node; ; curr = prev[curr])   
        {
            cycle.pb(curr);
            if(curr==node && cycle.size()>1) break;
        }
        cout<<"YES"<<endl;
        reverse(all(cycle));
        printit(cycle, cycle.size());
        return 0;
    }
    cout<<"NO"<<endl;
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