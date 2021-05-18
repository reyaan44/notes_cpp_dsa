#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class rj;
class reyaan
{
    ll a;
    public:
        void set(ll aa)
        {
            a=aa;
        }
        void display()
        {
            cout<<"reyaan = "<<a<<endl;
        }
        friend void swap(reyaan & obj1, rj & obj2);
};
class rj
{
    ll a;
public:
    void set(ll aa)
    {
        a=aa;
    }
    void display()
    {
        cout<<"rj = "<<a<<endl;
    }
    friend void swap(reyaan & obj1, rj & obj2);
};
void swap(reyaan & obj1, rj & obj2) // REFERENCE OBJECTS 
{
    swap(obj1.a,obj2.a);
    obj1.display();                // FRIEND FUNCTIONS GAINS THE POWER OF ACCESSING ALL THE PRIVATE DATA MEMBERS
    obj2.display();                // AND MEMBER FUNCTIONS AND TO MANIPULATE THEM WITH REFERENCE VARIABLE
}                                  // OR JUST WITH OBJECTS COPYING WITHOUT BEING ABLE TO CHANGE ITS VALUE AT ORIGINAL PLACE
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    reyaan a;
    rj b;
    a.set(100);
    b.set(200);
    a.display();
    b.display();
    swap(a,b);
    return 0;
}