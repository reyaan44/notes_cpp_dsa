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
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s1,s2;
    cin>>s1>>s2;
    if(s1.length()==0 || s2.length()==0)
    {
        cout<<"0"<<endl;
        return 0;
    }
    int n = s1.length();
    int m = s2.length();
    int dp[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            dp[i][j] = 0;
            if(s1[i]==s2[j])
            {
                if(i-1>=0 && j-1>=0)
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                dp[i][j]++;
            }
            else
            {
                if(i-1>=0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
                if(j-1>=0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
        }
    }
    cout<<dp[n-1][m-1]<<endl;
    timetaken;
    return 0;
}
/*

*/