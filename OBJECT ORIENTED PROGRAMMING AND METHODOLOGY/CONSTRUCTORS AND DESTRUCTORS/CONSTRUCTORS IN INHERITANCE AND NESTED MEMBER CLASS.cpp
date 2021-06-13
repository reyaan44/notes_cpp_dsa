#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define precision(a) cout<<fixed<<setprecision(a)
#define testcase ll t; cin>>t; while(t--)
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,b) for(ll i=a; i<b; ++i)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;
/* ABSTRACT CLASS = THE CLASS WHICH IS ONLY USED AS BASE CLASS AND NOT TO CREATE ANY OBJECTS */
/* IF BASE CLASS DOESNT HAVE PARAMETERIZED CONSTRUCTOR, THEN IT IS NOT MANDATORY FOR DERIVED CLASS TO HAVE A CONSTRUCTOR, BUT IF BASE CLASS HAS A PARAMETERIZED CONSTRUCTOR, THEN IT IS COMPULSARY FOR ALL ITS DERIVED CLASSES TO HAVE CONSTRUCTOR */
class alpha
{
    ll a,b;
public:
    alpha(ll i,ll j) : a(i), b(j) {cout<<"ALPHA CALLED"<<endl;} // CONSTRUCTOR  // AFTER : , THE AREA IS CALLED AS INITIALIZATION SECTION, WE CAN INITIALIZE THE VALUES OF THE DATA MEMBERS DIRECTLY WITH () WITHOUT WRITING IN CURLY BRACES 
    void display()
    {
        cout<<"A = "<<a<<endl<<"B = "<<b<<endl;
    }
};
class beta
{
    ll c,d;
public:
    beta(ll k)      // BOTH INITIALIZATION SECTION AND THIS WAY WORKS FOR CONSTRUCTORS
    {
        c=k;
        d=k*2;
        cout<<"BETA CALLED"<<endl;
    }
    void display()
    {
        cout<<"C = "<<c<<endl<<"D = "<<d<<endl;
    }
};
class gamma : public alpha, public beta 
/* BASE CLASSES ARE CALLED FIRST IN THE OEDER OF THE INITIALIZATION IN DERIVED CLASSES, LIKE HERE, ALPHA WILL BE CALLED, THEN BETA.. IN CASE OF MULTILEVEL DERIVED CLASSES, THE CONSTRUCTORS ARE CALLED IN ORDER OF DERIVATION, FOR EG. A->B->C, THEN WHILE C IS A DERIVED CLASS, FIRST A WILL BE CALLED, THEN B.. ALSO IF THERE IS ANY VIRTUAL BASE CLASS IN THE BASE CLASSES, IT WILL BE CALLED FIRST */
{
    ll e,g;
public:
    gamma(ll a, ll b, ll c, ll d, ll f) : beta(c), alpha(a,b), e(d)     // THIS IS HOW CONSTRUCTORS ARE CALLED, AND ALSO E IS INITIALIZED A VALUE, THE ORDER OF CALLING CONSTRUCTORS IS INDEPENDENT OF THE ORDER IN INITIALIZING SECTION
    {
        g=f;
        cout<<"GAMMA CALLED"<<endl;
    }
    void display()
    {
        cout<<"E = "<<e<<endl<<"G = "<<g<<endl;
    }
};
class gamma1 : public beta, public alpha        // ANOTHER EXAMPLE JUST FOR REFERENCE TO SHOW ORDER OF CONSTRUCTORS CALLED
{
    ll e,g;
public:
    gamma1(ll a, ll b, ll c, ll d, ll f) : beta(c), alpha(a,b), g(f)  
    {
        e=d;
        cout<<"GAMMA CALLED"<<endl;
    }
    void display()
    {
        cout<<"E = "<<e<<endl<<"G = "<<g<<endl;
    }
};

/* NESTED MEMBER CLASS */

class Enclosed
{
    ll a,b;
public:
    Enclosed(ll i,ll j) : b(j)
    {
        a=i;
        cout<<"Enclosed Initialized"<<endl;
    }
    void display()
    {
        cout<<"A = "<<a<<endl<<"B = "<<b<<endl;
    }
};
class Enclosed1
{
    ll a,b;
public:
    Enclosed1(ll i,ll j) : b(j)
    {
        a=i;
        cout<<"Enclosed1 Initialized"<<endl;
    }
    void display()
    {
        cout<<"A = "<<a<<endl<<"B = "<<b<<endl;
    }
};
class Nested
{
public:
    ll a;
    Enclosed objj;           // INITIALIZING OBJECTS OF THE ENCLOSED CLASSES
    Enclosed1 objj1;
public:
    Nested(ll i, ll j, ll k, ll l, ll m) : objj(i,j), objj1(k,l), a(m)        // MANDATORY IF ENCLOSED CLASS HAVE CONSTRUCTOR // HERE, ENCLOSED(I,J) CANT BE WRITTEN BECAUSE IT IS NOT INHERITED
    {
        cout<<"Nested Initialized"<<endl;
    }
    void display()
    {
        cout<<"A = "<<a<<endl;
        objj.display();      // CALL THEIR OWN FUNCTION
        objj1.display();     // CALL THEIR OWN FUNCTION
    }
};


int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    gamma obj(1,2,3,4,5);
    gamma1 obj1(1,2,3,4,5);
    obj.alpha::display();       // TO RESOLVE AMBIGUITY
    obj.beta::display();
    obj.display();      // DERIVED CLASS IS ALWAYS GIVEN THE EDGE OVER BASE CLASSES IN AMBIGUITY

    Nested obj2(1,2,3,4,5); 
    obj2.objj.display();    // NOTE, THIS IS POSSIBLE BACAUSE OBJJ1 AND DISPLAY BOTH ARE PUBLIC
    // obj2.objj1.a=78; // NOTE, THIS IS NOT POSSIBLE BECAUSE A IS PRIVATE
    obj2.display(); // I CANNOT DO obj2.Enclosed::display(); BECAUSE I CANNOT USE NESTED OBJECTS DIRECTLY, THEIR SCOPE IS THE NESTED CLASS ONLY FOR CALLING, AND THEY CAN CALL THEIR RESPECTIVE ENCLOSED FUNCTIONS FROM THERE ITSELF
    timetaken;
    return 0;
}