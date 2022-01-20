#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool comp(int x, int y)// This “comparator” function returns a value; convertible to bool, which basically tells us whether the passed “first” argument should be placed before the passed “second” argument or not. 
{
    int count1 =0, count2=0;
    while(x>0)
    {
        x/=10;
        count1++;
    }
    while(y>0)
    {
        y/=10;
        count2++;
    }
    return count1>count2;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int arr[]={432,556,4221,67,4,67890};
    int n= sizeof(arr)/sizeof(arr[0]);
    cout<<"BEFORE SORT : ";
    for (int i = 0; i < n; i++)
       {
           cout<<arr[i]<<" ";
       }   
       cout<<endl;
       sort(arr,arr+n,comp);
       cout<<"AFTER SORT : ";
    for (int i = 0; i < n; i++)
       {
           cout<<arr[i]<<" ";
       }   
    return 0;
}