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
vector<ll> ans;
ll inDegree[1000001];
void kahn(ll n)
{
    /*
        WE WILL FIRST FIND ALL THE NODES WITH INDEGREE ZERO AS THEY WILL COME AT FIRST
    */
    queue<ll> q;
    for(ll i=1; i<=n; i++)  
    {
        if(inDegree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        ll a = q.front();
        q.pop();
        ans.push_back(a);
        for(ll i=0; i<adj[a].size(); i++)
        {
            inDegree[adj[a][i]]--;      // REMOVING THE EDGES OF THE NODE WHICH WE INSERTED IN QUEUE, SO BY DOING THAT
                                        // THE INDEGREE OF ITS CHILD NODE WILL GET REDUCED BY 1, AS THERE IS 1 EDGE
            if(inDegree[adj[a][i]]==0)  // IF IN THIS NODE, THERE IS NO NODE LEFT WHICH HAS EDGE TOWARDS THIS NODE, IT CAN BE ADDED TO QUEUE
            {
                q.push(adj[a][i]);
            }
        }
    }
    /*
        IF VALID TOPOLOGICAL SORTING DOES NOT EXISTS (IT HAS A CYCLE), THAN ANS.SIZE()!=N
        SO TO CHECK IF THE TOPOLOGICAL SORTING EXISTS OR NOT, WE WILL HAVE TO INCLUDE THIS DETAIL AS WELL
        VALID TOPOLOGICAL SORTING ONLY EXISTS IN DAG(DIRECTED ACYCLIC GRAPH) AND WE CAN CHECK IT BY 
        ANS.SIZE()==N AT THE END. IF THEY ARE EQUAL, ALL ELEMENTS ARE TRAVERSED AND IT IS A VALID 
        TOPOLOGICAL SORTING AS WELL AS A DAG.
    */
    for(ll i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    ll n,e;
    cin>>n>>e;
    for(ll i=0; i<e; i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);   // BECOZ DIRECTED GRAPH NEEDED FOR TOPOLOGICAL SORTING
        inDegree[b]++;  // IN DEGREE IS THE NUMBER OF EDGES DIRECTED TOWARDS THIS NODE
    }
    kahn(n);
    return 0;
}