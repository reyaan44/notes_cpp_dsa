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
class node // FORMING A NODE IN LINKEDLIST
{           // IT HAS DATA AND A POINTER TO OBJECT
public:
  ll data;    // DATA
  node* next;   // POINTER TO  AN OBJECT OF SAME CLASS
  node(ll val) // CONSTRUCTOR
  {
    data=val;
    next=NULL;
  }
  node()      // CONSTRUCTOR
  {
    next=NULL;
  }
};

void EvenPositionsAfterOddPositions(node* & head);

void appendLastKNodes(node* & head, ll k, ll length);

node* reverseKNodes(node* & head, ll k);
node* reverseListReccursive(node* & head);
void reverseList(node* & head);

void formCycle(node* & head,ll pos);
bool detectCycle(node* head);
void removeCycle(node* & head);

void deleteNode(node* & head, ll val);

bool search(node* head, ll key);

ll lengthOfList(node* head);

void printlist(node* n);

void insertAtHead(node* & head, ll val);
void insertAtTail(node* & head,ll val);




void EvenPositionsAfterOddPositions(node* & head)     // MAKING LINKED LIST 1->2->30->4->5->7->8 TO 1->30->5->8->2->4->7
                                                      // HERE, ODD AND EVEN DOESNT MEANS DATA OF NODE, IT MEANS POSITIONS OF THE NODES IN LINKED LIST
{
  node* odd = head;
  node* evenHead = head->next;              // IT WILL HELP IN MAKING LAST ELEMENT OF ODD TO JOIN TO FIRST ELEMENT OF EVEN
  node* even = head->next;
  while(even->next!=NULL)
  {
    odd->next=odd->next->next;
    odd=odd->next;            
    if(even->next->next!=NULL)              // IF NUMBER OF ELEMENTS ARE ODD
    {
      even->next=even->next->next;
      even=even->next;
    }
    else
    {
      even->next=NULL;
    }
  }
  odd->next=evenHead;
  even->next==NULL;
}




void appendLastKNodes(node* & head, ll k, ll length)      // MAKING 1->2->3->4->5->6->7  TO  5->6->7->1->2->3->4  FOR K=3, MAKING LAST K NODES IN A LIST FIRST K NODES AND THEN REST WILL FOLLOW
{
  ll count=0;
  k=k%length;                                  // FOR CASE WHERE K>L
  node *newTail,*newHead;                 
  node* temp = head;
  while(temp->next!=NULL)
  {
    count++;
    if(count==length-k)
    { 
      newTail=temp;                   // JUST BEFORE ELEMENT FROM LAST K NODES, (K+1)'TH NODE FROM RIGHT
      newHead=temp->next;             // JUST THE ELEMENT OF LAST K NODES, K'TH NODE FROM RIGHT
    }
    temp=temp->next;
  }
  temp->next=head;
  newTail->next=NULL;
  head=newHead;
}





node* reverseKNodes(node* & head, ll k)     // FOR EG, 1->2->3->4->5->6->7->NULL, FOR K=2, THIS BECOMES 2->1->4->3->6->5->7->NULL
{
  node *prev=NULL,*curr=head,*nxt;
  ll count=0;
  while(curr!=NULL && count<k)      // REVERSING K NODES AND THEN MAKING ANOTHER ECCURSIVE FUNCTION
  {
    nxt = curr->next;
    curr->next = prev;
    prev = curr;
    curr=nxt;
    count++;
  }
  if(curr!=NULL)
  {
    head->next = reverseKNodes(nxt,k);
  }
  return prev;
}
node* reverseListReccursive(node* & head)
{
  if(head->next==NULL || head==NULL)
  {
    return head;
  } 
  node* newhead = reverseListReccursive(head->next);
  head->next->next=head;  // NEXT(SUCCESSIVE) NODE OF HEAD POINTS BACK TO HEAD, AND THE NEXT (SUCCESSIVE) NODE BECOMES HEAD IN ANOTHER RECCURSIVE FUNCTION 
  head->next=NULL;
  return newhead;
}
void reverseList(node* & head)
{
  // MAKING THREE POINTERS, PREV CURR AND NXT, MAKING CURR->NEXT=PREV, AND THEN MOVE ONE STEP AHEAD TILL END
  node *prev=NULL,*curr=head,*nxt;
  while(curr!=NULL)
  {
    nxt=curr->next;
    curr->next=prev;
    prev=curr;        // PREV IS NOW THE NODE CURRENT WAS
    curr=nxt;         // CURR IS NOW THE NODE NXT WAS
  }
  head = prev;
}





