#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Grandparent
{
public:
    ll height = 20;
    ll weight = 60;
};
class Parent1 :  virtual public Grandparent           // DEFINED AS VIRTUAL BASE CLASS
{    
public:     
    ll h1 = 19;
    ll w1 = 59;
};
class Parent2 : public virtual Grandparent            // DEFINED AS VIRTUAL BASE CLASS
{
public:
    ll h2 = 21;
    ll w2 = 61;
};
class Child : public Parent1, public Parent2        
                    // The class GRANDPARENT has just 2 data members height and weight which are public. This class is virtually inherited in class PARENT1 and class PARENT2. Now class PARENT1 and class PARENT2 becomes virtual base class and no duplication of data member height and weight are done.
                    // otherwise both PARENT1 and PARENT2 will create duplicates of data members and when inherited to CHILD, ambiguity will arise, but if we use virtual class, no duplicates are formed. A single copy of its data members is shared by all the base classes that use virtual base.
{
public:
    ll yo;
};
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    Child a;
    cout<<a.h1<<endl<<a.w1<<endl<<a.h2<<endl<<a.w2<<endl;
    cout<<a.height<<endl<<a.weight<<endl<<endl;
    a.height=2;
    cout<<a.height<<endl<<endl;
    Grandparent b;
    cout<<b.height<<endl<<endl;
    Parent1 c;
    cout<<c.height<<endl<<endl;
    Parent2 d;
    cout<<d.height<<endl<<endl;
    c.height = 6;
    cout<<c.height<<endl;
    cout<<d.height<<endl<<endl;
    b.height = 9;
    cout<<b.height<<endl;
    cout<<c.height<<endl;
    cout<<d.height<<endl<<endl;
    return 0;
}


