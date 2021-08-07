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
vector<ll> adj[10001];
ll in[10001];
vector<ll> ans;
bool kahn(ll n)
{
    priority_queue<ll,vector<ll>,greater<ll>> q;
    for(ll i=1; i<=n; i++)
    {
        if(in[i]==0) q.push(i);
    }
    while(!q.empty())
    {
        ll a = q.top();
        q.pop();
        ans.pb(a);
        for(ll i=0; i<adj[a].size(); i++)
        {   
            in[adj[a][i]]--;
            if(in[adj[a][i]]==0) q.push(adj[a][i]);
        }
    }
    return n==ans.size();
}
int main()
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
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        in[y]++;
    }
    if(kahn(n))
    {
        for(ll i=0; i<ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    else cout<<"Sandro fails."<<endl;
    timetaken;
    return 0;
}