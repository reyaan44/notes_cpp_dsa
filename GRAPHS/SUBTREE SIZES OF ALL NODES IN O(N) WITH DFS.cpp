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
#define iendl "\n", cout.flush // FOR INTERACTIVE PROBLEMS
#define getlineinput(a) cin>>ws; getline(cin,a); // CIN>>WS TO CLEAR THE INPUT BUFFER AS GETLINE INCLUDES SPACES FROM JUST THE START
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,b) for(ll i=a; i<b; ++i)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;
const ll M = 1000000007;
inline bool comp(ll x,ll y)
{
    return x<y; // INITIALLY IN DEFAULT INCREASING ORDER (SMALL TO BIG)
}
inline ll mod(ll x)
{
    return (x%M + M)%M;
}
ll visited[100001];
vector<ll> adj[100001];
ll subtreeSize[100001];
ll dfs(ll a)
{
    visited[a]=1;
    ll curr_dist = 1;
    for(ll i=0; i<adj[a].size(); i++)
    {
        if(visited[adj[a][i]]==0)   // IN A TREE, IF A NODE IS UNVISITED, THEN IT IS SURELY A CHILD OF CURRENT NODE OF FUNCTION
        {
            curr_dist+=dfs(adj[a][i]);
        }
    }
    subtreeSize[a]=curr_dist;
    return curr_dist;   // 1 FOR LAST NODES.
}
int main()  // FOR TREES ONLY
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif  
    ll n,e;
    cin>>n>>e;
    for(ll i=0; i<e; i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1); // ROOT NODE
    cout<<"SUBTREE SIZE : ";
    for(ll i=1; i<=n; i++)
    {
        cout<<subtreeSize[i]<<" ";
    }
    cout<<endl;
    timetaken;
    return 0;
}