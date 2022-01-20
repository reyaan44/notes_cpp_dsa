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
const ll BLK = 700; // DEFAULT FOR 10^6 // BLK is block size
inline bool comp(pair<ll,pair<ll,ll>> &l, pair<ll,pair<ll,ll>> &r) 
{
    ll left1 = l.ff/BLK;
    ll left2 = r.ff/BLK;
    if(left1<left2) return 1;
    else if(left1>left2) return 0;
    ll right1 = l.ss.ff;
    ll right2 = r.ss.ff;
    if(right1<right2) return 1;
    return 0;
}
inline bool optimized_comp(pair<ll,pair<ll,ll>> &l, pair<ll,pair<ll,ll>> &r)
{
    ll left1 = l.ff/BLK;
    ll left2 = r.ff/BLK;
    if(left1<left2) return 1;
    else if(left1>left2) return 0;
    if(left1&1) return l.ss.ff<r.ss.ff;
    return l.ss.ff>r.ss.ff;
}
void add(ll x, ll &curr)
{
    curr+=x;
}
void remove(ll x, ll &curr)
{
    curr-=x;
}
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    /*
        Mo's Algorithm - Find out the total number of unique elements in range of L to R for Q queries
        Time Complexity - O(N) for precomputation and O(sqrt(N)) for each query
        We will sort the queries based onn the block size of sqrt decomposition.
        If Left of both L is diff, smaller first.
        If Left of both L is same, smaller Right.
    */
    testcase
    {
        ll n,q;
        cin>>n;
        ll arr[n];
        scanit(arr,n);
        cin>>q;
        vector<pair<ll,pair<ll,ll>>> queries;
        ll i = 0;
        while(q--)
        {
            ll l,r;
            cin>>l>>r;
            l--;
            r--;
            queries.pb({l,{r,i}});
            i++;
        }
        vector<ll> ans(queries.size(),0);
        sort(all(queries), comp);
        ll start = 0, end = -1;
        ll curr = 0;
        for(ll i=0; i<queries.size(); i++)
        {
            ll l = queries[i].ff;
            ll r = queries[i].ss.ff;
            while(l<start)
            {
                start--;
                add(arr[start], curr);
            }
            while(r>end)
            {
                end++;
                add(arr[end], curr);
            }
            while(l>start)
            {
                remove(arr[start], curr);
                start++;
            }
            while(r<end)
            {
                remove(arr[end], curr);
                end--;
            }
            ans[queries[i].ss.ss] = curr;
        }
        for(ll i=0; i<ans.size(); i++)
        {
            cout<<ans[i]<<endl;
        }
    }
    timetaken;
    return 0;
}