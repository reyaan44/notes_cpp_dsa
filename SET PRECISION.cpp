#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    cout<<fixed<<setprecision(8);  // WE CAN FIX THE SETPRECISION FOR ALL THE DOUBLES THAT WILL BE RUN THE PROGRAM
    cin>>t;
    while(t--)
    {
        double pi = 3.14159265;
        ll n;
        cin>>n;
        double k = sin(pi/n);
        k=k*k;
        cout<<k<<endl;
        cout<<1/k<<endl;
        cout<<double(2)/double(3)<<endl;
    }
    return 0;
}
