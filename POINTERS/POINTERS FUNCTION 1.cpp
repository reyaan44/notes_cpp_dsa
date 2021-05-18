#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll & maxi(ll & x, ll & y) // HERE, WE ARE DOING RETURN BY REFERENCE
{
    if(y>x) return y;
    else return x;
    // AS X AND Y ARE REFERENCE VARIABLES, WHILE RETURNING THEM, WE MUST WRITE LL & FUNC_NAME(...)
}
void swapup(ll & a, ll & b) // HERE, WE DECLARE TWO REFERENCE VARIABLES, SO ANY CHANGE HERE WILL BE DONE IN MAIN FUNCTION VARIABLES 
{
    ll temp=a;
    a=b;
    b=temp;
}
void swapit(ll *x, ll *b) //HERE, WE HAVE TO RECIEVE IN POINTERS AS ARGUMENTS ARE SENT HERE IN POINTERS
{
    ll temp=*x;  // HERE, WE ARE DEFERENCING THE VALUES DUE TO WHICH WE ARE ABLE TO DIRECTLY ACCESS A AND B WITH THE HELP OF THEIR ADDRESS AND MAKE CHANGES IN THEM
    *x=*b;
    *b=temp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll a=4,b=6;
    cout<<"BEFORE SWAP "<<a<<" "<<b<<endl;
    ll *aptr=&a;
    ll *bptr=&b;
    swapit(aptr,bptr); // HERE, WE ARE SENDING POINTERS, SO RECIEVERS MUST ALSO BE POINTERS
    cout<<"AFTER SWAP "<<a<<" "<<b<<endl;
    swapup(a,b);   // HERE, WE CAN JUST SEND NORMALLY AND RECIEVE IN REFERENCE VARIABLES ABOVE SO CHANGE THERE WILL BE SAME AS CHANGE HERE
    cout<<"AFTER ANOTHER SWAP "<<a<<" "<<b<<endl;
    cout<<maxi(a,b)<<endl;
    return 0;
}