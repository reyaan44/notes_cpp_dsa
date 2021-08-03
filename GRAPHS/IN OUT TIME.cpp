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
map<ll,ll> intime;
map<ll,ll> outtime;
ll timer = 1;
void dfs(ll a)
{
    visited[a] = 1;
    intime[a] = timer++;
    for(auto itr = adj[a].begin(); itr!=adj[a].end(); itr++)
    {
        if(visited[*itr]==0)
        {
            dfs(*itr);
        }
    }
    outtime[a] = timer++;
}
int main()  // THIS WILL BE USED TO FIND IF A NODE A IS IN SUBTREE OF A NODE B IN O(1) TIME.
{
    cout<<"ENTER THE NUMBER OF EDGES : ";
    ll n; cin>>n;
    for(ll i=0; i<n; i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
        visited[a]=0;
        visited[b]=0;
    }
    for(auto itr = visited.begin(); itr!=visited.end(); itr++)
    {
        if(itr->second==0)
        {
            dfs(itr->first);   
        }
    }
    cout<<"IN TIME : ";
    for(auto itr : intime)
    {
        cout<<itr.second<<" ";
    }
    cout<<endl;
    cout<<"OUT TIME : ";
    for(auto itr : outtime)
    {
        cout<<itr.second<<" ";
    }
    cout<<endl;
    return 0;
}