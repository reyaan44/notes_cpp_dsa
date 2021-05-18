#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define precision(a) cout<<fixed<<setprecision(a)
#define testcase ll t; cin>>t; while(t--)
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,b) for(ll i=a; i<b; ++i)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;
class rj; // FORWARD DECLARATION
class reyaan
{
    ll a,b;
    void func1()
    {
        cout<<"REYAAN FUNCTION 2 ACCESSED"<<endl; // PRIVATE MEMBER FUNCTION
    }
public:
    ll c;
    void func()
    {
        cout<<"REYAAN FUNCTION 1 ACCESSED"<<endl;
    }
    friend class rj;  // CLASS RJ HAS ACCESS TO ALL PRIVATE DATA MEMBER AS WELL AS PRIVATE MEMBER FUNCTIONS
};
class rj
{
    ll e,f;
    reyaan j;  // DECLARING REYAAN CLASS IN RJ, NOW CAN ACCESS ALL PRIVATE THINGS OF CLASS REYAAN
public:
    void func2(reyaan obj1) // HERE, PASSING ARGUMENT IS NOT COMPULSARY
    {
        j.a=2; // ACCESSING PRIVATE DATA MEMBERS OF CLASS REYAAN
        cout<<j.a<<endl;
        j.func1(); // ACCESSING PRIVATE MEMBER FUNCTION OF CLASS REYAAN
        cout<<"RJ ACCESSED"<<endl;
        obj1.func(); 
        obj1.a=4;
        cout<<obj1.a<<endl;
    }
};
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    rj obj1;  
    reyaan q; // HERE, WE CANT PRIVATELY ACCESS REYAAN CLASS, IT NEEDS TO BE INSIDE ANOTHER CLASS WHICH IS A FRIEND
    obj1.func2(q);
    timetaken;
    return 0;
}