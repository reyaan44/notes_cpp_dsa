#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll *p; //HERE, P IS IN THE STACK
    p = new ll(20);  // P POINTS TO A SPACE IN  HEAP WITH SIZE OF ONE LL
    cout<<p<<endl;
    cout<<*p<<endl;
    *p=16;
    cout<<*p<<endl;
    delete(p);    // DEALLOCATING P, HERE THE VALUE AT HEAP WILL BE DESTROYED, BUT P WILL STILL POINT AT HEAP, WHICH IS CALLED A DANGLING POINTER.
                  // TO REMOVE IT, WE EITHER POINT P TO OTHER VALUE IN HEAP, OR DESTROY P ITSELF
    cout<<p<<endl;
    cout<<*p<<endl; // 16 is removed and garbage valuue is displayed but p points there only
    p=new ll[4];  // HERE, P POINTS TO ARRAY ALLOCATED IN HEAP
    cout<<p<<endl; // points to a new location that is starting address of the allocated array
    cout<<*p<<endl;// WE CAN ADD ELEMENTS TO ARRAY BY P[0],P[1]..... ALSO IT IS SAME AS *P,*(P+1)....
    *p=2;
    *(p+1)=4;
    p[2]=6;
    p[3]=9;
    cout<<*p<<endl;
    for(ll i=0; i<4; i++)
    {
        cout<<p[i]<<" ";    // PRINTING COMPLETE ARRAY ALLOCATED IN HEAP, ALSO WE COULD USE *(P+I) IN PLACE OF P[I];
    }
    cout<<endl;
    delete[]p;    // DEALLOCARING P
    p=NULL;       // DANGLING POINTER IS REMOVED
    cout<<p<<endl;
    cout<<*p<<endl;
    return 0;
}