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





node* mergeSortedListsReccursive(node* & head3, node* & head4)
{
  node* temp;
  if(head3==NULL)
  {
    return head4;
  }
  if(head4==NULL)
  {
    return head3;
  }
  if((head3->data)<(head4->data))
  {
    temp = head3;
    temp->next = mergeSortedListsReccursive(head3->next,head4);
  }
  else
  {
    temp = head4;
    temp->next = mergeSortedListsReccursive(head3,head4->next);
  }
  return temp;
}





node* mergeSortedLists(node* & head3, node* & head4)
{
  node* temp = new node(-1);                // WE WILL MAKE A NEW LINKED LIST AND TO MAKE THAT, WE MAKE A NEW NODE, DONT GET CONFUSED BETWEEN MAKING A NEW NODE AND A NEW POINTER, TEMP HERE IS A NEW NODE
  node* ptr1 = head3;
  node* ptr2 = head4;
  node* ptr3 = temp;                         // NEW POINTER
  while(ptr1!=NULL && ptr2!=NULL)             // TILL ANY ONE OF THESE BECOMES NULL
  {
    if((ptr1->data)<(ptr2->data))
    {
      ptr3->next=ptr1;                    // NEW LINKED LIST POINTS TO SMALLER DATA 
      ptr1=ptr1->next;
    }
    else
    {
      ptr3->next=ptr2;
      ptr2=ptr2->next;
    }
    ptr3=ptr3->next;        
  }
  while(ptr1!=NULL)                       // AFTER ONE OF THEM IS NULL, WE NEED TO TRANSVERSE THROUGH EVERY ELEMENT IN THE LINKED LIST THAT IS STILL NOT NULL AND ADD THEM IN OUR NEW LINKED LIST
  {
    ptr3->next=ptr1;
    ptr1=ptr1->next;
    ptr3=ptr3->next;
  }
  while(ptr2!=NULL)
  {
    ptr3->next=ptr2;
    ptr2=ptr2->next;
    ptr3=ptr3->next;
  }
  return temp->next;                      // TEMP WAS A NODE WITH DATA -1, WE DIDNT NEED THAT, WE NEED ALL THE ADDED NODES IN THIS NEW LINKED LIST, SO TEMP->NEXT IS RETURNED
}






ll lengthOfList(node* head);        // FORWARD DECLARATION


void make2LinkedList(node* & head1, node* & head2, ll pos)      // LINKED LIST 1 = 1->2->3->4->5->6
{                                 // LINKED LIST 2 = 10->11
                                  // MAKING 2 LINKED LIST WITH LINKED LIST 2 AND LINKED LIST 1 AT POSITION POS OF LINKED LIST 1
                                  // NOW LINKED LIST 1 = 1->2->3->4->5->6
                                  // NOW LINKED LIST 2 = 10->11->5->6     THEY HAVE 5 AS INTERSECTION NODE
  node* temp1 = head1;
  node* temp2 = head2;
  ll count = 0;
  while(temp2->next!=NULL)
  {
    temp2=temp2->next;
  }
  while(temp1!=NULL)
  {
    count++;
    if(count==pos)
    {
      temp2->next=temp1;            // MAKING LAST NODE OF LINKED LIST 2 TO POINT TO NODE AT POSITION POS OF LINKED LIST 1 MAKING THEM 2 LINKED LIST
      break;
    }
    temp1=temp1->next;
  }
}





ll FindIntersectionOf2LinkedList(node* & head1, node* & head2)
{
  node* ptr1 = head1;
  node* ptr2 = head2;
  ll l1 = lengthOfList(head1);
  ll l2 = lengthOfList(head2);
  ll diff = abs(l1-l2);           
  forl(i,0,diff)            // MAKING THE BIGGER LINKED LIST'S POINTER FROM HEAD TO DIFF POSITIONS AHEAD
  {
    if(l1>l2) ptr1=ptr1->next;
    else if(l2>l1) ptr2=ptr2->next;
    if(ptr1==NULL || ptr2==NULL) return -1;
  }
  while(ptr1!=NULL && ptr2!=NULL)
  {
    if(ptr1==ptr2)
    {
      return ptr1->data;
    }
    ptr1=ptr1->next;
    ptr2=ptr2->next;
  }
  return -1;
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
    node* head1=NULL;
    node* head2=NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    insertAtTail(head1,5);
    insertAtTail(head1,6);
    insertAtTail(head2,10);
    insertAtTail(head2,11);
    printlist(head1);
    
    make2LinkedList(head1,head2,5);               // MAKING LINKED LIST WITH HEAD2 TO JOIN LINKED LIST WITH HEAD1 AT POSITION 5 OF HEAD1
    printlist(head1);
    printlist(head2);

    cout<<FindIntersectionOf2LinkedList(head1,head2)<<endl;   // OUTPUT THE DATA OF THE NODE OF INTERSECTING NODE, ELSE IF NEVER INTERSECTING PRINT -1 
    
    node* head3=NULL;
    node* head4=NULL;
    insertAtTail(head3,1);
    insertAtTail(head3,4);
    insertAtTail(head3,5);
    insertAtTail(head3,9);
    insertAtTail(head4,2);
    insertAtTail(head4,7);
    insertAtTail(head4,10);
    printlist(head3);
    printlist(head4);
    // node* headFinal = mergeSortedLists(head3,head4);        // THIS IS COMMENTED TO SHOW THE OUTPUT OF RECCURSIVE ONE  // ITERATIVE METHOD
    // printlist(headFinal);
    node* headFinalReccursive = mergeSortedListsReccursive(head3,head4);    // RECCURSIVE METHOD
    printlist(headFinalReccursive);

    
    timetaken;
    return 0;
}