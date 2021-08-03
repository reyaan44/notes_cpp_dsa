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
map<ll,vector<ll>> adj;
map<ll,bool> visited;
map<ll,ll> colour;  // STORES THE COLOUR OF THE NODE
bool dfs(ll a, ll c)    // C IS COLOUR
{
    visited[a]=1;
    colour[a]=c;
    for(auto itr = adj[a].begin(); itr!=adj[a].end(); itr++)
    {
        if(visited[*itr]==0)
        {
            if(!dfs(*itr,c^1))  // 0 BECOMES 1, 1 BECOMES 0.
            {
                return false;
            }
        }
        else if(colour[*itr]==colour[a]) return false;
    }
    return true;
} 
bool isBiPartite()
{
    for(auto itr = visited.begin(); itr!=visited.end(); itr++)  // FOR NON-CONNECTED COMPONENTS
    {
        if(visited[itr->second]==0)
        {
            if(!dfs(itr->first,1)) return false;
        }
    }
    return true;
}
int main()
{
    ll n;
    cout<<"ENTER THE NUMBER OF EDGES : "; cin>>n;
    for(ll i=0; i<n; i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b), adj[b].pb(a), visited[a]=0, visited[b]=0;
    }
    if(isBiPartite()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}