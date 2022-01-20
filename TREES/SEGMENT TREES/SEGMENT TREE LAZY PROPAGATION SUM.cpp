#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define scanit(a,n) for(ll indexaa=0; indexaa<n; indexaa++) cin>>a[indexaa];
#define printit(a,n) for(ll indexaa=0; indexaa<n; indexaa++) cout<<a[indexaa]<<" "; cout<<endl;
#define pb push_back
#define mp make_pair
#define vll vector<ll>
#define precision(a) cout<<fixed<<setprecision(a)
#define testcase ll t; cin>>t; while(t--)
#define endl "\n"
#define iendl "\n", cout<<flush // FOR INTERACTIVE PROBLEMS
#define getlineinput(a) cin>>ws; getline(cin,a); // CIN>>WS TO CLEAR THE INPUT BUFFER AS GETLINE INCLUDES SPACES FROM JUST THE START
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,b) for(ll i=a; i<b; ++i)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
#define PI 3.141592653589793238462
using namespace std;
const ll M = 1000000007;
inline bool comp(ll x,ll y) { return x<y; } // INITIALLY IN DEFAULT INCREASING ORDER (SMALL TO BIG)
inline ll mod(ll x) {ll a1=(x%M); if(a1<0){a1+=M;} return a1;}
inline ll power(ll x, unsigned ll y, ll p = LLONG_MAX) {ll res=1; x=x%p; if(x==0) {return 0;} while(y>0){ if(y&1){res=(res*x)%p;} y=y>>1; x=(x*x)%p;} return res;} // CALCULATING POWER IN LOG(Y) TIME COMPLEXITY
inline ll inversePrimeModular(ll a, ll p) {return power(a,p-2,p);}
class segmentTree
{
public:
    segmentTree *left, *right;
    ll start, end;
    ll sum, lazySum;    // LAZYSUM ANOTHER LAZY TREE VARIABLE
    segmentTree(vector<ll> & vect, ll l, ll r)
    {
        start = l;
        end = r;
        if(l==r)
        {
            sum = vect[l];
            lazySum = 0;
        }
        else
        {
            ll mid = l + (r - l)/2;
            left = new segmentTree(vect, l ,mid);
            right = new segmentTree(vect, mid+1, r);
            sum = left->sum + right->sum;
            lazySum = 0;
        }
    }
    void updateRange(ll l, ll r, ll add) 
    {
        if(lazySum!=0)  // IF WE GET AT ANY NODE, WE WILL CHECK WHETHER ITS UPDATION IS REMAINING OR NOT,
                        // IF IT IS REMAINING, WE UPDATE ONLY THAT NODE, AND PASS UPDATION TO ITS CHILD
        {
            ll curr = lazySum;  // EXPLAINED BELOW
            lazySum = 0;
            sum += curr*(end-start+1);
            if(l!=r)
            {
                left->lazySum += curr;
                right->lazySum += curr;
            }
        }
        if(l>end || r<start) return;
        if(l<=start && r>=end)
        {
            sum += (end-start+1)*add;   // WE UPDATE THE CURRENT SUM OF THE NODE, END-START+1 GIVES THE TOTAL CHILDREN OF THIS NODE
                                        // WE UPDATE THIS NODE AND PASS THE LAZY SUM TO CHILDREN
            if(l!=r)
            {
                left->lazySum+=add;
                right->lazySum+=add;
            }
            return;
        }
        ll mid = (l+r)/2;
        left->updateRange(l,mid,add);
        right->updateRange(mid+1,r,add);
        sum = left->sum + right->sum;
    }
    ll getRange(ll l, ll r)
    {
        if(lazySum!=0)  // IF WE GET AT ANY NODE, WE WILL CHECK WHETHER ITS UPDATION IS REMAINING OR NOT,
                        // IF IT IS REMAINING, WE UPDATE ONLY THAT NODE, AND PASS UPDATION TO ITS CHILD
        {
            ll curr = lazySum;  // THIS VALUE NEEDS TO BE ADDED
            lazySum = 0;        // UPDATING THE LAZY TREE
            sum += curr*(end-start+1);  // UPDATING THE MAIN TREE
            if(l!=r)
            {
                left->lazySum += curr;  // GIVING THE UPDATES TO CHILDREN IN LAZY TREE
                right->lazySum += curr; // GIVING THE UPDATES TO CHILDREN IN LAZY TREE
            }
        }
        if(l<=start && r>=end) return sum;
        if(l>end || r<start) return 0;
        return (left->getRange(l,r) + right->getRange(l,r));
    }
};
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin>>n;
    vector<ll> vect(n);
    scanit(vect, n);
    segmentTree s1(vect, 0, n-1);
    ll q;
    cin>>q;
    while(q--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        if(a==1)
        {
            ll d;
            cin>>d;
            s1.updateRange(b,c,d);
        }
        else if(a==2)
        {
            cout<<s1.getRange(b,c)<<endl;
        }
    }
    timetaken;
    return 0;
}