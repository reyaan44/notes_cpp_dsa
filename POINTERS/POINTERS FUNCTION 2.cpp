#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void increment(ll *ptr)
{
    (*ptr)++;
    *ptr+=1; // HERE, IF WE DO (*PTR++), IT WILL INCREMENT THE ADDRESS VALUE, WE DO *PTR=*PTR+1
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll a = 3;
    cout<<"BEFOR INCREMENT = "<<a<<endl;
    increment(&a);
    cout<<"AFTER INCREMENT = "<<a<<endl;
    return 0;
}