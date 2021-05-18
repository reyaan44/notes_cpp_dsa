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
    ll arr[2][3]={{1,2,3},{4,5,6}};
    cout<<arr<<endl;
    ll (*ptr)[3]=arr; // HERE, WE CANNOT WRITE *PTR=ARR, BECAUSE HERE ARR IS NOT A POINTER TO SINGLE ELEMENT OF AN ARRAY BUT IT IS POINTER TO A 1D ARRAY OF SIZE 3 
    // HERE, PTR IS A POINTER TO A ONE DIMENSIONAL ARRAY OF 3 INTEGERS.
    cout<<ptr<<endl;  // HERE, PTR REPRESENTS POINTER TO A STARTING OF 1D ARRAY OF ARR[0]
    cout<<ptr+1<<endl;// HERE, PTR+1 REPRESENTS POINTER TO STARTING OF ARITHMETICALLY NEXT 1D ARRAY OF ARR[1]
    cout<<*ptr<<endl; // HERE, *PTR DOES NOT GET  US THE VALUE OF ELEMENT OF 1D ARRAY, IT POINTS TO THE FIRST ELEMENT OF 1D ARRAY OF ARR[0][0] 
    cout<<*(ptr+1)<<endl;// HERE, *(PTR+1), HERE GO STEP BY STEP. FIRST, PTR POINTS TO STARTING OF FIRST 1D ARRAY ARR[0], THEN PTR+1 REPRESENTS STARTING OF ARITHMETICALLY NEXT 1D ARRAY OF ARR[1], THEN DEREFERENCING IT GIVES US ADDRESS TO FIRST ELEMENT OF SECOND 1D ARRAY ARR[1][0]
    cout<<**ptr<<endl; //HERE, FIRST PTR (FROM ABOVE), THEN *PTR (FROM ABOVE), THEN ** PTR REPRESENTS THE VALUR OF ARR[0][0]
    cout<<**(ptr+1)<<endl;// HERE, PTR+1 REPRESENTS STARTING OF SECOND 1D ARRAY, *(PTR+1) REPRESENTS ADDRESS OF FIRST ELEMENT OG SECOND 1D ARRAY, **(PTR+1) REPRESENTS ARR[1][0]
    cout<<*(*ptr+1)<<endl;// PTR -> *PTR -> *PTR+1 -> *(*PTR+1)
    cout<<*(*(ptr+1)+1)<<endl;// PTR ->PTR+1 -> *(PTR+1) -> *(PTR+1)+1 -> *(*(PTR+1)+1)
    cout<<*(*(ptr+1)+2)<<endl;
}