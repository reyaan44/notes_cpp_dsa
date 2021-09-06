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
vector<ll> dis(100001,LLONG_MAX);
class edges
{
public:
    ll a,b,w;
};
vector<edges> vect(100001);
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n,m,source;
    cin>>n>>m>>source;
    for(ll i=0; i<m; i++)
    {
        ll a,b,w;
        cin>>a>>b>>w;
        vect[i].a = a;
        vect[i].b = b;
        vect[i].w = w;
    }
    // LEMMA IS THAT, AFTER KTH PHASE, BELLMAN-FORD ALGORITHM CORRECTLY FINDS ALL 
    // SHORTEST PATHS WHOSE NUMBER OF EDGES ARE LESS THAN OR EQUAL TO K
    // THATS WHY, WE ARE RUNNING A LOOP N-1 TIMES.
    dis[source]=0;
    for(ll i=0; i<n-1; i++)
    {
        for(ll j=0; j<m; j++)
        {
            if(dis[vect[j].a]!=LLONG_MAX)
            {
                dis[vect[j].b] = min(dis[vect[j].b], dis[vect[j].a]+vect[j].w);
            }
        }
    }
    for(ll i=1; i<=n; i++)
    {
        cout<<dis[i]<<" ";
    }
    cout<<endl;
    timetaken;
    return 0;
}