void formCycle(node* & head,ll pos)       // MAKING A CYCLE FROM NORMAL SINGLY LINKED LIST
{
  ll count=0;
  node* temp=head;
  node* startCycle;
  while(temp->next!=NULL)
  {
    if(count==pos)
    {
      startCycle = temp;
    }
    count++;
    temp=temp->next;
  }
  temp->next = startCycle;          // INSTEAD OF NULL, LAST NODE POINTS TO A NODE AT POSITION POS MAKING IT A CYCLE
}
bool detectCycle(node* head) // HARE AND TORTOISE ALGORITHM \ FLOYDS ALGORITHM
{
  node* fast=head,*slow = head;      // FAST AND SLOW START FROM HEAD, FAST MAKES TWO STEPS EVERYTIME AND SLOW MAKES 1, AT SOME POINT, THEY MEET, IF THEY MEET, ITS A CYCLE, ELSE NOT
  while(fast!=NULL && fast->next!=NULL)
  {
    slow=slow->next;          // MOVING ONE STEP
    fast=fast->next->next;    // MOVING TWO STEPS
    if(slow==fast) return 1;
  }
  return 0;
}
void removeCycle(node* & head) // HARE AND TORTOISE ALGORITHM \ FLOYDS ALGORITHM
{
  // MAKE ONE OF FAST OR SLOW TO BECOME HEAD AFTER THEY MET, THEN BOTH MOVES ONE ONE STEP AHEAD, THE POINT WHERE THEY MEET IS THE NODE CONNECTING TO CYCLE, WE JUST MAKES THE SECOND LAST NODE JUST BEFORE WHICH POINTS TO NODE IN POS TO POINT TO NULL
  node* fast=head,*slow=head;
  do
  {
    slow=slow->next;
    fast=fast->next->next;      // REACHING TO THE POSITION
  }
  while(slow!=fast);
  fast=head;              // MAKING ONE OF THEM TO BECOME HEAD
  while((slow->next)!=(fast->next))     // TAKING ONE ONE STEPS
  {
    slow=slow->next;
    fast=fast->next;
  }
  slow->next=NULL;      // MAKING SECOND LAST NODE BEFORE THE POS NODE TO POINT TO NULL
}





void deleteNode(node* & head, ll val)   // RECIEVING HEAD AS REFERENCE
{
  if(head==NULL)                    // NO VALUE ANYWHERE, NOTHING TO DELETE
  {
    return;
  }
  if(head->data==val)              // CHECKING HEAD FOR THE NODE
  {
    node* n = head;                // MAKING A NODE N BECOMING HEAD
    n=n->next;                    // N BECOMES THE NEXT NODE BECOZ ->NECT ON RIGHT SIDE OF EQUAL TO REPRESENTS THE NEXT NODE ITSELF AND NOT THE NEXT SECTION OF THAT OWN NODE
    delete head;                  // DELETING IS A GOOD HABIT
    head=n;                       // MAKING HEAD AS THE NODE N, AS I SAID, NAME DOESNT MATTER MUCH, WE NAME NEXT NODE HEAD, IT BECOMES HEAD
    return;
  }
  node *n = head;                 
  while(((n->next)->data)!=val)   // IT MEANS DATA OF SUCCESSIVE(COMES AFTER N) NODE OF N != VAL
  {
    n=n->next;
  }
                                // IF LOOP TERMINATES, WE HAVE N AS THE PREVIOUS NODE OF THE NODE THAT IS TO BE DELETED
  node* todelete = n->next;     // MAKING A NODE TODELETE AND POINTING IT TO THE NODE THAT IS TO BE DELETED
  n->next = n->next->next;      // HERE, N->NEXT MEANS NEXT SECTION OF NODE N, AND N->NEXT->NEXT MEANS NEXT TO MEXT NODE FROM N, PRECISELY AS N IS PREVIOUS NODE OF THE NODE TO BE DELETED, N->NEXT->NEXT IS THE SUCCESSIVE NODE AFTER THE NODE WHICH IS TO BE DELETED, WHICH MEANS WE ARE POINTING PREVIOUS NODE TO SUCCESSIVE NODE
  delete todelete;              // GOOD HABIT TO REMOVE FROM DYNAMIC MEMORY IF OF NO USE 
}






