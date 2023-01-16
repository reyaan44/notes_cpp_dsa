#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;
class max_flow
{
    public:
        vector<vector<ll>> adj = vector<vector<ll>>(501);
        vector<vector<ll>> capacity = vector<vector<ll>>(501);
        vector<ll> visited = vector<ll>(501);
        ll n, m;
        max_flow(ll n, ll m)
        {
            this->n = n;
            this->m = m;
            for(ll i=0; i<=n; i++)
            {
                capacity[i] = vector<ll>(n+1,0);    // INITITALIZING 2D VECTOR FOR STORING RESIDUAL CAPACITY
                                                    // RESIDUAL CAPACITY MEANS THE LEFT SPACE WHICH CAN BE FILLED IN AN EDGE
            }
            for(ll i=0; i<m; i++)
            {
                ll a,b,w;
                cin>>a>>b>>w;   // W IS MAXIMUM CAPACITY
                adj[a].pb(b);
                adj[b].pb(a);   // ALTHOUGH DIRECTED, WE MAKE BOTH SIDES
                capacity[a][b] += w;
                capacity[b][a] += w; // Depends on problem, if undirected
            }
        }
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
        ll max_flow_start(ll start, ll end) // START, SINK
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
        void dfs(ll a)
        {
            visited[a] = 1;
            for(auto child: adj[a])
            {
                if(visited[child] || !capacity[a][child]) 
                    continue;
                dfs(child);
            }
        }
        vector<vector<ll>> min_cut()
        {
            dfs(1);
            vector<vector<ll>> ans;
            for(ll i=1; i<=n; i++)
            {
                if(visited[i])
                {
                    for(auto child: adj[i])
                    {
                        if(visited[child]) continue;
                        ans.pb({i,child});
                    }
                }
            }
            return ans;
        }
};
int main()
{
    ll n,m;
    cin>>n>>m;
    max_flow obj1 = max_flow(n,m);
    cout<<obj1.max_flow_start(1,n)<<endl;   // for just the max-flow

    // for min cut
    // vector<vector<ll>> ans = obj1.min_cut();
    // cout<<ans.size()<<endl;
    // for(ll i=0; i<ans.size(); i++)
    // {
    //     cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    // }

    /*
        Here, the capacity is the total capacity left in the flow from a to b.
        Also known as the residual graph.
    */

    /*
        Min Cut - One possible minimum cut is the following: 
        the set of all the vertices that can be reached from  in the residual graph 
        (using edges with positive residual capacity), 
        and the set of all the other vertices. 
        This partition can be easily found using DFS starting at s.
    */

    return 0;
}
