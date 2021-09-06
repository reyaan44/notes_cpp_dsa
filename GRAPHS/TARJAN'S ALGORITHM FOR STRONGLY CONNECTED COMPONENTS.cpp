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
ll timer = 0, scc= 0;
stack<ll> st;
vector<ll> adj[10001];
ll in[10001], low[10001], visited[10001], Instack[10001];
void dfs(ll a)
{
    visited[a]=1;
    in[a] = low[a] = timer++;
    Instack[a]=1;           //  KEEPS A TRACK WHETHER ELEMENT IS PRESENT IN STACK OR NOT
    st.push(a);

    for(ll i=0; i<adj[a].size(); i++)
    {
        /*
            1. A NODE IS NOT VISITED AND NOT IN STACK == WE JUST ADD IT TO STACK AND RUN DFS
            2. A NODE IS VISITED AND NOT IN STACK == THE NODE IS DECLARED AS A SEPARATE STRONGLY CONNECTED COMPONENT AND IT IF WE GO TO THAT NODE, THERE IS NO WAY WE CAN REACH BACK HERE AGAIN
            3. A NODE IS VISITED AND IN STACK == A BACKEDGE, WE WILL UPDATE OUT LOW TO MINIMUM OF ITS IN TIME AND OUR LOW TIME
        */
        if(visited[adj[a][i]]==1 && Instack[adj[a][i]]==1)
        {
            low[a] = min(low[a], in[adj[a][i]]);
        }
        else if(visited[adj[a][i]]==0)
        {
            dfs(adj[a][i]);
            if(Instack[adj[a][i]]==1)   // TO CHECK THE NODES WHICH CAN STILL BE REACHED THE OTHER WAY AROUND DURING BACKTRACKING
            {
                low[a] = min(low[a], low[adj[a][i]]);
            }
        }
    }
    if(in[a]==low[a])   // THIS MEANS THAT WE HAVE FOUND A NODE FROM WHICH WE CAN MOVE TO THE ELEMENTS ABOVE IT IN STACK AND THEY CAN COME BACK TO THIS NODE, SO HERE, A STRONGLY CONNECTED COMPONENT IS FOUND, AS WE CANNOT MOVE BACK FROM THIS NODE IN ANY WAY
                        // ALSO THIS NODE ISNT ATTACHED TO ANY BACKEDGE THROUGH WHICH WE CAN TRAVERSE TO ANOTHER NODE WHICH IS ITS ANCESTOR 
    {
        scc++;
        while(1)
        {
            ll a1 = st.top();
            st.pop();
            Instack[a1]=0;
            cout<<a1<<" ";
            if(a1==a)
            {
                break;
            }
        }
        cout<<endl;
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
    }
    for(ll i=1; i<=n; i++)
    {
        if(visited[i]==0)
        {
            dfs(i);
        }
    }
    cout<<"SCC = "<<scc<<endl;
    return 0;
}