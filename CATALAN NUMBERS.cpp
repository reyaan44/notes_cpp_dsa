#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define precision(a) cout<<fixed<<setprecision(a)
#define testcase ll t; cin>>t; while(t--)
#define endl "\n"
#define iendl "\n", cout.flush // FOR INTERACTIVE PROBLEMS
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,b) for(ll i=a; i<b; ++i)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;
const ll M = 1000000007;
ll catalan(ll n)        // FORMULA = 2N                // VERY HIGH COMPLEXITY, LLOK FOR SHORTER SOLUTION // SEQUENCE OF NATURAL NUMBERS THAT OCCUR IN VARIOUS COUNTING PROBLEMS OFTEN INVOLVING RECURSSIVELY DEFINED OBJECTS
                        //             C 
                        //              N
                        //               / 
                        //                N+1
{
    ll ans = 0;
    if(n==0 || n==1) return 1;
    for(ll i=0; i<=n-1; i++)
    {
        ans+=catalan(i)*catalan(n-i-1);
    }
    return ans;
}
int main()
{
    // quick;
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    for(ll i=0; i<10; i++)
    {
        cout<<"CATALAN NUMBER FOR "<<i<<" = "<<catalan(i)<<endl;
    }
    timetaken;
    return 0;
}