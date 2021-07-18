#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define precision(a) cout<<fixed<<setprecision(a)
#define testcase ll t; cin>>t; while(t--)
#define endl "\n"
#define iendl "\n", cout.flush // FOR INTERACTIVE PROBLEMS
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,b) for(ll i=a; i<b; ++i)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;
const ll M = 1000000007;
ll mod(ll x)
{
    return (x%M + M)%M;
}
vector<ll> vect(1,-1);          // IT ACTS LIKE A COMPLETE BINARY TREE, MEANS NO SPACE BETWEEN ANY ELEMENTS IN VECTOR, ONLY LEAF NODES WILL HAVE DEGREE<2 AND IN THEM ALSO IT WILL HAVE THE TREE FILLED FROM LEFT SIDE.  
void insertInHeap(ll x)         // WE FIRST INSERT IN THE ARRAY, THEN COMPARE IT WITH ITS PARENT AND ITS PARENT TILL ROOT AT I=1
{
    vect.push_back(x);
    ll i = vect.size()-1;
    while(i>1 && vect[i/2]<vect[i])
    {
        swap(vect[i/2],vect[i]);
        i=i/2;
    }
}
void deleteInHeap()             // ONLY ROOT ELEMENT CAN BE DELETED, AND AS IT IS A MAXHEAP, IT WILL HAVE THE MAXIMUM OF ALL THE NUMBERS, WE DEETE AND SWAP IT WITH 
                                // LAST ELEMENT IN ARRAY, THEN WE ADJUST THE NEW ROOT INTO THE ARRAY BY CHECKING ITS LEFT AND RIGHT CHILD AND REPLACING WITH WHICHEVER IS 
                                // THE BIGGEST, AND WE WILL ADJUST IT IN ARRAY AND SO ON...
{
    static ll size = vect.size()-1;
    ll x = vect[1];
    swap(vect[1],vect[size]);
    size--;
    ll i = 1;
    ll j = i*2;
    while(j<size)
    {
        if(vect[j+1]>vect[j]) j++;
        if(vect[i]<vect[j])
        {
            swap(vect[i],vect[j]);
            i=j;
            j=j*2;
        }
        else
        {
            break;
        }
    }
}
void printHeap()
{
    for(ll i=1; i<vect.size(); i++)
    {
        cout<<vect[i]<<" ";
    }
    cout<<endl;
}







void heapify(ll arr[], ll n, ll i)  // THIS FUNCTION IS ONLY FOR A SINGLE SUBTREE
{
    ll leftTree = i*2+1;
    ll rightTree = i*2+2;
    ll largest = i;     // ROOT OF THE SUBTREE

    if(leftTree<n && arr[largest]<arr[leftTree])
    {
        largest = leftTree;
    }
    if(rightTree<n && arr[largest]<arr[rightTree])
    {
        largest = rightTree;
    }
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);  // IF WE MADE ANY CHANGES, SWAP AND AGAIN CALL THE FUNCTION.
        heapify(arr,n,largest);
    }

}
void heapSort(ll arr[], ll n)
{
    for(ll i = (n/2)-1; i>=0; i--)  // FOR MAKING A MAX HEAP ONCE, RUNNING A FOR LOOP FOR EACH OF ITS SUBTREE OTHER THAN LEAF NODES
                                    // (N/2)-1 IS THE FIRST NODE IN THE ARRAY OR HEAP OR BINARY TREE WHICH IS NOT A LEAF NODE 
    {
        heapify(arr,n,i);
    }
    for(ll i=n-1; i>=0; i--)        // STORING IN THE LAST ELEMENTS THE BIGGEST NUMBER
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);           // HEAPIFY WITH I=0 BECAUSE ONLY THE ROOT IS DISTURBED
    }

}
int main()
{
    insertInHeap(4);
    insertInHeap(5);
    insertInHeap(10);
    insertInHeap(8);
    insertInHeap(7);
    insertInHeap(14);
    insertInHeap(13);
    printHeap();
    for(ll i=1; i<vect.size(); i++) // THIS IS MAKING THE ARRAY SORTED IN O(N*LOGN) TIME
    {
        deleteInHeap();
    }
    printHeap();

    ll arr[7]={3,1,5,2,9,6,4};
    cout<<endl;
    cout<<"BEFORE SORT : ";
    for(ll i=0; i<7; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapSort(arr,sizeof(arr)/sizeof(arr[0]));
    cout<<"AFTER SORT : ";
    for(ll i=0; i<7; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}