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
class edge
{
public:
    ll a,b,w;
};
ll par[10001];
ll _rank[10001];
edge arr[100001];
bool comp(edge a, edge b)
{
    if(a.w<b.w) return true;    // TRUE MEANS A IS PLACED BEFORE B
    else return false;
}
ll find(ll a)
{
    if(par[a]==-1) return a;
    else return par[a] = find(par[a]);
}
void merge(ll a, ll b)
{
    if(_rank[a]>_rank[b])
    {
        par[b] = a;
        _rank[a] += _rank[b];
    }
    else
    {
        par[a] = b;
        _rank[b] += _rank[a];
    }
}
int main()
{
    ll n,m;
    ll sum = 0;
    cin>>n>>m;
    for(ll i=0; i<=n; i++)
    {
        par[i]=-1;
    }
    for(ll i=0; i<m; i++)
    {
        cin>>arr[i].a>>arr[i].b>>arr[i].w;
        _rank[arr[i].a]=1;
        _rank[arr[i].b]=1;
    }
    sort(arr, arr+m, comp); // SORTING ACCORDING TO WEIGHTS
    for(ll i=0; i<m; i++)
    {
        ll a1 = find(arr[i].a); // FINDING PARENTS
        ll b1 = find(arr[i].b);
        if(a1==b1) continue;
        else
        {
            merge(a1,b1);
            sum+=arr[i].w;
        }
    }
    cout<<sum<<endl;
    return 0;
}