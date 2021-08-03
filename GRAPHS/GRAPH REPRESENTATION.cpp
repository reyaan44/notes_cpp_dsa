#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define endl "\n"
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,b) for(ll i=a; i<b; ++i)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;






void printAdjacencyMatrix(vector<vector<ll>> vect)
{
    cout<<"ADJACENCY MATRIX : "<<endl;
    for(ll i=0; i<vect.size(); i++)
    {
        for(ll j=0; j<vect[i].size(); j++)
        {
            cout<<vect[i][j]<<" ";
        }
        cout<<endl;
    }
}
void addEdgeAdjacencyMatrix(vector<vector<ll>> & vect, ll a,ll b)
{
    vect[a-1][b-1]=1;
    vect[b-1][a-1]=1;
}







void printAdjacencyList(vector<ll> a[], ll n)
{
    cout<<"ADJACENCY LIST : "<<endl;
    for(ll i=1; i<=n; i++)
    {
        cout<<i;
        for(auto itr = a[i].begin(); itr!=a[i].end(); itr++)
        {
            cout<<" -> "<<*itr;
        }
        cout<<endl;
    }
}
void addEdgeAdjacencyLists(vector<ll> a[], ll a1, ll a2)
{
    a[a1].push_back(a2);
    a[a2].push_back(a1);
}








int main()
{
    // THESE ARE ONLY FOR NON DIRECTING GRAPHS
    quick;
    ll n = 6; // TOTAL 6 EDGES
    vector<vector<ll>> vect(6,vector<ll> (6,0));    //  FIRST 6 IS ROW COUNT (VERTICAL), THEN AFTER THAT, IT IS COLUMN COUNT WITH DEFAULT VALUE 0 THAT CAN BE CHANGED
    addEdgeAdjacencyMatrix(vect,1,2);
    addEdgeAdjacencyMatrix(vect,1,3);
    addEdgeAdjacencyMatrix(vect,1,4);
    addEdgeAdjacencyMatrix(vect,2,3);
    addEdgeAdjacencyMatrix(vect,3,4);
    addEdgeAdjacencyMatrix(vect,3,6);
    addEdgeAdjacencyMatrix(vect,4,5);
    printAdjacencyMatrix(vect); cout<<endl<<endl<<endl;

    vector<ll> a[n+1];  // ARRAY OF VECTORS, array of vectors is two dimensional array with fixed number of rows where each row is vector of variable length. 
                        // Each index of array stores a vector which can be traversed and accessed using iterators.
                        // N+1 IS THE NUMBER OF ARRAYS AND EACH ARRAY STORES A VECTOR
    addEdgeAdjacencyLists(a,1,2);
    addEdgeAdjacencyLists(a,1,3);
    addEdgeAdjacencyLists(a,1,4);
    addEdgeAdjacencyLists(a,2,3);
    addEdgeAdjacencyLists(a,3,4);
    addEdgeAdjacencyLists(a,3,6);
    addEdgeAdjacencyLists(a,4,5);
    printAdjacencyList(a,n);
    return 0;
}