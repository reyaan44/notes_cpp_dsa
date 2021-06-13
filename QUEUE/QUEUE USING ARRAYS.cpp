#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;
class Queue             // FIRST IN FIRST OUT
{
    ll *arr;
    ll front;           // POINTS TO FIRST ELEMENT OF THE QUEUE
    ll back;            // POINTS TO LAST ELEMENT OF QUEUE
    ll n;
public:
    Queue()
    {
        n=0;
        front=-1;
        back=-1;
    }
    Queue(int a)
    {
        n = a;
        front=-1;
        back=-1;
        arr=new ll[n];
    }
    void enqueue(ll a)      // ADD NEW MEMBER TO QUEUE AT LAST
    {
        if(back==n-1)
        {
            cout<<"Not Possible"<<endl;
            return;
        }
        back++;
        arr[back]=a;
        if(front==-1)       // IF FIRST ELEMENT
        {
            front++;
        }
    }
    void dequeue()      // REMOVES FIRST ELEMENT
    {
        if(front==-1 || front>back)
        {
            cout<<"Not Possible"<<endl;
            return;
        }
        front++;
    }
    ll peek()       // RETURNS FIRST ELEMENT
    {
        if(front==-1 || front>back)
        {
            cout<<"Not Possible"<<endl;
            return -1;
        }
        return arr[front];
    }
    bool empty()
    {
        if(front==-1 || front>back)
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
    Queue q1(6);
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
    cout<<q1.empty()<<endl;
    timetaken;
    return 0;
}