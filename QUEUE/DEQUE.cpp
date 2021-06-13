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
void display(deque<ll> dq1)                 
{
    for(auto itr = dq1.begin(); itr!=dq1.end(); itr++)
    {
        cout<<*itr<<" ";
    }   
    cout<<endl;
    for(ll i=0; i<dq1.size(); i++)
    {
        cout<<dq1.at(i)<<" ";           // NOTE DQ1.AT()
    }
    cout<<endl;
}
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    deque<ll> dq1;              // DEQUE CAN INSERT AND REMOVE ELEMENTS FROM BOTH BACK AND FRONT
    dq1.push_front(1);
    dq1.push_front(2);
    dq1.push_back(3);
    dq1.push_back(4);
    dq1.push_front(5);
    display(dq1);

    cout<<dq1.max_size()<<endl;
    cout<<dq1.front()<<endl<<dq1.back()<<endl;

    dq1.pop_front();
    display(dq1);

    dq1.pop_back();
    display(dq1);
    timetaken;
    return 0;
}