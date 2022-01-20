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
const ll maxN = 100001;
const ll BLK = 700;
ll fact[maxN] = {}, smallestPrimeFactor[maxN] = {}, isPrimeSieve[maxN] = {};
mt19937_64 my_rand(chrono::steady_clock::now().time_since_epoch().count());
inline bool comp(ll x,ll y) { return x<y; } // INITIALLY IN DEFAULT INCREASING ORDER (SMALL TO BIG)
inline ll mod(ll x) {ll a1=(x%M); if(a1<0){a1+=M;} return a1;}
inline ll power(ll x, unsigned ll y, ll p = LLONG_MAX) {ll res=1; x=x%p; if(x==0) {return 0;} while(y>0){ if(y&1){res=(res*x)%p;} y=y>>1; x=(x*x)%p;} return res;} // CALCULATING POWER IN LOG(Y) TIME COMPLEXITY
inline ll inversePrimeModular(ll a, ll p) {return power(a,p-2,p);}
inline void calcFact(ll n) { fact[0] = 1; for(ll i=1; i<=n; i++){ fact[i] = fact[i-1]*i; fact[i] = mod(fact[i]); }}
inline ll ncr(ll n, ll r) { if(n<r) return 0; return mod(inversePrimeModular(mod(fact[n-r]*fact[r]),M)*fact[n]); }
struct custom_hash { static uint64_t splitmix64(uint64_t x)  { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); }};
void sieve(ll n) { for(ll i=1; i<=n; i++) smallestPrimeFactor[i] = i; for(ll i=2; (i*i)<=n; i++) { if(smallestPrimeFactor[i]==i) { for(ll j=(i*i); j<=n; j+=i) { smallestPrimeFactor[j] = min(smallestPrimeFactor[j], i); } } } for(ll i=2; i<=n; i++) { if(smallestPrimeFactor[i]==i) isPrimeSieve[i] = 1; } }
vector<ll> eutour, beg(maxN), last(maxN), depth(maxN), vect(maxN), ans(200001), freq(maxN), val_freq(maxN);
vector<vector<ll>> BiLift(maxN, vector<ll>(22)), query, adj(maxN);
void euler(vector<vector<ll>> &adj, ll a, ll par, ll &curr, ll height)
{
    depth[a] = height;
    BiLift[a][0] = par;
    eutour.pb(a);
    beg[a] = curr++;
    for(auto child: adj[a])
    {
        if(child==par) continue;
        euler(adj, child, a, curr, height+1);
    }
    last[a] = curr++;
    eutour.pb(a);
}
ll LCA(ll a, ll b)
{
    if(depth[a]>depth[b]) swap(a,b);
    ll diff = depth[b] - depth[a];
    ll curr = 0;
    while(diff)
    {
        if(diff&1) b = BiLift[b][curr];
        curr++;
        diff>>=1;
    }
    if(a==b) return a;
    for(ll i = BiLift[0].size()-1; i>=0; i--)
    {
        if(BiLift[a][i]!=BiLift[b][i] && BiLift[a][i]!=-1 && BiLift[b][i]!=-1)
        {
            a = BiLift[a][i];
            b = BiLift[b][i];
        }
    }
    return BiLift[a][0];
}
inline bool comp1(vector<ll> &v1, vector<ll> &v2)
{
    ll left1 = v1[0]/BLK;
    ll left2 = v2[0]/BLK;
    if(left2!=left1) return left1<left2;
    if(left2&1) return v1[1]<v2[1];
    return v2[1]<v1[1];
}
void add(ll idx)
{
    ll node = eutour[idx];
    freq[node]++;
    if(freq[node]==2)
    {
        ll c = vect[node];
        val_freq[c]--;
    }
    else
    {
        ll c = vect[node];
        val_freq[c]++;
    }
}
void remove(ll idx)
{
    ll node = eutour[idx];
    freq[node]--;
    if(freq[node]==1)
    {
        ll c = vect[node];
        val_freq[c]++;
    }
    else
    {
        ll c = vect[node];
        val_freq[c]--;
    }
}
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    /*
    THERE ARE TWO TYPES OF QUERIES FOR PATH QUERIES.
    FIRSTLY, WE FLATTEN THE TREE ITH EULOR TOUR.
    NOW WE GET TWO NODES A AND B IN QUERY.
    IF B IS IN SUBTREE OF A, L = START(A) AND R = START(B)
    ELSE L = END(A) AND R = START(B) ALONG WITH THE LCA OF BOTH OF THEM.
    FOR LCA WE ARE DOING BINARY LIFTING.
    THIS IS A SPOJ SOLUTION OF CODE "GOT".
    WE NEED TO FIND IF THERE EXIST A NODE WITH A CERTAIN VALUE ON THE PATH FROM A TO B.
    */
    ll n,q;
    bool check = 0;
    while(cin>>n)
    {
        if(check) cout<<endl;
        check = 1;
        query.clear();
        eutour.clear();
        for(ll i=0; i<=n; i++)
        {   
            freq[i] = val_freq[i] = 0;
            adj[i].clear();
        }
        cin>>q;
        for(ll i=1; i<=n; i++) cin>>vect[i];
        for(ll i=0; i<(n-1); i++)
        {
            ll a,b;
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        ll curr = 0;
        euler(adj, 1, -1, curr, 1);
        for(ll j=1; j<BiLift[0].size(); j++)
        {
            for(ll i=1; i<=n; i++)
            {
                if(BiLift[i][j-1]==-1) BiLift[i][j] = -1;
                else BiLift[i][j] = BiLift[BiLift[i][j-1]][j-1];
            }
        }
        for(ll i=0; i<q; i++)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            if(beg[a]>beg[b]) swap(a,b);
            ll lca = LCA(a,b);
            if(lca==a) query.pb({beg[a],beg[b],c,i,-1}); // LCA -1 BECAUSE WE DONOT NEED LCA HERE AND THIS IS FIRST TYPE OF PATH QUERY IN WHICH B IS IN THE SUBTREE OF A
            else query.pb({last[a],beg[b],c,i,lca}); // LCA NEEDED BECAUSE ON THE PATH FROM END(A) TO START(B), THEIR LCA IS MISSED, SO WE WILL INCLUDE THAT AS WELL.
        }
        sort(all(query), comp1);
        ll start = 0, end = -1;
        for(ll i=0; i<q; i++)
        {
            ll l = query[i][0];
            ll r = query[i][1];
            ll c = query[i][2];
            ll idx = query[i][3];
            ll lca = query[i][4];
            while(r>end) add(++end);
            while(start>l) add(--start);
            while(r<end) remove(end--);
            while(start<l) remove(start++);
            if(val_freq[c] || (lca!=-1 && vect[lca]==c)) ans[idx] = 1;
            else ans[idx] = 0;
        }
        for(ll i=0; i<q; i++)
        {
            if(ans[i]) cout<<"Find"<<endl;
            else cout<<"NotFind"<<endl;
        }
    }
    timetaken;
    return 0;
}