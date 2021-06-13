#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;
class node
{
public:
    ll data;
    node* next;
    node()
    {
        data=-1;
        next=NULL;
    }
    node(ll val)
    {
        data=val;
        next=NULL;
    }
};
class Queue
{
public:
    node* front;
    node* back;
    Queue()
    {
        front=NULL;
        back=NULL;
    }
    void enqueue(ll a)
    {
        node* temp = new node(a);
        if(front==NULL)
        {
            front=temp;
            back=temp;
            return;
        }
        back->next=temp;
        back=temp;
    }
    void dequeue()
    {
        node* todelete = front;
        if(front==back || front==NULL)
        {
            front=NULL;
            back=NULL;
            delete todelete;
            return;
        }
        front=front->next;
        delete todelete;
    }
    ll peek()
    {
        if(front==NULL)
        {
            cout<<"Not Possible"<<endl;
            return -1;
        }
        return front->data;
    }
    bool empty()
    {
        if(front==NULL)
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
    cout<<q1.empty()<<endl;
    timetaken;
    return 0;
}