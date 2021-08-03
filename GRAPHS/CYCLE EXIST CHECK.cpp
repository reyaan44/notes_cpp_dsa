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
bool check = 0;
bool isCycleInGraph(ll a, ll parent)    // PARENT IS INCLUDED TO CHECK THE CYCLE
{
    visited[a]=1;
    for(auto itr = adj[a].begin(); itr!=adj[a].end(); itr++)
    {
        if(visited[*itr]==0)
        {
            if(isCycleInGraph(*itr,a)) return true;
        }
        else if(parent!=*itr) return true;  // IF NODE'S EDGES ARE CONNECTED TO THE PARENT, THEN NO PROBLEM, BUT IF IT IS CONNECTED TO A NODE THAT IS NOT PARENT AS WELL AS VISITED IN THE PAST, THEN IT INDICATES A CYCLE AND CURRENT EDGE IS A BACKEDGE
                                            // IN SHORT, THERE SHOULD NOT BE MORE THAN ONE WAY TO REACH A TO B IN A GRAPH, OTHERWISE IT IS A CYCLE
    }
    return false;
}
int main()
{
    cout<<"NUMBER OF EDGES : ";
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
    for(auto itr = visited.begin(); itr!=visited.end(); itr++)  // FOR DISCONNECTED GRAPH
    {
        if(itr->second==0)
        {
            if(isCycleInGraph(itr->first,-1))  // GIVING PARENT -1 AS IT HAS NO PARENT IN THE BEGINNING AS WE ARE CONSIDERRING THIS A ROOT
            {
                check=1;
                break;
            }
        }
    }
    if(check) cout<<"CYCLE EXISTS"<<endl;
    else cout<<"CYCLE DOES NOT EXIST"<<endl;
    return 0;
}