#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define endl "\n"
using namespace std;

// DJIKSTRA ALGO -> FINDING SINGLE SOURCE SHORTEST PATH IN A WEIGHTED GRAPH

vector<pair<ll,ll>> adj[100001];
vector<ll> dis(100001,LLONG_MAX);
int main()
{
    ll n,m;
    cin>>n>>m;
    for(ll i=0; i<m; i++)
    {
        ll a,b,w;
        cin>>a>>b>>w;
        adj[a].pb({b,w});   // UNDIRECTRED GRAPH
        adj[b].pb({a,w});   // NODE, DISTANCE
    }
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> q1; // FOR PAIRS, AND VECTOR AND GREATER INT FOR MIN HEAP
    q1.push({0,1});     // DISTANCE, NODE
    dis[1] = 0;     // CONSIDERING 1 AS SOURCE VERTEX   
    while(!q1.empty())
    {
        ll node = q1.top().second;
        ll distance = q1.top().first;
        q1.pop();
        for(ll i=0; i<adj[node].size(); i++)
        {
            if(distance + adj[node][i].second < dis[adj[node][i].first])    // CHECKING THE NEW DISTANCE EVERYTIME
            {
                dis[adj[node][i].first] = distance + adj[node][i].second;
                q1.push({dis[adj[node][i].first], adj[node][i].first});
            }
        }
    }
    for(ll i=1; i<=n; i++)
    {
        cout<<dis[i]<<" ";
    }
    cout<<endl;
    return 0;
}