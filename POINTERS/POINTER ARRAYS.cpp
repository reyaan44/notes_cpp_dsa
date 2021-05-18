#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll arr[4];
    for(ll i=0; i<sizeof(arr)/sizeof(arr[0]); i++) cin>>arr[i];
    cout<<arr<<endl;
// ARR IS A CONSTATNT INDEX POINTER WHICH STORE ADDRESS OF ELEMENT OF INDEX NUMBER 0
// AND IT CANNOT BE INCREMENTED OR DECREMENTED 
    cout<<*arr<<endl;
    ll *ptr=arr; // HERE WE ARE MAKING ANOTHER POINTER WITH SAME VALUE AS ARR SO THAT WE CAN GET OUTPUT OF WHOLE ARRAY
    cout<<ptr<<endl;
    cout<<*ptr<<endl;
    for(ll i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
    {
        cout<<*(arr+i)<<" ";
    }
    // *(arr+i) is same as a[i]
    // arr+i is same as &a[i]
    cout<<endl;
    for(ll i=0; i<4; i++) // HERE 4 AS WELL AS SIZEOF CAN BE WRITEEN, BOTH ARE SAME
    {
        cout<<*ptr<<" ";
        ptr++;
    }
    cout<<endl;
    for(ll i=0; i<sizeof(arr)/sizeof(arr[0]); i++) cout<<arr[i]<<" ";   
    return 0;
}
