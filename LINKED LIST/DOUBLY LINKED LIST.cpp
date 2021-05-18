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
class node
{
public:
  ll data;
  node* next;
  node* prev;
  node(ll val)
  {
    data = val;
    next=NULL;
    prev=NULL;
  }
};
void insertAtHead(node* & head, ll val)
{
  node* n = new node(val);
  n->next=head;
  if(head!=NULL) head->prev=n;
  head=n;
}
void insertAtTail(node* & head, ll val)
{
  node* n = new node(val);
  node* temp = head;
  if(head==NULL)
  {
    insertAtHead(head,val);
    return;
  }
  while(temp->next!=NULL)
  {
    temp=temp->next;
  }
  temp->next=n;
  n->prev=temp;
}
void deleteNode(node* & head, ll val)
{
  node* temp = head;
  if(head->data==val)
  {
    node* todelete = head;
    head=head->next;
    head->prev=NULL;
    delete todelete;
    return;
  }
  while(temp->data!=val && temp!=NULL)
  {
    temp=temp->next;
  }
  temp->prev->next=temp->next;
  if(temp->next!=NULL) temp->next->prev=temp->prev;
  node* todelete = temp;
  delete todelete;
}
void display(node* head)
{ 
  node* temp = head;
  while(temp!=NULL)
  {
    cout<<temp->prev<<" "<<temp->data<<" "<<temp->next<<endl;
    temp=temp->next;
  }
  cout<<endl;
}
ll mod(ll x)
{
    return (x%M + M)%M;
}
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,6);
    insertAtTail(head,98);
    display(head);
    insertAtHead(head, 999);
    display(head);

    deleteNode(head,3);
    deleteNode(head,98);
    deleteNode(head,999);
    display(head);
    timetaken;
    return 0;
}