bool search(node* head, ll key)   // KEY IS THE VALUE IN DATA THAT IS TO BE SEARCHED
{
  node* temp = head;        // MAKING TEMP A HEAD
  while(temp!=NULL)         // DOING TEMP!=NULL AND NOT DOING TEMP->NEXT!=NULL BECOZ, IF WE MAKE TEMP->NEXT!=NULL, THEN WE WILL NOT GET LAST NODE TO BE CHECKED INSIDE WHILE LOOP, AND LAST ELEMENT WONT EVER BE CHECKED, BUT IF WE DO TEMP!=NULL, THEN FIRST EVERY ELEMENT IS CHECKED INCLUDING LAST ELEMENT, AND THEN WHEN WE MOVE TO NEXT ELEMENT WHOCH IS NULL, THE LOOP TERMINATES 
  {
    if(temp->data==key)
    {
      return 1;
    }
    temp=temp->next;
  }
  return false;
}





ll lengthOfList(node* head)
{
  node* temp = head;
  ll count=0;
  while(temp!=NULL)
  {
    count++;
    temp=temp->next;
  }
  return count;
}




void printlist(node* n)                     // HERE, WE FORM A NEW NODE N WHICH POINTS TO HEAD, OR MORE PRECISELY, IT BECOMES A HEAD(NOT PERMANENTLY, JUST FOR THIS FUNCTION, ATHOUGH HEAD AND NODE*N=HEAD, BOTH CAN COEXIST IN SAME FUNCTION, AND BOTH BECOMES THE HEAD NODE) OR WE CAN SAY, THIS NODE WILL BE HEAD NODE ONLY AND CAN DO EVERYTHING AND MAKE EVERY CHANGE A HEAD NODE CAN
{
  while(n!=NULL)                    // HERE, N!=NULL DOES NOT MEANS THE NODE WHICH HAS SOME DATA AND ITS NEXT IS NULL (LAST NODE), IT MEANS THAT AFTER WE GET AT THE LAST NODE, WE PRINT ITS DATA, ITS NEXT WHICH IS NULL, THEN WE MOVE AT NEXT NODE (WHICH IS NOT THERE) AND AS THE ADDRESS TO NEXT NODE IS NULL, WE WILL CONSIDER THE WHOLE NEXT NODE TO BE NULL
  {
    cout<<n->data<<" "<<n->next<<endl;
    n=n->next;                      // HERE, N->NEXT IS ON RIGHT SIDE OF EQUAL TO, SO IT MEANS WE ARE POINTING TO THE NEXT NODE ONLY, N=N->NEXT MEANS N WILL NOW BECOME(YES, BECOME, NOT PERMANENTLY, BUT ALL CHANGES WILL BE AFFECTED AS IF IT WAS REAL) NEXT NODE                                                                                      
  }
  cout<<endl;
}    





