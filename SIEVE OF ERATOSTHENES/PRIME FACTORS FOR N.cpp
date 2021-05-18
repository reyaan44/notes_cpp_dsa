#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void primefactors(ll n)
{
    ll arr[n+1]={0};
    for(ll i=2; i<=n; i++)
    {
        arr[i]=i; // ALL PRIME NUMBERS ARE THEMSELVES THEIR PRIME FACTORS
    }
    for(ll i=2; i<=n; i++)
    {
        if(arr[i]==i)
        {
            for(ll j=i*i; j<=n; j+=i) // I*I BECAUSE REST OTHERS ARE ALREADY MARKED AND FIRST UNMARKED MULTIPLE IS ALWAYS I*I
            {
                if(arr[j]==j)
                {
                    arr[j]=i;
                }
            }
        }
    }
    while(n!=1)
    {
        cout<<arr[n]<<" ";
        n/=arr[n];
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
    primefactors(n);
    return 0;
}