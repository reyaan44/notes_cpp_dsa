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
ll fact[200001] = {}, smallestPrimeFactor[200001] = {}, isPrimeSieve[200001] = {};
mt19937_64 my_rand(chrono::steady_clock::now().time_since_epoch().count());
inline ll mod(ll x) {ll a1=(x%M); if(a1<0){a1+=M;} return a1;}
inline ll power(ll x, unsigned ll y, ll p = LLONG_MAX) {ll res=1; x=x%p; if(x==0) {return 0;} while(y>0){ if(y&1){res=(res*x)%p;} y=y>>1; x=(x*x)%p;} return res;} // CALCULATING POWER IN LOG(Y) TIME COMPLEXITY
inline ll inversePrimeModular(ll a, ll p) {return power(a,p-2,p);}
inline void calcFact(ll n) { fact[0] = 1; for(ll i=1; i<=n; i++){ fact[i] = fact[i-1]*i; fact[i] = mod(fact[i]); }}
inline ll ncr(ll n, ll r) { if(n<r) return 0; return mod(inversePrimeModular(mod(fact[n-r]*fact[r]),M)*fact[n]); }
struct custom_hash { static uint64_t splitmix64(uint64_t x)  { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); }};
void sieve(ll n) { for(ll i=1; i<=n; i++) smallestPrimeFactor[i] = i; for(ll i=2; (i*i)<=n; i++) { if(smallestPrimeFactor[i]==i) { for(ll j=(i*i); j<=n; j+=i) { smallestPrimeFactor[j] = min(smallestPrimeFactor[j], i); } } } for(ll i=2; i<=n; i++) { if(smallestPrimeFactor[i]==i) isPrimeSieve[i] = 1; } }
const ll BLK = 700;
const ll maxN = 100001;
ll color[maxN], start[maxN], ans[maxN], last[maxN], node_freq[maxN], color_freq[maxN];
vector<vector<ll>> query;
vector<ll> eutour, freq_freq(maxN);
vector<ll> sqrt_dec(maxN,0);
inline bool comp(vector<ll> &v1, vector<ll> &v2)
{
    ll left1 = v1[0]/BLK;
    ll left2 = v2[0]/BLK;
    if(left2==left1)
    {
        if(left2&1) return v1[1]<v2[1];
        return v1[1]>v2[1];
    }
    return left1<left2;
}
void eulor(vector<vector<ll>> &adj, ll a, ll par, vector<ll> &eutour, ll start[], ll last[], ll &curr)
{
    eutour.pb(a);
    start[a] = curr++;
    for(auto child: adj[a])
    {
        if(child==par) continue;
        eulor(adj, child, a, eutour, start, last, curr);
    }
    last[a] = curr++;
    eutour.pb(a);
}
void add(ll idx)
{
    ll node = eutour[idx];
    ll c = color[node];
    node_freq[node]++;
    if(node_freq[node]==2)
    {
        color_freq[c]++;
        freq_freq[color_freq[c]]++;
        freq_freq[color_freq[c]-1]--;
        ll block = color_freq[c]/BLK;
        sqrt_dec[block]++;
        block = (color_freq[c]-1)/BLK;
        sqrt_dec[block]--;
    }
}
void remove(ll idx)
{
    ll node = eutour[idx];
    ll c = color[node];
    node_freq[node]--;
    if(node_freq[node]==1)
    {
        color_freq[c]--;
        freq_freq[color_freq[c]]++;
        freq_freq[color_freq[c]+1]--;
        ll block = color_freq[c]/BLK;
        sqrt_dec[block]++;
        block = (color_freq[c]+1)/BLK;
        sqrt_dec[block]--;
    }
}
ll getsum(ll idx, ll n)
{
    ll sum = 0;
    ll left = idx/BLK;
    ll right = n/BLK;
    if(left==right)
    {
        for(ll i=idx; i<=n; i++) sum+=freq_freq[i];
    }
    else
    {
        for(ll i = idx; i<(left+1)*BLK; i++) sum+=freq_freq[i];
        for(ll i = left + 1; i<right; i++) sum+=sqrt_dec[i];
        for(ll i = (right*BLK); i<=n; i++) sum+=sqrt_dec[i];
    }
    return sum;
}
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    /*
    QUESTION : https://codeforces.com/problemset/problem/375/D
    MO'S ALGORITHM ON THE SUBTREE QUERIES.
    WE WILL FLATTEN THE TREE BY EULER TOUR.
    THEN, THE FIRST AND THE LAST APPEARING POSITION IN THE EULER TOUR IS OUR L AND R.
    WE CAN DO SUM UPDATE QUERIES WITH SQUARE ROOT DECOMPOSITION IN O(1).
    SEGMENT TREE TAKES O(LOGN).
    EVERY NODE IN L TO R IS REPEATING TWICE.
    */
    ll n,m;
    cin>>n>>m;
    for(ll i=1; i<=n; i++) cin>>color[i];
    vector<vector<ll>> adj(n+1);
    for(ll i=0; i<(n-1); i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(ll i=0; i<=n; i++)
    {
        start[i] = -1;
        last[i] = -1;
    }
    ll curr = 0;
    eulor(adj, 1, -1, eutour, start, last, curr);
    for(ll i=0; i<m; i++)
    {
        ll x;
        cin>>x;
        ll l = start[x];
        ll r = last[x];
        ll k;
        cin>>k;
        query.pb({l,r,k,i});
    }
    sort(all(query), comp);
    ll start1 = 0, end1 = -1;
    for(ll i=0; i<query.size(); i++)
    {
        ll l = query[i][0];
        ll r = query[i][1];
        ll k = query[i][2];
        while(r>end1) add(++end1);
        while(l<start1) add(--start1);
        while(r<end1) remove(end1--);
        while(l>start1) remove(start1++);
        ll a1 = getsum(k,n);
        ans[query[i][3]] = a1;
    }
    for(ll i=0; i<m; i++)
    {
        cout<<ans[i]<<endl;
    }
    timetaken;
    return 0;
}