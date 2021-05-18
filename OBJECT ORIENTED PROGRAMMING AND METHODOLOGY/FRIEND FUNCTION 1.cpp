#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class rj;  // FORWARD DECLARATION
class reyaan
{
    ll a,b;
public:
    friend ll max(reyaan z, rj y);
    void set();
};
class rj
{
    ll d,f;
public:
    void set();
    friend ll max(reyaan z, rj y);
};
void reyaan :: set()
{
    a=3;
}
void rj :: set()
{
    d=51;
}
ll max(reyaan z, rj y)
{
    if(z.a>y.d) return z.a;
    else return y.d;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    reyaan q;
    rj t;
    q.set();
    t.set();
    cout<<max(q,t);
    return 0;
}