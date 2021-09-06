#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define scanit(a,n) for(ll indexaa=0; indexaa<n; indexaa++) cin>>a[indexaa];
#define printit(a,n) for(ll indexaa=0; indexaa<n; indexaa++) cout<<a[indexaa]<<" "; cout<<endl;
#define pb push_back
#define mp make_pair
#define precision(a) cout<<fixed<<setprecision(a)
#define testcase ll t; cin>>t; while(t--)
#define endl "\n"
#define iendl "\n", cout<<flush // FOR INTERACTIVE PROBLEMS
#define getlineinput(a) cin>>ws; getline(cin,a); // CIN>>WS TO CLEAR THE INPUT BUFFER AS GETLINE INCLUDES SPACES FROM JUST THE START
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,b) for(ll i=a; i<b; ++i)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    /*  
        TIME COMPLEXITY = O(N^3)
        IF A GRAPH IS SPARSE MATRIX, USE DIJSKTRAS ALGORITHM, ELSE USE FLOYD MASHALL ALGORITHM
    */
    ll n,e;
    cin>>n>>e;
    ll arr[n+1][n+1];
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            arr[i][j] = INT_MAX;
            if(i==j) arr[i][j]=0;
        }
    }
    for(ll i=0; i<e; i++)
    {
        ll a,b,w;
        cin>>a>>b>>w;
        arr[a][b] = min(arr[a][b],w);
    }   
    for(ll k = 1; k<=n; k++)
    {
        for(ll i = 1; i<=n; i++)
        {
            for(ll j=1; j<=n; j++)
            {
                arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);
            }
        }
    }
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    timetaken;
    return 0;
}