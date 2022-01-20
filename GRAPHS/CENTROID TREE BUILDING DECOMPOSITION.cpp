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
vector<ll> adj[200001]; // INITIAL TREE
vector<ll> ctr[200001]; // NEW CENTROID TREE
vector<ll> dead(200001); // STORES THOSE NODES WHO ARE ALREADY TAKEN IN CENTROID TREE AND VIRTUALLY REMOVED FROM MAIN TREE
vector<ll> subtreeSize(200001); // STORES THE SIZE OF ALL THE SUBTREES
ll subtreeSizeDFS(ll a, ll par)
{
    ll a1 = 1;
    if(dead[a]) return subtreeSize[a] = 0; // IT IS REMOVED VIRTUALLY
    for(ll i=0; i<adj[a].size(); i++)
    {
        if(adj[a][i]!=par)
        {
            a1+=subtreeSizeDFS(adj[a][i],a);
        }
    }
    return subtreeSize[a] = a1;
}
ll centroid(ll a, ll par, ll sz)    // TO FIND A CENTROID OF A TREE
{   
    for(ll i=0; i<adj[a].size(); i++)
    {
        if(adj[a][i]!=par)
        {
            if(subtreeSize[adj[a][i]]>(sz/2)) return centroid(adj[a][i], a, sz);
        }
    }
    return a;
}
ll buildTree(ll a, ll par)
{
    ll sz = subtreeSizeDFS(a,par);  // CALCULATES THE SUBTREE SIZE OF ALL NODES CONSIDERING DEAD NODES AS REMOVED
    ll a1 = centroid(a,par,sz);
    cout<<a1<<endl;
    vector<ll> child; // AFTER REMOVING THE CENTROID, THE NODES ON HICH WE NEED TO MAKE OPERATIONS FURTHER
    for(ll i=0; i<adj[a1].size(); i++)
    {
        if(dead[adj[a1][i]]==0)
        {
            child.pb(adj[a1][i]);
        }
    }
    dead[a1] = 1;   // VIRTUALLY REMOVING THE CENTROID
    for(ll i=0; i<child.size(); i++)
    {
        ll a2 = buildTree(child[i], a1);    //  HERE, A1 IS THE PREVIOUS CENTROID, WE ARE PASSING AS A PARENT TO NEW NODE SO THAT THE FIRST JUMP WOULD NOT BE ON THE PREVIOUS CENTROID AS WE WILL CONSIDER THAT EDGE DELETED
        ctr[a1].pb(a2);
        ctr[a2].pb(a1);
    }
    return a1;
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
    for(ll i=0; i<(n-1); i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    buildTree(1,-1);
    for(ll i=1; i<=n; i++)
    {
        for(ll j=0; j<ctr[i].size(); j++)
        {
            cout<<i<<" "<<ctr[i][j]<<endl;
        }
    }
    timetaken;
    return 0;
}