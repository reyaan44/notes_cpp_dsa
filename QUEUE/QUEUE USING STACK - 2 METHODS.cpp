#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;
class QueueCallStack
{
	public:
    stack<ll> s1;
    void enqueue(ll a)
    {
        s1.push(a);
    }
    void dequeue()
    {
        if(s1.empty())
        {
            return;
        }
        ll x = s1.top();
        s1.pop();
        if(s1.empty())
        {
        	return;
        }
        dequeue();
        s1.push(x);
    }
    ll peek()
    {
        if(s1.empty())
        {
            return -1;
        }
        ll x = s1.top();
        s1.pop();
        if(s1.empty())
        {
        	s1.push(x);
        	return x;
        }
        ll a = peek();
        s1.push(x);
        return a;
    }
    bool empty()
    {
        if(s1.empty())
        {
            return 1;
        }
        return 0;
    }

};


class Queue
{
public:
    stack<ll> s1;
    stack<ll> s2;
    void enqueue(ll a)
    {
        s1.push(a);
    }
    void dequeue()
    {
        if(s1.empty()==1 && s2.empty()==1)
        {
            cout<<"Not Possible"<<endl;
            return;
        }
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }
    ll peek()
    {
        if(s1.empty()==1 && s2.empty()==1)
        {
            cout<<"Not Possible"<<endl;
            return -1;
        }
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    bool empty()
    {
        if(s1.empty()==1 && s2.empty()==1)
        {
            return 1;
        }
        return 0;
    }
};
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Queue q1;
    q1.enqueue(1);
    cout<<q1.peek()<<endl;
    q1.enqueue(2);
    cout<<q1.peek()<<endl;
    q1.enqueue(3);
    q1.enqueue(4);
    cout<<q1.peek()<<endl;
    q1.dequeue();
    cout<<q1.peek()<<endl;
    q1.dequeue();
    cout<<q1.peek()<<endl;
    cout<<q1.empty()<<endl<<endl;

    QueueCallStack q2;
    q2.enqueue(1);
    cout<<q2.peek()<<endl;
    q2.enqueue(2);
    cout<<q2.peek()<<endl;
    q2.enqueue(3);
    q2.enqueue(4);
    cout<<q2.peek()<<endl;
    q2.dequeue();
    cout<<q2.peek()<<endl;
    q2.dequeue();
    cout<<q2.peek()<<endl;
    cout<<q2.empty()<<endl;
    timetaken;
    return 0;
}