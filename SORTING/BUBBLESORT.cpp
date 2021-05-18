#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void bubbleSort(ll arr[], ll n)
{
	for(ll i=0; i<n-1; i++)
    {
    	for(ll j=0; j<n-1-i; j++)
    	{
    		if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
    	}
    }
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    ll arr[]={2,5,1,57,11,89,3445,112,3};
    ll n=sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    for(ll i=0; i<n; i++)
    {
    	cout<<arr[i]<<" ";
    }    
	return 0;
}



/* 1.BUBBLE SORT
   2. FUNCTION
   3. COMP
*/