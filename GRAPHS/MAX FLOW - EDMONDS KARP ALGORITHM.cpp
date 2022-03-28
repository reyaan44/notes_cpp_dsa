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
vector<vector<ll>> adj(501);
ll n;
vector<vector<ll>> capacity(501);
ll bfs(ll start, ll end, vector<ll> & parent)
{
    parent.assign(n+1,-1);
    parent[start] = 0;   
    queue<ll> q;
    q.push(start);
    ll flow = LLONG_MAX;
    while(!q.empty())
    {
        ll curr = q.front();
        q.pop();
        for(auto next: adj[curr])
        {
            if(parent[next]==-1 && capacity[curr][next])    // PARENT IS -1 MEANS NOT VISITED, CAPACITY[CURR].. MEANS THE NEXT EDGE TO IT IN ADJACENCY LIST
            {
                parent[next] = curr;
                flow = min(flow, capacity[curr][next]);
                if(next==end) return flow;
                q.push(next);
            }
        }
    }
    return 0;
}
ll max_flow(ll start, ll end)
{
    ll flow = 0;
    vector<ll> parent(n+1);
    ll new_flow;
    while(new_flow = bfs(start, end, parent))   // FINDING AUGUMENTING PATH
    {
        flow+=new_flow;
        ll curr = end;  
        while(curr!=start)
        {
            ll prev = parent[curr];        
            capacity[prev][curr]-=new_flow; // IN RESIDUAL, THIS MUCH IS USED
            capacity[curr][prev]+=new_flow; // REVERSE RESIDUAL, STORES HOW MUCH CAN BE TAKEN OUT OF THIS EDGE
            curr = prev;
        }
    }
    return flow;
}
// https://cp-algorithms.com/graph/edmonds_karp.html
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ll m;
    cin>>n>>m;
    ll source = 1, sink = n;    // START, END
    for(ll i=0; i<=n; i++)
    {
        capacity[i] = vector<ll>(n+1,0);    // INITITALIZING 2D VECTOR FOR STORING RESIDUAL CAPACITY
                                            // RESIDUAL CAPACITY MEANS THE LEFT SPACE WHICH CAN NE FILLED IN AN EDGE
    }
    for(ll i=0; i<m; i++)
    {
        ll a,b,w;
        cin>>a>>b>>w;   // W IS MAXIMUM CAPACITY
        adj[a].pb(b);
        adj[b].pb(a);   // ALTHOUGH DIRECTED, WE MAKE BOTH SIDES
        capacity[a][b] += w;
    }
    cout<<max_flow(source,sink)<<endl;
    timetaken;
    return 0;
}