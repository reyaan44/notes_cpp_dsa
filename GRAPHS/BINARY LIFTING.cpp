#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define scanit(a,n) for(ll indexaa=0; indexaa<n; indexaa++) cin>>a[indexaa];
#define printit(a,n) for(ll indexaa=0; indexaa<n; indexaa++) cout<<a[indexaa]<<" "; cout<<endl;
#define pb push_back
#define mp make_pair
#define vll vector<ll>
#define precision(a) cout<<fixed<<setprecision(a)
#define testcase ll t; cin>>t; while(t--)
#define endl "\n"
#define iendl "\n", cout<<flush // FOR INTERACTIVE PROBLEMS
#define getlineinput(a) cin>>ws; getline(cin,a); // CIN>>WS TO CLEAR THE INPUT BUFFER AS GETLINE INCLUDES SPACES FROM JUST THE START
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,b) for(ll i=a; i<b; ++i)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
#define PI 3.141592653589793238462
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T> 
// using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll M = 1000000007;
mt19937_64 my_rand(chrono::steady_clock::now().time_since_epoch().count());
ll fact[200001] = {}, smallestPrimeFactor[200001] = {}, isPrimeSieve[200001] = {};
inline bool comp(ll x,ll y) { return x<y; } // INITIALLY IN DEFAULT INCREASING ORDER (SMALL TO BIG)
inline ll mod(ll x) {ll a1=(x%M); if(a1<0){a1+=M;} return a1;}
inline ll power(ll x, unsigned ll y, ll p = LLONG_MAX) {ll res=1; x=x%p; if(x==0) {return 0;} while(y>0){ if(y&1){res=(res*x)%p;} y=y>>1; x=(x*x)%p;} return res;} // CALCULATING POWER IN LOG(Y) TIME COMPLEXITY
inline ll inversePrimeModular(ll a, ll p) {return power(a,p-2,p);}
inline void calcFact(ll n) { fact[0] = 1; for(ll i=1; i<=n; i++){ fact[i] = fact[i-1]*i; fact[i] = mod(fact[i]); }}
inline ll ncr(ll n, ll r) { if(n<r) return 0; return mod(inversePrimeModular(mod(fact[n-r]*fact[r]),M)*fact[n]); }
struct custom_hash { static uint64_t splitmix64(uint64_t x)  { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); }};
void sieve(ll n) { for(ll i=1; i<=n; i++) smallestPrimeFactor[i] = i; for(ll i=2; (i*i)<=n; i++) { if(smallestPrimeFactor[i]==i) { for(ll j=(i*i); j<=n; j+=i) { smallestPrimeFactor[j] = min(smallestPrimeFactor[j], i); } } } for(ll i=2; i<=n; i++) { if(smallestPrimeFactor[i]==i) isPrimeSieve[i] = 1; } }
vector<ll> adj[200001];
vector<ll> parent(200001);  // STORING ALL THE PARENTS OF ALL THE NODES
vector<vector<ll>> BiLift;  // BINARY LIFTING 2D ARRAY, SIZE = N*(LOGN).
void dfs(ll a, ll par)
{
    parent[a] = par;
    for(auto &child: adj[a])
    {
        if(child!=par)
        {
            dfs(child,a);
        }
    }
}
ll find_Kth_Parent(ll node, ll k)   // TAKES O(LOGN) TIME FOR EACH QUERY, WHILE BRUTE FORCE TAKES O(N) TIME.
{
    ll curr = 0;
    while(k)
    {
        if(k&1)
        {
            node = BiLift[node][curr];  // THE NODE IS SHIFTED UPWARDS BY 2^CURR STEPS.
            if(node==-1) return -1; // TO BE SAVED FROM RUNTIME ERROR.
        }
        curr++;
        k>>=1;
    }
    return node;
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
    BiLift = vector<vector<ll>> (n, vector<ll>(log2(n)+1,-1));  // HERE, THE ROW IS THE NODE, AND COLUMN IS POWER(2)'TH PARENT OF THAT NODE
    for(ll i=0; i<(n-1); i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0,-1);  // ROOTED AT 0 HERE. GETTING ALL THE PARENTS
    for(ll i=0; i<n; i++) BiLift[i][0] = parent[i]; // FILLING THE IMMEDIATE PARENTS 
    for(ll j=1; j<(log2(n)+1); j++)
    {
        for(ll i=0; i<n; i++)
        {
            if(BiLift[i][j-1]==-1) BiLift[i][j] = -1;   // EDGE CASE
            else BiLift[i][j] = BiLift[BiLift[i][j-1]][j-1];
        }
    }
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<(log2(n)+1); j++)
        {
            cout<<BiLift[i][j]<<" ";
        }
        cout<<endl;
    }
    ll node = 3, k = 5;
    cout<<find_Kth_Parent(node,k)<<endl;    // -1 MEANING CANT GO UPWARD THAN ROOT NODE.
    node = 3, k = 1;
    cout<<find_Kth_Parent(node,k)<<endl;
    node = 3, k = 2;
    cout<<find_Kth_Parent(node,k)<<endl;
    node = 2, k = 3;
    cout<<find_Kth_Parent(node,k)<<endl;
    node = 7, k = 1;
    cout<<find_Kth_Parent(node,k)<<endl;
    timetaken;
    return 0;
}