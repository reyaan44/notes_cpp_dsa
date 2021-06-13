#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define precision(a) cout<<fixed<<setprecision(a)
#define testcase ll t; cin>>t; while(t--)
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,b) for(ll i=a; i<b; ++i)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;





class Stack1        // MAKING PUSH COSTLY
{
    ll n;
    queue<ll> q1;
    queue<ll> q2;
public:
    Stack1()
    {
        n=0;
    }
    void push(ll a)
    {
        q2.push(a);
        n++;
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    void pop()
    {
        if(n==0)
        {
            return;
        }
        n--;
        q1.pop();
    }
    ll top()
    {
        if(n==0) return -1;
        return q1.front();
    }
    ll size()
    {
        return n;
    }
};  


class Stack2        // POP IS COSTLY
{
    ll n;
    queue<ll> q1;
    queue<ll> q2;
public:
    Stack2()
    {
        n=0;
    }
    void push(ll x)
    {
        q1.push(x);
        n++;
    }
    void pop()
    {
        if(n==0) return;
        ll temp = n;
        while(temp!=1)
        {
            q2.push(q1.front());
            q1.pop();
            temp--;
        }
        q1.pop();
        swap(q1,q2);
        n--;
    }
    ll top()
    {
        if(n==0) return -1;
        return q1.back();
    }
    ll size()
    {
        return n;
    }
};
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Stack1 s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    cout<<s1.top()<<endl;
    s1.pop();
    cout<<s1.top()<<endl;
    cout<<s1.size()<<endl<<endl;

    Stack2 s2;
    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.push(4);
    cout<<s2.top()<<endl;
    s2.pop();
    cout<<s2.top()<<endl;
    cout<<s2.size()<<endl;
    timetaken;
    return 0;
}