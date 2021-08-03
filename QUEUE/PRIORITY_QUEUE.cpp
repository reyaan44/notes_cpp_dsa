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
void display(priority_queue<ll> dq1)
{
    while(!dq1.empty())
    {
        cout<<dq1.top()<<" ";
        dq1.pop();
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
    priority_queue<ll> dq1;   // MAX HEAP      // IN PRIORITY QUEUE, first element of the queue is the greatest of all elements in the queue and elements are in non increasing order
    dq1.push(1);
    dq1.push(2);
    dq1.push(100);
    dq1.push(3);
    dq1.push(8);
    dq1.push(4);
    dq1.push(5);
    display(dq1);

    cout<<dq1.top()<<endl;

    dq1.pop();
    display(dq1);

    dq1.pop();
    display(dq1);
    timetaken;
    return 0;
}