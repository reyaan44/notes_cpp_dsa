#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
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
// using namespace __gnu_pbds;
// template<class T> 
// using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
const ll M = 1000000007;
ll fact[200001] = {};
inline bool comp(ll x,ll y) { return x<y; } // INITIALLY IN DEFAULT INCREASING ORDER (SMALL TO BIG)
inline ll mod(ll x) {ll a1=(x%M); if(a1<0){a1+=M;} return a1;}
inline ll power(ll x, unsigned ll y, ll p = LLONG_MAX) {ll res=1; x=x%p; if(x==0) {return 0;} while(y>0){ if(y&1){res=(res*x)%p;} y=y>>1; x=(x*x)%p;} return res;} // CALCULATING POWER IN LOG(Y) TIME COMPLEXITY
inline ll inversePrimeModular(ll a, ll p) {return power(a,p-2,p);}
inline void calcFact(ll n) { fact[0] = 1; for(ll i=1; i<=n; i++){ fact[i] = fact[i-1]*i; fact[i] = mod(fact[i]); }}
inline ll ncr(ll n, ll r) { if(n<r) return 0; return mod(inversePrimeModular(mod(fact[n-r]*fact[r]),M)*fact[n]); }
struct custom_hash { static uint64_t splitmix64(uint64_t x)  { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); }};
void insert(ll arr[], ll x, ll n)   //  TO BE CALLED AFTER EVERY EMELEMT INSERTION (TAKES O(LOGN) IN 1 OPERATION)
{
    while(n>1)
    {
        if(arr[n/2]<arr[n])
        {
            swap(arr[n/2], arr[n]);
            n=n/2;
        }
        else break;
    }
}
void heapify(ll arr[], ll n) // HEAPIFY, MAKE WHOLE ARRAY A HEAP WITH O(N) TIME
{
    for(ll i=n; i>=1; i--)
    {
        ll curr = i;
        while(1)
        {
            if(curr*2<=n)
            {
                if(((curr*2)+1)<=n)
                {
                    if(arr[curr*2]>arr[(curr*2)+1])
                    {
                        if(arr[curr*2]>arr[curr])
                        {
                            swap(arr[curr*2], arr[curr]);
                            curr= curr*2;
                        }
                        else break;
                    }
                    else if(arr[curr*2]<arr[(curr*2)+1])
                    {
                        if(arr[(curr*2)+1]>arr[curr])
                        {
                            swap(arr[(curr*2)+1], arr[curr]);
                            curr = (curr*2)+1;
                        }
                        else break;
                    }
                    else break;
                }
                else
                {
                    if(arr[curr*2]>arr[curr])
                    {
                        swap(arr[curr*2], arr[curr]);
                        curr=curr*2;
                    }
                }
            }
            else break;
        }
    }
}
void heapsort(ll arr[], ll n)
{
    ll curr = n;
    for(ll i=1; i<=n; i++)
    {
        ll k = 1;
        swap(arr[k], arr[curr]);
        curr--;
        while(1)
        {
            if((k*2)<=curr)
            {
                if(((k*2)+1)<=curr)
                {
                    if(arr[k*2]>arr[(k*2)+1])
                    {
                        if(arr[k*2]>arr[k])
                        {
                            swap(arr[k*2], arr[k]);
                            k=k*2;
                        }
                        else break;
                    }
                    else if(arr[(k*2)+1]>=arr[k*2])
                    {
                        if(arr[(k*2)+1]>arr[k])
                        {
                            swap(arr[(k*2)+1], arr[k]);
                            k=(k*2)+1;
                        }
                        else break;
                    }
                    else break;
                }
                else
                {
                    if(arr[k*2]>arr[k])
                    {
                        swap(arr[k], arr[k*2]);
                        k=k*2;
                    }
                    else break;
                }
            }
            else break;
        }
    }
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
    ll arr[n+1];
    for(ll i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    ll k;
    cin>>k;
    heapify(arr,n);
    heapsort(arr,n);
    cout<<"AFTER HEAP SORT : ";
    for(ll i=1; i<=n; i++) cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"ELEMENT NO."<<k<<" = ";
    cout<<arr[k]<<endl;
    timetaken;
    return 0;
}