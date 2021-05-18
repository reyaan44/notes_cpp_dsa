#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll setBit(ll n, ll pos) // WE HAVE TO SET A BIT IN NUMBER N AT POSITION POS
{
    // 5 0101
    ll k = 1<<pos; // 0010 
    return (k|n); //0111     // BITWISE OR
}
ll getBit(ll n,ll pos) // WE HAVE TO GET THE BIT IN NUMBER N AT POSITION pos
{
    // 6 0110
    ll k = 1<<pos; //0100      
    return ((k & n)!=0); // TRUE      // BITWISE AND   
}
ll clearBit(ll n, ll pos) // WE HAVE TO CLEAR (MAKE 0) THE BIT OF N AT POSITION POS
{   
    // 6 0110
    ll k = 1<<pos; // 0100
    k = ~k; // 1011
    return (k & n);
}
ll updateBit(ll n, ll pos, ll value) // WE HAVE TO UPDATE (MAKE 1 OR 0 WHICH IS GIVEN IN VALUE) THE BIT OF N AT POSITION POS
{
    // IN UPDATE BIT, WE FIRST CLEAR BIT AND THEN SET BIT
    // 6 0100
    ll k = 1<<pos; // 0010
    k=~k; // 1101
    k=(k&n); // 0101
    // BIT CLEARED
    return (k | (value<<pos));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // IN BITS, POSITION STARTS FROM 0 FROM RIGHT SIDE
    ll n =5;
    ll pos = 1;
    cout<<setBit(n,pos)<<endl;
    n=6;
    pos=2;
    cout<<getBit(n,pos)<<endl;
    cout<<clearBit(n,pos)<<endl;
    n=5;
    pos=1;
    ll value = 1; // WE WANT TO SET VALUE 'VALUE' AT POSITION POS OF NUMBER N IN BITS
    cout<<updateBit(n,pos,value)<<endl;
    return 0;
}