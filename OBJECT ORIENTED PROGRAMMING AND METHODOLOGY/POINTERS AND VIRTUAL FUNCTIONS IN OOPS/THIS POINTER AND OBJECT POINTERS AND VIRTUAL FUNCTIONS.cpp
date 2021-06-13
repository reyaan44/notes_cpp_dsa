#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define precision(a) cout<<fixed<<setprecision(a)
#define testcase ll t; cin>>t; while(t--)
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,b) for(ll i=a; i<b; ++i)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;

// LEARN OPERATOR OVERLOADING FROM BOOK, NOT MENTIONED IN NOTES 
// https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/ LEARN ABSTRACT CLASSES AND PURE VIRTUAL FUNCTIONS HERE

class ABC
{
public:
    ll a;
    void display()
    {
        cout<<"A = "<<this->a<<endl;    // USE OF THIS POINTER WHEN OBJECT IS IMPLICITLY PASSED
        cout<<"Base class Display Function is Accessed"<<endl;
    }
    ABC greater(ABC);
};
ABC ABC :: greater(ABC b)
{
    if(b.a>a) return b;
    return *this;               // REAL USE OF THIS POINTER IS IN OPERATOR OVERLOADING AND CALLING FUNCTIONS LIKE ONE OF THE ARGUMENT IS IMPLICIT IN THE FUNCTION, TO RETURN OR ACCESS THAT ARGUMENT, THIS POINTER CAN BE USED
} 

class Derived : public ABC
{
public:
    ll b;
    void display()
    {
        cout<<"B = "<<b<<endl;
        cout<<"Derived class Display Function is Accessed"<<endl;
    }
};



class A
{
public:
    ll a;
    void show()
    {
        cout<<"A1 IS CALLED"<<endl;
    }
    virtual void show1()
    {
        cout<<"A2 IS CALLED"<<endl;
    }
};
class B : public A
{
public:
    ll b;
    void show()
    {
        cout<<"B1 IS CALLED"<<endl;
    }
    void show1()
    {
        cout<<"B2 IS CALLED"<<endl;
    }
};

int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ABC a1;
    a1.a = 100;
    ABC a2;
    a2.a = 200;
    ABC obj = a1.greater(a2);
    cout<<obj.a<<endl<<endl<<endl;



    ABC *ptr;
    ABC obj1;

    Derived obj2;
    Derived *p;

    ptr=&obj1;  
    ptr->a = 8;
    ptr->display();
    (*ptr).display();   // ANOTHER WAY TO CALL MEMBERS WITH POINTERS
    ptr = &obj2;        // POINTER OBJECT OF BASE CLASS CAN POINT TO OBJECT OF DERIVED CLASS, BUT NOT VICE VERSA
    ptr->a = 9;
    // ptr->b = 10;         // NEW FORMED MEMBERS OF DERIVED CLASS CANNOT BE ACCESSED FROM POINTER OF BASE CLASS EVEN WHEN IT IS POINTED AT OBJECT OF DERIVED CLASS
    ptr->display();         // POINTS TO OBJECT OF DERIVED CLASS, BUT AS IT IS INITIALLY AN OBJECT OF BASE CLASS, IT STILL POINTS TO THE DISPLAY FUNCTION OF BASE CLASS AND IT IS NOT OVERWRITTEN BY DERIVED CLASS, AS POINTER OBJECT OF BASE CLASS CANNOT ACCESS MEMBERS OF DERIVED CLASS

    p = &obj2;
    p->b = 100;
    p->display();       // OBJECT POINTER OF DERIVED CLASS CALLS DISPLAY FUNCTION OF DERIVED CLASS ONLY
    p->a = 45;          // POINTER OBJECT OF DERIVED CLASS CAN ACCESS THE MEMBERS OF BASE CLASS
    // p = &obj1;       // POINTER OBJECT OF DERIVED CLASS CANNOT POINT TO OBJECT OF BASE CLASS
    p->display();
    cout<<obj2.a<<endl;

    ((Derived *)ptr) -> b = 199;    // TYPE CASTING, HERE, WE CAN MAKE OBJECT POINTER OF BASE CLASS TO ACCESS MEMBERS OF DERIVED CLASS
    ((Derived *)ptr) -> display();  // TYPE CASTING, HERE, WE CAN CALL DERIVED CLASS DISPLAY FUNCTION DUE TO TYPE CASTING FROM THE OBJECT POINTER OF BASE CLASS
    cout<<endl<<endl;



    A *bptr;
    A r1;
    B *dptr;
    B r2;
    bptr=&r1;
    bptr->show();
    bptr->show1();
    bptr=&r2;
    bptr->show();
    bptr->show1();      //  AS WE MADE SHOW1 VIRTUAL IN BASE CLASS, OBJECT POINTER OD BASE CLASS POINTING AS DERIVED CLASS CALLS A FUCNTION OF DERIVED CLASS ONLY
    cout<<endl;
    r1.show();
    r1.show1();
    r2.show();
    r2.show1();
    cout<<endl;
    ((B *)bptr) -> show();
    dptr=&r2;
    dptr->show();
    dptr->show1();
    timetaken;
    return 0;
}