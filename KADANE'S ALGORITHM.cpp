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
    // KADANE'S ALGORITHM
    // TO FIND THE SUM OF VALUES OF SUBARRAYS OF A GIVEN ARRAY (KEEPING IN MIND THAT SUB ARRAY IS ALWAYS CONTINUOUS ARRAY, THE ONE WHICH IS NOT CONTINUOUS IS SEQUENTIAL ARRAY)
    // WITH TIME COMPLEXITY O(N) 
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0; i<n; i++)
    {
    	cin>>arr[i];
    }
    ll sum=0,maxsum=LLONG_MIN;
    for(ll i=0; i<n; i++)
    {
    	sum+=arr[i];
    	if(sum<0)
    	{
    		sum=0;
    	}
    	maxsum=max(sum,maxsum);
    }
    cout<<maxsum<<endl;
    return 0;
}