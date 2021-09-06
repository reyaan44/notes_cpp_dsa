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
const ll M = 1000000007;
class Union
{
public:
    vector<ll> _rank,par;
    void initialize(ll n)
    {
        _rank.assign(n+1,1);
        par.assign(n+1,0);
        for(ll i=1; i<=n; i++)
        {
            par[i]=i;
        }
    }
    ll find(ll a)
    {
        if(par[a]==a) return a;
        else return par[a] = find(par[a]);
    }
    void merge(ll a, ll b)
    {
        a = find(a);
        b = find(b);
        if(a==b)
        {
            return;
        }
        if(_rank[a]>_rank[b])
        {
            par[b] = a;
            _rank[a]+=_rank[b];
        }
        else
        {
            par[a] = b;
            _rank[b]+=_rank[a];
        }
    }
};
inline bool comp(ll x,ll y)
{
    return x<y; // INITIALLY IN DEFAULT INCREASING ORDER (SMALL TO BIG)
}
inline ll mod(ll x)
{
    return (x%M + M)%M;
}
ll par[100001], _rank[100001];
ll find(ll a)
{
    if(par[a] == -1)
    return a;
 
    else
    return find(par[a]);
}
/*
    IN PATH COMPRESSION
    ll find(ll a)
    {
        if(par[a]==a) return a;
        else par[a] = find(par[a]);
    }
*/
void merge(ll a , ll b)
{
    a = find(a);
    b = find(b);
 
    if(a == b)
    return ;
 
    if(_rank[a] > _rank[b])
    {
        _rank[a] += _rank[b];
        par[b] = a;
    }
    else
    {
        _rank[b] += _rank[a];
        par[a] = b;
    }
}
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll maxi = 0;
    forl(i,0,n)
    {
        if(s[i]=='1')
        {
            _rank[i] = 1;
            par[i] = -1;
            if((i-1)>=0 && s[i-1]=='1')
            {
                merge(i,i-1);
            }
            ll p = find(i);
            if(_rank[p]>maxi) maxi = _rank[p];
        }
    }
    while(k--)
    {
        ll x;
        cin>>x;
        if(x==1)
        {
            cout<<maxi<<endl;
        }
        else
        {
            cin>>x;
            x--;
            if(s[x]=='1') continue;
            else
            {
                s[x]='1';
                par[x]=-1;
                _rank[x]=1;
                if((x-1)>=0 && s[x-1]=='1') merge(x,x-1);
                if((x+1)<n && s[x+1]=='1') merge(x,x+1);
                ll p = find(x);
                if(_rank[p]>maxi) maxi = _rank[p];
            }
        }
    }   
    timetaken;
    return 0;
}