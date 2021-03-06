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
    Bellman Ford Algorithm
    1. Find SSSP In weighted graphs with negative weights as well
    2. Detect Negative Cycles
    */
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> edges;
    vector<vector<ll>> adj(n);
    for(ll i=0; i<m; i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        adj[a].pb(b);
        edges.pb({a,b,c});
    }
    vector<ll> dist(n,LLONG_MAX);
    vector<ll> prev_node(n,0);  // storing the previous node from which distance is smallest
    dist[0] = 0;    // imp
    // LEMMA IS THAT, AFTER KTH PHASE, BELLMAN-FORD ALGORITHM CORRECTLY FINDS ALL 
    // SHORTEST PATHS WHOSE NUMBER OF EDGES ARE LESS THAN OR EQUAL TO K
    // THATS WHY, WE ARE RUNNING A LOOP N-1 TIMES.
    for(ll i=0; i<n-1; i++)
    {
        for(ll j=0; j<m; j++)
        {
            ll start = edges[j][0];
            ll end = edges[j][1];
            ll len = edges[j][2];
            if(dist[start]!=LLONG_MAX && dist[end] > len + dist[start])
            {
                dist[end] = dist[start] + len;
                prev_node[end] = start;
            }
        }
    }
    bool check = 1;
    vector<ll> cycle_nodes;
    for(ll j=0; j<m; j++)   // In n-1 turns, we must get the answer, so if on the nth turn as well we are getting something / improving something / relaxing something, then we have a negative cycle
    {
        ll start = edges[j][0];
        ll end = edges[j][1];
        ll len = edges[j][2];
        if(dist[start]!=LLONG_MAX && dist[end] > len + dist[start])
        {
            check = 0;
            cycle_nodes.pb(end); // either the node next to the end of negative cycle or inside the cycle
        }
    }
    if(!check)
    {
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<cycle_nodes.size(); j++)
            {
                cycle_nodes[j] = prev_node[cycle_nodes[j]]; // to bring the nodes from next to the end of the cycle to in the cycle
            }
        }
        queue<ll> q;
        for(ll i=0; i<cycle_nodes.size(); i++)
        {
            dist[cycle_nodes[i]] = LLONG_MIN;   // -INF
            q.push(cycle_nodes[i]);
        }
        while(!q.empty())   // Running a BFS to make all the nodes  -INF reachable from negative cycles
        {
            ll a = q.front();
            q.pop();
            for(ll i=0; i<adj[a].size(); i++)
            {
                if(dist[a]==LLONG_MIN && dist[adj[a][i]]!=LLONG_MIN)
                {
                    dist[adj[a][i]] = LLONG_MIN;
                    q.push(adj[a][i]);
                }
            }
        }
    }
    if(dist[n-1]==LLONG_MIN) cout<<"-1"<<endl;
    else cout<<dist[n-1]<<endl;
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