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
vector<ll> adj[10001];
vector<ll> tra[10001];
ll visited[10001];
vector<ll> out;
ll ans = 0;
void dfs(ll a)
{
    visited[a]=1;
    for(ll i=0; i<adj[a].size(); i++)
    {
        if(visited[adj[a][i]]==0)
        {
            dfs(adj[a][i]);
        }
    }
    out.pb(a);  // INSERTING THE NODES WITH THEIR OUT TIME IN ASCENDING ORDER
}
void dfsUtil(ll a)  // TRANSPOSE GRAPH, A IS THE VERTEX WITH VISITED==0 AND LARGEST OUT TIME DEGREE IN REAL GRAPH, WHOCH MAKES IT LEAST IN TIME DEGREE IN TRANSPOSE GRAPH
{
    visited[a]=1;
    for(ll i=0; i<tra[a].size(); i++)
    {
        if(visited[tra[a][i]]==0)
        {
            dfsUtil(tra[a][i]);
        }
    }
}
/*
    POINTS 
    1. A TRANSPOSE GRAPH IN A DIRECTED GRAPH IS THAT ALL THE EDGES ARE TURNED. A->B BECOMES B->A
    2. STRONGLY CONNECTED COMPONENTS REMAINS SAME FOR REAL AND TRANSPOSE GRAPH
    3. EVERY DAG (DIRECTED ACYCLIC GRAPH) HAS ATLEAST 1 NODE WITH IN DEGREE 0
    4. EVERY CONDESATION GRAPH IS A DAG.
    5. THE VERTEX WITH MAXIMUM OUT TIME IS THE PART OF THE STRONGLY CONNECTED COMPONENT WITH IN DEGREE 0 WHILE REPRESENTED AS CONDENSATION GRAPH
    6. IN DEGREE 0 IN REAL GRAPHS MEANS OUT DEGREE 0 IN TRANSPOSE GRAPH, SO AS IT STOPS THE DFS IN BETWEEN DUE TO NO MORE STEPS POSSIBLE, IT BECOMES ONE SCC(STRINGLY CONNECTED COMPONENT)
*/
int main()
{
    ll n,e;
    cin>>n>>e;
    for(ll i=0; i<e; i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        tra[b].pb(a);   // TRANSPOSE GRAPH HAS OPPOSITE DIRECTED EDGES
    }
    for(ll i=1; i<=n; i++)
    {
        if(visited[i]==0)
        {
            dfs(i);
        }
    }
    for(ll i=1; i<=n; i++)  // IT WILL BE USED AGAIN FOR DFS IN TRANSPOSE GRAPH
    {
        visited[i]=0;
    }
    reverse(out.begin(), out.end());    // NOW IN DESCENDING ORDER OUT TIME
    for(ll i=0; i<out.size(); i++)
    {
        if(visited[out[i]]==0)
        {
            dfsUtil(out[i]);
            ans++;
        }
    }
    cout<<"STRONGLY CONNECTED COMPONENTS = "<<ans<<endl;
    return 0;
}