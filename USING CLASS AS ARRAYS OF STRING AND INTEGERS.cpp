#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class reyaan
{
public:
    ll marks;
    string s;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    reyaan a[5];
    reyaan b[5]; 
    for(ll i=0; i<5; i++)
    {
        cin>>a[i].s;
        cin>>a[i].marks;
        cin>>b[i].marks;
    }
    for(ll i=0; i<5; i++)
    {
        cout<<a[i].marks<<" ";
        cout<<a[i].s<<" ";
        cout<<b[i].marks<<" ";
        cout<<endl;
    }
    return 0;
}