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
vector<ll> adj[1000001];
ll visited[1000001], low[1000001], in[1000001];
ll timer = 0;   // TIMER FOR RECORDING IN TIME OF NODES
/*
    LOW OF A NODE IS THE LOWEST ANCESTOR THAN CAN BE REACHED FROM THAT CURRENT NODE.
*/
/*
    LOW IS THE LOWEST ANCESTOR OF A NODE IN THE GRAPH, THATS WHY FIRST WE TAKE IT AS ITSELF ONLY,
    THEN IF(WE GET A BACK EDGE) WE UPDATE THE LOW OF THAT NODE, WHICH INDICATES THAT THE NODE CAN BE
    REACHED THROUGH THAT ABOVE ANCESTOR WITH LESSER IN TIME ALSO.
*/
void dfs(ll a, ll parent)
{
    visited[a]=1;
    in[a]=low[a]=timer++;
    for(auto i = 0; i<adj[a].size(); i++)
    {
        if(adj[a][i]==parent) continue;
        if(visited[adj[a][i]]==1)   // BACK EDGE
        {
            low[a] = min(in[adj[a][i]],low[a]); // IN TIME OF THE ANCESTOR, LOW OF CURRENT NODE
        }
        else
        {
            dfs(adj[a][i],a);   // FORWARD EDGE
            if(in[a]<low[adj[a][i]])    
            /*
                COMPARING TWO NODES TO SEE IF THEIR EDGE IS A BRIDGE OR NOT DURING BACKTRACKING,
                HERE, IF INTIME OF THAT NODE IS >= LOW OF ITS CHILD NODE, MEANS THE CHILD NODE IS CONNECTED
                TO SOME ANOTHER ANCESTOR AS IT IS REACHABLE THROUGH THAT ANCESTOR, OTHERWISE IF INTIME OF THAT
                NODE < LOW OF ITS CHILD NODE, THE CHILD NODE CAN ONLY BE REACHED THROUGH THAT NODE, SO IT IS A BRIDGE
                BECAUSE IF WE CUT IT OFF, WE WILL HAVE TWO OR MORE CONNECTED COMPONENTS.
            */
            {
                cout<<a<<" - "<<adj[a][i]<<" IS A BRIDGE."<<endl;
            }
            low[a] = min(low[a],low[adj[a][i]]);    // UPDATING THE LOW OF THE NODE TO SHOW THAT THIS NODE
                                                    // IS ACCESSIBLE FROM THAT ANCESTOR
        }
    }
}
int main()
{
    ll n,e; // N = NO. OF NODES // E = NO. OF EDGES
    cin>>n>>e;
    for(ll i=0; i<e; i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(ll i=1; i<=n; i++)   // FOR DISCONNECTED GRAPHS
    {
        if(visited[i]==0)
        {
            dfs(i,-1);
        }
    }
    return 0;
}