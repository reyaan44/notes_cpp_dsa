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
vector<ll> prime;
vector<ll> adj[100001];
ll dist[100001];
ll visited[100001];
bool isValid(ll a, ll b)    // TO CHECK THE DIGIT DIFFERENCE ACCORDING TO QUESTION
{
    ll cnt = 0;
    while(a>0 && b>0)
    {
        if((a%10)!=(b%10)) cnt++;
        a/=10;
        b/=10;
    }
    if(cnt==1) return true;
    else return false;
}
bool isPrime(ll a)
{
    if(a==0 || a==1) return false;
    for(ll i=2; i*i<=a; i++)
        if(a%i==0) return false;
    return true;
}
void buildGraph()
{
    for(ll i=1000; i<=9999; i++) 
        if(isPrime(i)) prime.push_back(i);
    for(ll i=0; i<prime.size()-1; i++)  // TO CHECK TO MAKE THE EDGE BETWEEN TWO PRIME NUMBERS
    {
        for(ll j=i+1; j<prime.size(); j++)
        {
            if(isValid(prime[i],prime[j]))
            {
                adj[prime[i]].pb(prime[j]);
                adj[prime[j]].pb(prime[i]);
            }
        }
    }
}
void bfs(ll a)  // SSSP IN BFS.
{
    dist[a]=0;  // IMP
    queue<ll> q;
    q.push(a);
    visited[a]=1;
    while(!q.empty())
    {
        a = q.front();
        q.pop();
        for(ll i=0; i<adj[a].size(); i++)
        {
            if(visited[adj[a][i]]==0)
            {
                q.push(adj[a][i]);
                visited[adj[a][i]]=1;
                dist[adj[a][i]]=dist[a]+1;  // IMP
            }
        }
    }
}
int main()  // QUESTION : https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqa2xwRDRhLU1NT0dGQlBib0lrU01IenpBR3BUUXxBQ3Jtc0trQmVnbzdvTkl5WUNnVmlsbnlkbWpEdnRVWGpGMm5NS3NQcTlZeDM5LXZ4QXZvQUFqNjJ1XzFpV2NIN1hkYnNiYmRqTjM0b0VVLUZSLUNBbi1TNk5ETGxZV01RaXVaMllNc1QzUDdYb0FGWTE3N0N2dw&q=https%3A%2F%2Fwww.spoj.com%2Fproblems%2FPPATH%2F
            // NAME - PRIME PATH
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    buildGraph();   // BUILD AND CONNECT THE GRAPHS OF PRIME NUMBERS WITH 1 DIGIT DIFFERENCE TO EACH OTHER
    testcase
    {
        ll a,b;
        cin>>a>>b;
        for(ll i=1000; i<=9999; i++)
        {
            dist[i]=-1; // TO CHECK IMPOSSIBLE CASE, BUT WE MADE FIRST ELEMENT AS DIS[A]=0.
            visited[i]=0;   
        }
        bfs(a); // TO MAKE THE SHORTEST PATH FROM THE ROOT TO ALL THE REACHABLE ROOTS AND UPDATING THEIR DISTANCE OF APPROACH FROM ROOT 
        if(dist[b]==-1) cout<<"Impossible"<<endl;
        else cout<<dist[b]<<endl;
    }
    timetaken;
    return 0;
}