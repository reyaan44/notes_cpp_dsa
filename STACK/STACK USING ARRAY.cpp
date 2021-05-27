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
class Stack
{
	ll top;
	ll *arr;
	ll size;
public:
	Stack()
	{
		cout<<"PLEASE ACCESS PARAMETERIZED CONSTRUCTOR"<<endl;
	}
	Stack(ll n)
	{
		size=n;
		arr = new ll[size];
		top = -1;
	}
	void push(ll x)
	{
		if(top==size-1)
		{
			cout<<"STACK OVERFLOWED"<<endl;
			return;
		}
		top++;
		arr[top]=x;
	}
	void pop()
	{
		if(top==-1)
		{
			cout<<"0 ELEMENTS LEFT"<<endl;
			return;
		}
		top--;
	}
	ll Top()
	{
		if(top==-1)
		{
			cout<<"0 ELEMENTS LEFT"<<endl;
			return -1;
		}
		return arr[top];
	}
	bool empty()
	{
		return top==-1;
	}
};
int main()
{
    quick;
    Stack s(100);
    s.push(7);
    s.push(8);
    s.push(9);
    cout<<s.Top()<<endl;
    s.pop();
    cout<<s.Top()<<endl;
    s.pop();
    s.pop();
    s.pop();
    cout<<s.Top()<<endl;
    cout<<s.empty()<<endl;
    timetaken;
    return 0;
}