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
set<ll> no_of_articulation_points;  // TO REMOVE AMBIGUOUS POINTS, BECAUSE SAME NODE CAN BE REPORTED AS ARTICULATION POINTS BY DIFFERENT SUBTREES IN A GRAPH
ll timer = 0;
/*
    LOW OF A NODE IS THE LOWEST ANCESTOR THAN CAN BE REACHED FROM THAT CURRENT NODE.
*/
void dfs(ll a, ll parent)   
{
    visited[a]=1;
    low[a]=in[a]=timer++;
    ll degree = 0;
    for(ll i=0; i<adj[a].size(); i++)
    {
        if(adj[a][i]==parent) continue;
        if(visited[adj[a][i]]==1)
        {
            low[a] = min(low[a],in[adj[a][i]]);
        }
        else
        {
            dfs(adj[a][i],a);
            low[a] = min(low[a],low[adj[a][i]]);
            if(low[adj[a][i]]>=in[a] && parent!=-1)
            /*
                WE ARE CHECKING IF THE CHILD OF THE CURRENT NODE IS CONNECTED TO SOME ANCESTOR OR NOT, IF IT IS
                CONNECTED, THEN IT CANNOT BE ARTICULATION POINT. IF IT IS NOT CONNECTED, AND IF IT IS NOT A ROOT
                NODE ACCORDING TO DFS TREE, THEN IT IS AN ARTICULATION POINT.
            */
            {
                no_of_articulation_points.insert(a);
            }
            degree++;
        }
    }
    if(parent==-1 && degree>=2) // CHECK FOR ROOT. WHY THIS ? BECAUSE CONSIDER A CASE : 1-2, 2-3, 1-3.
    {
        no_of_articulation_points.insert(a);
    }
}
int main()
{
    ll n,e;
    cin>>n>>e;
    for(ll i=0; i<e; i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(ll i=1; i<=n; i++)
    {
        if(visited[i]==0)
        {
            dfs(i,-1);
        }
    }
    cout<<"NUMBER OF ARTICULATION POINTS/CUT VERTICES = "<<no_of_articulation_points.size()<<endl;
    return 0;
}