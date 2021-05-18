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
class node
{
  public:
    ll data;
    node* next;
    node(ll val)
    {
      data=val;
      next=NULL;
    }
    node()
    {
      next=NULL;
    }
};


// CIRCULAR LINKED LIST


void deleteNode(node* & head, ll pos)
{
  ll count=1;
  node* n = head;
  if(pos==1)                            // IF WE WANT TO DELETE HEAD NODE
  {
    while(n->next!=head)
    {
      n=n->next;
    }
    n->next=head->next;
    node* temp = head;
    head=head->next;
    delete temp;
    return;
  }
  while(count!=pos)
  {
    n=n->next;
    count++;
  }
  node* temp = n->next;
  n->next=n->next->next;
  delete temp;
}




void printlist(node* head)          // HERE, LIST IS CIRCULAR SO IT WILL GO IN INFINITE LOOP AND WILL NEVER REACH NULL, SO WE TRANSVERSE TILL TEMP->NEXT!=HEAD
{
  node* temp = head;
  do
  {
    cout<<temp->data<<" "<<temp->next<<endl;
    temp=temp->next; 
  }
  while(temp!=head);       // NEED A DO-WHILE BECOZ IN NORMAL, IF WE DO WHILE(temp->next!=head) WE WONT BE ABLE TO PRINT THE LAST ELEMENT
  cout<<endl;
}




void insertAtHead(node* & head, ll val)     // OBSERVE THE CHANGES BECOZ OF LIST BEING CIRCULAR
{
  node* temp = new node(val);
  node* n = head;
  temp->next = head;
  while(n->next!=head) 
  {
    n=n->next;
  }
  n->next=temp;
  head=temp;
}



void insertAtTail(node* & head, ll val)   // OBSERVE THE CHANGES BECOZ OF LIST BEING CIRCULAR
{
  node* temp = new node(val);
  if(head==NULL)
  {
    temp->next=temp;
    head = temp;
    return;
  }
  node* n = head;
  while(n->next!=head)
  {
    n=n->next;
  }
  n->next=temp;
  temp->next=head;
}





int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    printlist(head);
    insertAtHead(head,98);
    printlist(head);

    deleteNode(head,3);
    printlist(head);
    deleteNode(head,1);
    printlist(head);


    timetaken;
    return 0;
}