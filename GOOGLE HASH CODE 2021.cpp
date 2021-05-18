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
    ll d,intersection,s,v,f,p,cnt=0;
    cin>>d>>intersection>>s>>v>>f;
    vector<ll> incomingstreet(10000000,0);
    vector<string> str;
    vector<ll> start;
    vector<ll> end;
    vector<ll> l;
    string temp;
    ll t1,t2,t3;
    for (ll i = 0; i < s; i++)
    {
        cin>>t1>>t2;
        start.push_back(t1);
        end.push_back(t2);
        cin>>temp;
        str.push_back(temp);
        cin>>t3;
        l.push_back(t3);
    }
    vector<string> cars[v];
    string temp2;
    ll ans=-1;
    ll k,result;
    for(ll i=0; i<s; i++)
    {
        k=count(l.begin(),l.end(),i);
        if(k>ans)
        {
            ans=k;
            result=l[i];
        }
    }
    for (ll i = 0; i < v; i++)
    {
        cin >> p;
        for (ll j = 0; j < p; j++)
        {
            cin>>temp2;
            cars[i].push_back(temp2);
        }
    }
    cout<<intersection<<endl;
    for(ll i=0; i<intersection; i++)
    {
        cout<<i<<endl;
        incomingstreet[i]=count(end.begin(), end.end(), i);
        cout<<incomingstreet[i]<<endl;
        for(ll j=0; j<s; j++)
        {
            if(end[j]==i)
            {
                cout<<str[j]<<" "<<result<<endl;
            }
        }
    }
    return 0;
}