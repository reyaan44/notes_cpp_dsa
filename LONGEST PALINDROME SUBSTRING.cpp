#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#define ll long long int
#define ld long double
#define ff first
#define ss second
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
const ll M = 1000000007;
inline bool comp(ll x,ll y) { return x<y; } // INITIALLY IN DEFAULT INCREASING ORDER (SMALL TO BIG)
inline ll mod(ll x) {ll a1=(x%M); if(a1<0){a1+=M;} return a1;}
inline ll power(ll x, unsigned ll y, ll p = LLONG_MAX) {ll res=1; x=x%p; if(x==0) {return 0;} while(y>0){ if(y&1){res=(res*x)%p;} y=y>>1; x=(x*x)%p;} return res;} // CALCULATING POWER IN LOG(Y) TIME COMPLEXITY
inline ll inversePrimeModular(ll a, ll p) {return power(a,p-2,p);}
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // LONGEST PALINDROMIC SUBSTRING
    string s;
    cin>>s;
    ll n = s.length();
    ll dp[n+1][n] = {}; // n+1 for lenghts, n for the index in string
    for(ll i=0; i<n; i++)
    {
        dp[0][i] = 1;
        dp[1][i] = 1;
    }
    for(ll i=2; i<n+1; i++)
    {
        for(ll j=i-1; j<n; j++)
        {   
            if(dp[i-2][j-1]==1 && s[j]==s[j-i+1])   // i-2 and j-1 for checking whther the string which is has length 2 smaller than the string is palindrome or not
                                                    // j and j-i+1 means checking the first and last charachters of this string 
            {
                dp[i][j] = 1;
            }
        }
    }
    for(ll i=0; i<n+1; i++)
    {
        for(ll j=0; j<n; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    timetaken;
    return 0;
}