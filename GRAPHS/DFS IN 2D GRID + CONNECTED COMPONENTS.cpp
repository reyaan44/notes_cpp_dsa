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
ll arr[1001][1001];
ll visited[1001][1001];
ll dist[1001][1001];
ll n,m;
ll connected_components = 0;
bool isValid(ll x, ll y)
{
    if(x<1 || x>n || y<1 || y>m) return 0;
    if(visited[x][y]==1 || arr[x][y]==0) return 0;
    return 1;
}
ll dx[] = {1,0,0,-1};   // TO AVOID WRITING HEFTY CODE FOR EACH ADJACENT CELLS
ll dy[] = {0,1,-1,0};
void dfs(ll x, ll y)
{
    visited[x][y]=1;
    cout<<x<<" "<<y<<endl;
    for(ll i=0; i<4; i++)
    {
        if(isValid(x+dx[i],y+dy[i]))
        {
            dfs(x+dx[i],y+dy[i]);
        }
    }
}
bool isValidBFS(ll x, ll y)
{
    if(x<1 || x>n || y<1 || y>m) return 0;
    if(visited[x][y]==1) return 0;
    return 1;
}
void bfs(ll x, ll y)
{
    queue<pair<ll,ll>> q;
    q.push({x,y});
    visited[x][y]=1;
    dist[x][y]=0;
    while(!q.empty())
    {
        ll currX = q.front().first;
        ll currY = q.front().second;
        q.pop();
        for(ll i=0; i<4; i++)
        {
            if(isValidBFS(currX+dx[i],currY+dy[i]))
            {
                q.push({currX+dx[i],currY+dy[i]});
                visited[currX+dx[i]][currY+dy[i]]=1;
                dist[currX+dx[i]][currY+dy[i]]=dist[currX][currY]+1;
            }
        }
    }
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=m; j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}
void reset()
{
    connected_components=0;
    n=0;
    m=0;
    for(ll i=1; i<1001; i++)
    {
        for(ll j=1; j<1001; j++)
        {
            visited[i][j]=0;
            arr[i][j]=0;
            dist[i][j]=0;
        }
    }
}
int main()
{
    cout<<"ROWS : ";
    cin>>n;
    cout<<"COLUMNS : ";
    cin>>m;
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=m; j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"DFS : ";
    for(ll i=1; i<=n; i++)   // CELL EDGE AS EDGE FOR GRAPHS
    {
        for(ll j=1; j<=m; j++)
        {
            if(visited[i][j]==0 && arr[i][j]==1)    // TO GET THE NODES WITH 1 AS THEIR VALUE IN CELL
            {
                dfs(i,j);
                connected_components++;
            }
        }
    }   
    cout<<"CONNECTED COMPONENTS : "<<connected_components<<endl;
    reset();
    cout<<"ROWS : ";
    cin>>n;
    cout<<"COLUMNS : ";
    cin>>m;
    ll x,y;
    cout<<"SOURCE X : ";
    cin>>x;
    cout<<"SOURCE Y : ";
    cin>>y;
    bfs(x,y);
    cout<<endl;
    return 0;
}