void insertAtHead(node* & head, ll val)               // HEAD AS REFERENCE                      
{                                                     
  node *temp = new node(val);                   // MAKING NEW NODE THAT IS TO BE INSERTED IN HEAD, OR MADE A HEAD
  temp->next = head;                            // WE INSERT IT HERE BEFORE HEAD, IT POINTS HEAD, TEMP->HEAD->.....
  head = temp;      // MAKING ANOTHER OBJECT THIS OBJECT    // WE MAKE HEAD OF THE LIST TEMP, THE NAMES OF NODES DOENT MATTER AS LONG AS WE ARE USING THEM , BUT IN EVERY FUNCTION, ALL WE WANT IS THE HEAD, SO WE MAKE TEMP A NEW HEAD, THIS WAY (NOW)HEAD->(PREV HEAD)->.....
}
void insertAtTail(node* & head,ll val)    // HERE, WE ARE RECIEVING HEAD AS REFERENCE
{
  node *temp = new node(val);             // MAKING A NEW NODE TEMP AND INITIALISING ITS DATA AS VAL BY INVOKING CONSTRUCTOR
  if(head==NULL)                          // HERE, HEAD IS INITIALISED BUT NOT DONE ANYTHING ON IT
  {
    head = temp;
    return; 
  }
  node *n = head;                         // INITIALIZING NODE* N, N BECOMES HEAD
  while((n->next)!=NULL)                  // N->NEXT!=NULL MEANS ITERATING TILL LAST ELEMENT, GET IT AS N AND STOP
  {
    n=n->next;
  }
  n->next = temp;                       // N->NEXT MEANS POINTER LAST NODE HERE TO A NEW NODE, WHICH ADDS ONE NODE TO TAIL
}






int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    node *head,*second,*third;          // HEAD IS THE FIRST NODE IN A LINKED LIST // FORMING OF NODES
    head = new node();                  // MAKING A SPACE IN DYNAMIC MEMORY ALLOCATION
    second = new node();
    third = new node();
    head->data = 1;                     // STORES 1 IN DATA SECTION OF HEAD NODE
    head->next = second;                // HERE, HEAD->NEXT IS ON LEFT SIDE OF EQUAL TO, SO IT POINTS TO OTHER OBJECTS, SO HEAD->NEXT POINTS TO SECOND NODE
                                        // HERE, NEXT OF HEAD STORES ADDRESS OF SECOND NODE
    second->data = 2;
    second->next = third;               // SECOND'S NEXT POINTS TO THIRD NODE, HERE SECOND'S NEXT WILL STORE THE ADDRESS OF THE THIRD NODE
    third->data = 3;
    third->next = NULL;                  // LAST NODE POINTS TO NULL FOR OBVIOUS REASONS
    printlist(head);                     // GIVES HEAD AS ARGUMENT, IT PRINTS THE WHOLE LIST

    insertAtTail(head,6);                // TAIL IS THE LAST ELEMENT OF LINKED LIST, WE INSERT ANOTHER NODE THERE, 6 IS THE DATA FOR NEW NODE
    printlist(head);

    insertAtHead(head,98);
    printlist(head);

    cout<<search(head,4)<<endl; 
    cout<<search(head,98)<<endl;
    cout<<search(head,6)<<endl;

    deleteNode(head,3);         // DELETING A NODE WITH VALUE 3
    printlist(head);
    deleteNode(head,98);
    printlist(head);

    cout<<head->data<<" "<<head->next<<endl<<endl;

    reverseList(head);             // ITERATIVE METHOD
    printlist(head);
    head=reverseListReccursive(head); // RECURSIVE METHOD
    printlist(head);

    insertAtTail(head,8);
    insertAtTail(head,12);
    insertAtHead(head,9);
    printlist(head);
    head = reverseKNodes(head,2);
    printlist(head);

    cout<<detectCycle(head)<<endl;
    formCycle(head,3);
    cout<<detectCycle(head)<<endl;
    //printlist(head);
    removeCycle(head);
    cout<<detectCycle(head)<<endl;
    printlist(head);

    cout<<lengthOfList(head)<<endl;
    ll length = lengthOfList(head);
    appendLastKNodes(head,3,length);
    printlist(head);

    EvenPositionsAfterOddPositions(head);
    printlist(head);
    insertAtTail(head,4);
    printlist(head);
    EvenPositionsAfterOddPositions(head);
    printlist(head);


    timetaken;
    return 0;
}