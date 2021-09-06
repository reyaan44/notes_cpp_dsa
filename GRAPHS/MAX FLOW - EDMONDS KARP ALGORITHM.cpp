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
vector<ll> adj[100001];
ll n;
vector<vector<ll>> capacity(100001);
ll bfs(ll start, ll end, vector<ll> & parent)
{
    parent.assign(n+1,-1);
    parent[start]=-2;   
    queue<pair<ll,ll>> q;
    q.push({start,LLONG_MAX});

    while(!q.empty())
    {
        ll curr = q.front().first;
        ll flow = q.front().second;
        q.pop();

        for(ll i = 0; i<adj[curr].size(); i++)
        {
            if(parent[adj[curr][i]]==-1 && capacity[curr][adj[curr][i]])    // PARENT IS -1 MEANS NOT VISITED, CAPACITY[CURR].. MEANS THE NEXT EDGE TO IT IN ADJACENCY LIST
            {
                parent[adj[curr][i]]=curr;
                ll new_flow = min(flow,capacity[curr][adj[curr][i]]);
                if(adj[curr][i]==end)
                {
                    return new_flow;
                }
                q.push({adj[curr][i], new_flow});
            }
        }
    }
    return 0;
}
ll max_flow(ll start, ll end)
{
    ll flow = 0;
    vector<ll> parent(n+1,0);   // PARENT ARRAY
    ll new_flow;
    while(new_flow = bfs(start, end, parent))
    {
        flow+=new_flow;
        ll curr = end;  
        while(curr!=start)  // BACKTRACK
        {
            ll prev = parent[curr];        
            capacity[prev][curr]-=new_flow; // IN RESIDUAL, THIS MUCH IS USED
            capacity[curr][prev]+=new_flow; // REVERSE RESIDUAL, STORES HOW MUCH CAN BE TAKEN OUT OF THIS EDGE
            curr = prev;
        }
    }
    return flow;
}
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll m;
    cin>>n>>m;
    ll source, sink;    // START, END
    cin>>source>>sink;
    for(ll i=0; i<n+1; i++)
    {
        capacity[i] = vector<ll>(n+1,0);    // INITITALIZING 2D VECTOR FOR STORING RESIDUAL CAPACITY
                                            // RESIDUAL CAPACITY MEANS THE LEFT SPACE WHICH CAN NE FILLED IN AN EDGE
    }
    for(ll i=0; i<m; i++)
    {
        ll a,b,w;
        cin>>a>>b>>w;   // W IS MAXIMUM CAPACITY
        adj[a].pb(b);
        capacity[a][b]=w;
    }
    cout<<max_flow(source,sink)<<endl;
    timetaken;
    return 0;
}