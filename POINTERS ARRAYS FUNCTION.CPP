#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll sumofarr(ll *arr, ll size) // HERE, WE CAN TAKE LL *ARR AS WELL AS LL ARR[] AS ARGUMENTS, BOTH ARE SAME
// BECAUSE WHEN CALLING FUNCTION CALLS AN ARRAY, WHOLE ARRAY IS NOT CALLED, IT CAN BE VERY BIG IN SIZE AND IT IS UNNECESSARY TO WASTE SUCH A BIG MEMORY EVERY TIME
// SO WHEN ARRAY IS CALLED, CALLED FUNCTION RECIEVES A POINTER TARGETTING THE ADDRESS OF FIRST ELEMENT OF AN ARRAY THATS WHY WE CAN RECIEVE * ARR.
{
    ll sum=0;
    for(ll i=0; i<size; i++)
    {
        sum+=*(arr+i);   // *(arr+i) is same as arr[i]
                         // arr is same as &arr[0]
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll arr[]={1,2,3,4,5};
    ll size=sizeof(arr)/sizeof(arr[0]);
    /* HERE, WE ARE TAKING SIZE HERE IN THIS INT MAIN AND NOT ABOVE BECAUSE HERE SIZEOF(ARR) WILL COME MORE, AS AOVE, ARR IS NOT ARRAY, IT IS MERELY A POINTER FUNCTION POINTING TO FIRST ELEMENT
    OF REAL ARRAY, WHERE AS IN MAIN FUNCTION, IT IS A COMPLETE ARRAY */
    ll sum=sumofarr(arr,size);
    cout<<sum<<endl;   
    return 0;
}
/* WHATEVER CHANGES WE WILL MAKE IN ARRAY IN UPWARDS FUNCTION, BE IT VOID OR SOMETHING ELSE, EVERYTHING WILL BE REFLECTED IN MAIN ARRAY, LIKE IF WE DOUBLE ALL THE ELEMENTS OF ARRAY IN ABOVE FUNCTION, AND PRINT THE VALUES OF ARRAY IN MAIN FUNCTION AFTER THAT, IT WILL SHOW THE DOUBLED ELEMENTS, BECAUSE ARRAY IN FYNCTION IS "ALWAYS" CALL BY REFERENCE */ 
