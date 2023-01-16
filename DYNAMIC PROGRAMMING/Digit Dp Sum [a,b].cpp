// Code by Reyaan Jagnani
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
ll fact[maxN] = {}, smallestPrimeFactor[maxN] = {}, isPrimeSieve[maxN] = {};
mt19937_64 my_rand(chrono::steady_clock::now().time_since_epoch().count());
inline bool comp(ll x,ll y) { return x<y; } // INITIALLY IN DEFAULT INCREASING ORDER (SMALL TO BIG)
inline ll mod(ll x) {ll a1=(x%M); if(a1<0){a1+=M;} return a1;}
inline ll power(ll x, unsigned ll y, ll p = LLONG_MAX) {ll res=1; x=x%p; if(x==0) {return 0;} while(y>0){ if(y&1){res=(res*x)%p;} y=y>>1; x=(x*x)%p;} return res;} // CALCULATING POWER IN LOG(Y) TIME COMPLEXITY
inline ll inversePrimeModular(ll a, ll p) {return power(a,p-2,p);}
inline void calcFact(ll n = maxN-1) { fact[0] = 1; for(ll i=1; i<=n; i++){ fact[i] = fact[i-1]*i; fact[i] = mod(fact[i]); }}
inline ll ncr(ll n, ll r) { if(n<r) return 0; return mod(inversePrimeModular(mod(fact[n-r]*fact[r]),M)*fact[n]); }
inline ll ceil(ll a, ll b) { if(b==0) return LLONG_MAX; ll ans = (a+b-1)/b; return ans; }
struct custom_hash { static uint64_t splitmix64(uint64_t x)  { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); }};
void sieve(ll n = maxN-1) { for(ll i=1; i<=n; i++) smallestPrimeFactor[i] = i; for(ll i=2; (i*i)<=n; i++) { if(smallestPrimeFactor[i]==i) { for(ll j=(i*i); j<=n; j+=i) { smallestPrimeFactor[j] = min(smallestPrimeFactor[j], i); } } } for(ll i=2; i<=n; i++) { if(smallestPrimeFactor[i]==i) isPrimeSieve[i] = 1; } }
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
/*
dp[i][tight][sum_till_now]

We start from biggest to smallest positions.

We are saying ki, if at current i,tight,sum_till_now,
there are i digits remaining towards the right of the current digit
position, and the tightness is 0/1 for the current digit, and the
sum_till_now is this.

So, if tight = 0, we can chose any number in this position from
0 to 9, and we can add it to our sum_till_now and pass it further.
And if tight = 1, then, lets say "curr" is the current digit at ith
position, so, if we chose any digit from [0, curr-1], we can pass it
further as tightness 0, AND if we choose digit {curr}, the tightness for further steps
will be 1.

Base case is when no digits are left, where, we will return sum_till_now

The answer will be [n][1][0]
n digits left, tightness is 1, because we haven't started yet, and sum = 0

*/
ll dp[20][2][200] = {};
string s;
ll func(ll digits, ll tight, ll sum, ll pos)
{
    if(dp[digits][tight][sum] != -1)
        return dp[digits][tight][sum];
    if(digits==0)
        return sum;
    ll curr = s[pos]-'0';
    ll ans = 0;
    if(!tight)
    {
        for(ll i=0; i<=9; i++)
            ans += func(digits-1, 0, sum+i, pos+1);
    }
    else
    {
        for(ll i=0; i<curr; i++)
            ans += func(digits-1, 0, sum+i, pos+1);
        ans += func(digits-1, 1, sum+curr, pos+1);
    }
    return dp[digits][tight][sum] = ans;
}
ll solve(ll n)
{
    if(n<=0)
        return 0;
    s = to_string(n);
    n = s.length();
    for(ll i=0; i<20; i++)
    {
        for(ll j=0; j<2; j++)
        {
            for(ll k=0; k<200; k++)
                dp[i][j][k] = -1;
        }
    }
    return func(n, 1, 0, 0);
}
/*
https://www.spoj.com/problems/PR003004/
Find sum of digits in range [a,b]
We will find [1,b] - [1,a-1].
*/
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    testcase
    {
        ll a,b;
        cin>>a>>b;
        cout<<solve(b)-solve(a-1)<<endl;
    }
    timetaken;
    return 0;
}
/*
46
28
1128600

1. Binary Search / Binary Search on Answer
2. Bit
3. Parity (Odd / Even)
4. DP / Greedy
5. Graph / Bi-Partite
*/  