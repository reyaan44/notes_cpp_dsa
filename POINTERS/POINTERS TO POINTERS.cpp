#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a=5;
    int *p;
    p=&a;
    int **x;
    x=&p;
    int ***q;
    q=&x;
    cout<<"A = "<<a<<*p<<**x<<***q<<endl;
    cout<<"A AD = "<<p<<*x<<**q<<endl;
    cout<<"P = "<<p<<*x<<endl;
    cout<<"P AD = "<<x<<*q<<endl;
    cout<<"X = "<<x<<*q<<endl;
    cout<<"X AD = "<<q<<&x<<endl;
    cout<<"Q = "<<&x<<q<<endl;
    cout<<"Q AD = "<<&q<<endl;

    return 0;
}
