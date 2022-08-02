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
TRIES are also useful when doing xor operations on the array.
Just convert each of these into binary string and put it in trie.

problem1 : https://www.spoj.com/problems/ADAINDEX/
solution1 : 29748062

problem2 : https://codeforces.com/problemset/problem/706/D
solution2 : https://codeforces.com/contest/706/submission/162279761
*/

class node // characters are present on edges in tries
{   
public:
    ll curr;    // current occurrences
    node* next[26];
    node()
    {
        curr = 0;
        for(ll i=0; i<26; i++)
            next[i] = NULL;
    }
    void insert(ll idx, string &s)  // insert string
    {
        curr++;
        if(idx==s.length())
            return;
        if(next[s[idx]-'a']==NULL)
            next[s[idx]-'a'] = new node();
        next[s[idx]-'a']->insert(idx+1,s);
    }
    ll search(ll idx, string &s) // total prefixes
    {
        if(idx==s.length())
            return curr;
        if(next[s[idx]-'a']==NULL)
            return 0;
        else
            return next[s[idx]-'a']->search(idx+1,s);
    }
    bool remove(ll idx, string &s)   // remove string
    {
        curr--;
        if(curr==0)
            return 0;
        if(idx==s.length())
            return 1;
        if(next[s[idx]-'a']!=NULL)
        {
            bool check = next[s[idx]-'a']->remove(idx+1,s);
            if(!check)
                next[s[idx]-'a'] = NULL;
        }
        return 1;
    }
};
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    node* root = new node();
    ll n;
    cin>>n;
    for(ll i=0; i<n; i++)
    {
        string s;
        cin>>s;
        root->insert(0,s);
    }
    cin>>n;
    for(ll i=0; i<n; i++)
    {
        string s;
        cin>>s;
        cout<<root->search(0,s)<<endl;
    }
    cin>>n;
    for(ll i=0; i<n; i++)
    {
        string s;
        cin>>s;
        root->remove(0,s);
    }
    cin>>n;
    for(ll i=0; i<n; i++)
    {
        string s;
        cin>>s;
        cout<<root->search(0,s)<<endl;
    }
    /*
    4
    abc
    aba
    ab
    aca
    1
    ab
    1
    abc
    2
    ab
    abc

    3
    2
    0
    */
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