#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll power(ll n, ll p)
{
    if(p==0) return 1;
    return n*pow(n,p-1);
}
ll sum(ll n)
{
    if(n==0) return 0;
    return n+sum(n-1);
}
ll factorial(ll n)
{
    if(n==0) return 1;
    else
    return n*factorial(n-1);
}
ll fibonacci(ll n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    else
    {
        return fibonacci(n-1)+fibonacci(n-2);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // for(ll i=0; i<10; i++)
    // cout<<fibonacci(i)<<" ";
    // for(ll i=0; i<10; i++)
    // {
    //     cout<<factorial(i)<<" ";
    // }
    // for(ll i=0; i<=4; i++)
    // {
    //     cout<<sum(i)<<" ";
    // }
    // cout<<power(3,5)<<endl;
    return 0;
}