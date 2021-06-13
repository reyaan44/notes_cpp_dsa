#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define precision(a) cout<<fixed<<setprecision(a)
#define testcase ll t; cin>>t; while(t--)
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,b) for(ll i=a; i<b; ++i)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;
const ll M = 1000000007;
ll mod(ll x)
{
    return (x%M + M)%M;
}
class reyaan
{
    ll c,b;
public:
    ll d;
    void set(ll,ll);
    friend ll sum(reyaan);
}a;                                // DECLARING OBJECT A
ll sum(reyaan a)
{
    return a.c+a.b;
}
void reyaan::set(ll x,ll y)
{
    c=x;                         // POINTER CAN BE DECLARED TO ONLY "PUBLIC" MEMBER FUNCTIONS AND DATA MEMBERS
    b=y;
}
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll reyaan::*pointer = &reyaan::d;  // DECLARATION OF POINTER (*POINTER) POINTING TO A PUBLIC DATA MEMBER D
    a.d=10;   
    cout<<a.d<<endl;
    cout<<a.*pointer<<endl;       // ACCESSING THE DATA MEMBER WITH HELP OF POINTER
    reyaan *p = &a;               // DECLARING THE POINTER (*P) POINTING TO AN OBJECT OF CLASS
    cout<<(p->*pointer)<<endl;    // ACCESSING THE DATA MEMBER WITH POINTER TO A DATA MEMBER AND POINTER TO OBJECT OF CLASS
    void (reyaan :: *ptr)(ll,ll) = &reyaan :: set; // DECLARING POINTER (*PTR) TO MEMBER FUNCTION SET 
    (a.*ptr)(10,20);              // ACCESSING THE MEMBER FUNCTION WITH POINTER TO MEMBER FUNCTION
                        // ( ) PARENTHESIS IS COMPULSARY HERE
    cout<<"SUM = "<<sum(a)<<endl; 
    (p->*ptr)(30,40);             // HERE, P IS A POINTER TO AN OBJECT, AND HERE WE ARE ACCESSING FUNCTION 
                                  // WITH POINTER TO OBJECT AND POINTER TO FUNCTION
    cout<<"SUM = "<<sum(a)<<endl;
    timetaken;
    return 0;
}