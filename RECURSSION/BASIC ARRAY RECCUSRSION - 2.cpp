#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll first(ll arr[], ll n, ll k, ll index)
{
    if(n==0) return -1; 
    if(arr[0]==k) return index;
    else return first(arr+1,n-1,k,index+1);
}
ll last(ll arr[], ll n, ll k, ll index)
{
    if(index==n) return -1;
    ll rest = last(arr,n,k,index+1);
    if(rest!=-1)
    {
        return rest;
    }
    if(arr[index]==k) return index;
    return -1;
}
void increasingorder(ll n)
{
    if(n==0) return;
    increasingorder(n-1);
    cout<<n<<" ";
}
void decreasingorder(ll n)
{
    cout<<n<<" ";
    if(n==0) return;
    return decreasingorder(n-1);
}
bool sortcheck(ll arr[],ll n)
{
    if(n==1) return true;
    bool rest = sortcheck(arr+1, n-1);
    return (arr[0]<arr[1] && rest);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // ll arr[8]={1,2,3,4,5,6,7,8};
    // ll n = sizeof(arr)/sizeof(arr[0]);
    // if(sortcheck(arr,n)) cout<<"YES"<<endl;
    // else cout<<"NO"<<endl;
    // ll n=10;
    // decreasingorder(n);
    // ll n=10;
    // increasingorder(n);
    // ll arr[]={4,2,1,2,5,2,7};
    // ll n = sizeof(arr)/sizeof(arr[0]);
    // ll k = 2,index=0;
    // cout<<"FIRST = "<<first(arr,n,k,index)<<endl;
    // cout<<"LAST = "<<last(arr,n,k,index)<<endl;
    return 0;
}