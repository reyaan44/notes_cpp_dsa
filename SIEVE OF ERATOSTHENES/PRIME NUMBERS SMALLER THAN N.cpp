#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void sieveoferatosthenes(ll n)
{
    ll arr[n+1]={0};
    for(ll i=2; i<=n; i++)
    {
        if(arr[i]==0)
        {
            for(ll j=i*i; j<=n; j+=i) // I*I BECAUSE REST OTHERS ARE ALREADY MARKED AND FIRST UNMARKED MULTIPLE IS ALWAYS I*I
            {
                arr[j]=1;
            }
        }
    }
    // MAKE ALL MULTIPLES OF THE UNMARKED (ARR = 0) MARKED (ARR = 1)
    for(ll i=2; i<=n; i++)
    {
        if(arr[i]==0)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin>>n;
    sieveoferatosthenes(n);
    return 0;
}