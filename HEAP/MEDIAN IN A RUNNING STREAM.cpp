#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define precision(a) cout<<fixed<<setprecision(a)
#define testcase ll t; cin>>t; while(t--)
#define endl "\n"
#define iendl "\n", cout.flush // FOR INTERACTIVE PROBLEMS
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,b) for(ll i=a; i<b; ++i)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;
const ll M = 1000000007;
priority_queue<ll,vector<ll>> FirstHalf;    // MAX HEAP
priority_queue<ll,vector<ll>,greater<ll>> SecondHalf;   // MIN HEAP
ll median()
{
    if(FirstHalf.size()==SecondHalf.size())
    {
        return (FirstHalf.top()+SecondHalf.top())/2;
    }
    if(FirstHalf.size()>SecondHalf.size()) return FirstHalf.top();
    return SecondHalf.top();
}
void insert(ll x)
{
    if(FirstHalf.size()==SecondHalf.size())
    {
        if(FirstHalf.size()==0)
        {
            FirstHalf.push(x);
            return;
        }
        if(x<FirstHalf.top())
        {
            FirstHalf.push(x);
            return;
        }
        SecondHalf.push(x);
    }
    else
    {
        if(FirstHalf.size()>SecondHalf.size())
        {
            if(x>=FirstHalf.top())
            {
                SecondHalf.push(x);
                return;
            }
            ll temp = FirstHalf.top();
            FirstHalf.pop();
            SecondHalf.push(temp);
            FirstHalf.push(x);
        }
        else
        {
            if(x<=SecondHalf.top())
            {
                FirstHalf.push(x);
                return;
            }
            ll temp = SecondHalf.top();
            SecondHalf.pop();
            FirstHalf.push(temp);
            SecondHalf.push(x);
        }
    }
}
int main()
{
    ll arr[7]={4,1,5,7,6,3,2};
    for(ll i=0; i<7; i++)
    {
        insert(arr[i]);
        cout<<median()<<" ";
    }
    return 0;
}