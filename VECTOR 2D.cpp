#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define precision(a) cout<<fixed<<setprecision(a)
#define testcase ll t; cin>>t; while(t--)
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,b) for(ll i=a; i<b; ++i)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;
const ll M = 1000000007;
ll mod(ll x)
{
    return (x%M + M)%M;
}
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    testcase
    {
        ll n;
        cin>>n;
        vector<ll> u(n),s(n);
        forl(i,0,n) cin>>u[i];
        forl(i,0,n) cin>>s[i];
        map<ll,vector<ll>> m;
        forl(i,0,n)
        {
            m[u[i]].push_back(s[i]);
        }
        vector<vector<ll>> vect;
        ll cnt = 0;
        for(auto i = m.begin(); i!=m.end(); i++)
        {
            vect.push_back(i->second);  // HERE, I->SECOND IS A VECTOR, WHICH MEANS WE NEED TO PUSH BACK COMPLETE VECTOR
            sort(vect[cnt].begin(),vect[cnt].end());
            cnt++;
        }
        for(ll i=0; i<vect.size(); i++)
        {
            for(ll j=0; j<vect[i].size(); j++)
            {
                if(j!=0)
                {
                    vect[i][j]+=vect[i][j-1];  //PREFIX SUMS
                }
            }
        }
        // for(ll i=0; i<vect.size(); i++)
        // {
        //     for(ll j=0; j<vect[i].size(); j++)
        //     {
        //         cout<<vect[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<ll> ans(n);
        ll sum = 0;
        for(ll i=0; i<vect.size(); i++)
        {
            for(ll j=0; j<vect[i].size(); j++)
            {
                sum=0;
                ll del = vect[i].size()%(j+1);
                sum+=vect[i][vect[i].size()-1];
                if(del!=0) sum-=vect[i][del-1];
                // cout<<"SUM = "<<sum<<endl;
                ans[j]+=sum;
            }
        }
        for(ll i=0; i<ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    timetaken;
    return 0;
}