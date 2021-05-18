#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class reyaan
{
    ll a;
    void read(ll m); //private as default if not specified
public:
    void call(ll n);
    void lol(ll k);
    void print()
    {
        cout<<"A = "<<a<<endl;
    }
} a,b;   // declaring objects here
inline void reyaan :: read(ll m)
{
    a=m;
}
inline void reyaan :: call(ll n)
{
    read(n);
}
inline void reyaan :: lol(ll k)
{
    call(k);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    a.lol(1);
    a.print();
    b.lol(7);
    b.print();
    a.print();
    return 0;
}
