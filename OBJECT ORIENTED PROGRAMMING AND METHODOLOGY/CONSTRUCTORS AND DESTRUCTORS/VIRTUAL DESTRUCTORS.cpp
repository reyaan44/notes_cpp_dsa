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
class A
{
public:
    A()
    {
        cout<<"BASE CONSTRUCTOR"<<endl;
    }
    virtual ~A()            // WHEN WE DELETE A POINTER OBJECT OF BASE CLASS POINTING AT DERIVED CLASS, AND DELETE IT, THEN DERIVED CLASS DESTRUCTOR IS NOT CALLED, TO CALL IT, WE MAKE BASE CLASS CONSTRUCTOR VIRTUAL SO THAT DERIVED CLASS DESTRUCTOR IS ALSO CALLED
    {
        cout<<"BASE DESTRUCTOR"<<endl;
    }
};
class B : public A
{
public:
    B()
    {
        cout<<"DERIVED CONSTRUCTOR"<<endl;
    }
    ~B()
    {
        cout<<"DERIVED DESTRUCTOR"<<endl;
    }
};
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    B *obj;
    A *obj1 = obj;
    delete obj1;
    timetaken;
    return 0;
}