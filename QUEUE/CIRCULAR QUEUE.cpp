#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define precision(a) cout<<fixed<<setprecision(a)
#define testcase ll t; cin>>t; while(t--)
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,b) for(ll i=a; i<b; ++i)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;
class CircularQueue
{
    ll front,back;
    ll size;
    ll *arr;
public:
    CircularQueue()
    {
        size=0;
        front=0;
        back=0;
    }
    CircularQueue(ll n)
    {
        size=n;
        arr = new ll[size+1];           // BECOZ NO ELEMENT WILL EVER BE PRESENT AT FRONT POINTER
        front=0;
        back=0;
    }
    void enqueue(ll a)
    {
        if((front==0 && back==size) || front==(back+1)%(size+1)) // BECOZ FRONT IS ALWAYS EMPTY   AND   IF BACK IS JUST BEFORE FRONT
        {
            cout<<"Queue is full"<<endl;
            return;
        }   
        back=(back+1)%(size+1);
        arr[back]=a;
    }
    void dequeue()
    {
        if(front==back)     // ONLY COMDITION FOR EMPTY QUEUE
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        front=(front+1)%(size+1);
    }
    bool empty()
    {
        if(front==back) return 1;
        return 0;
    }
    ll top()
    {
        return arr[(front+1)%(size+1)];
    }
};
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    CircularQueue c1(4);
    cout<<c1.empty()<<endl;
    c1.enqueue(1);
    cout<<c1.empty()<<endl;
    c1.enqueue(2);
    cout<<c1.top()<<endl;
    c1.dequeue();
    cout<<c1.top()<<endl;
    c1.enqueue(3);
    c1.enqueue(4);
    cout<<c1.top()<<endl;
    c1.enqueue(5);
    cout<<c1.empty()<<endl;
    cout<<c1.top()<<endl;
    c1.dequeue();
    cout<<c1.top()<<endl;
    c1.enqueue(6);
    c1.enqueue(7);
    timetaken;
    return 0;
}