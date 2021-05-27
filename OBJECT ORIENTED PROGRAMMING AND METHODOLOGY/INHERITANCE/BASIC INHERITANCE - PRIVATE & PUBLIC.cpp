#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class ABC
{
    ll a;
public:
    ll b;
    void set_ab();
    ll get_a();
    void show_a();
};
class XYZ : public ABC          // ALL PUBLIC MEMBERS OF CLASS ABC(BASE CLASS) ARE COPIED PUBLICALLY TO XYZ(DERIVED CLASS), THEY ARE CPOIED UNDER PUBLIC OF XYZ
{                               //IF IT WOULD BE PRIVATE ABC, ALL PUBLIC MEMBERS OF ABC(BASE CLASS) ARE CAPOIED PRIVATELY TO XYZ(DERIVED CLASS) MEANS THEY ARE STORES IN PRIVATE SECRION OF XYZ
    ll c;                       // IF WE USE THE SAME NAME IN DERIVED CLASS AS A NAME OF DATA MEMBER OR MEMBER FUNCTION IN BASE CLASS, THAN THE NAME OF DERIVES CLASS WILL BE GIVEN UPPER HAND AGAINST BASE CLASS
public:
    void mul();
    void display();             
};
void ABC :: set_ab()
{
    a=5;
    b=10;
}
ll ABC :: get_a()
{
    return a;
}
void ABC :: show_a()
{
    cout<<"A = "<<a<<endl;
    cout<<"B = "<<b<<endl;
}
void XYZ :: mul()
{
    c=b*get_a();
}
void XYZ :: display()
{
    cout<<"A = "<<get_a()<<endl;
    cout<<"B = "<<b<<endl;
    cout<<"C = "<<c<<endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    XYZ obj;
    obj.set_ab();
    obj.show_a();
    obj.mul();
    obj.display();
    obj.b=8;
    obj.mul();
    obj.display();
    return 0;
}

