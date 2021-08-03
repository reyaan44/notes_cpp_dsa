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
class Graph
{
public:
    map<ll,vector<ll>> adj;     // ADJACENCY LIST
    map<ll,bool> visited;       // VISITED MAP 
    ll connectedComponents = 0;
    void addEdge(ll a,ll b)
    {
        visited[a]=0;
        visited[b]=0;
        adj[a].push_back(b);    // IF GRAPH IS UNDIRECTED, THEN WE DO BOTH SIDES, EG. A-B 
        adj[b].push_back(a);    // BUT IF WE HAVE AN UNDIRECTED GRAPH, EG. A->B, WE WILL ONLY PUSH B IN THE A'S LIST, WE WONT DO THE SAME FOR B, AS WE CAN ONLY FIND B FROM A, NOT VICE-VERSA
    }





    void DFS()  // THIS IS NECESSARY SO THAT DISCONNECTED GRAPH CAN ALSO BE INCLUDED IN DFS.
    {
        connectedComponents = 0;
        for(auto itr=visited.begin(); itr!=visited.end(); itr++)    // IN CASE USED MULTIPLE TIMES
        {
            visited[itr->first]=0;
        }
        for(auto itr = visited.begin(); itr!=visited.end(); itr++)
        {
            if(itr->second==0)
            {
                DFSMAIN(itr->first);
                connectedComponents++;
            }
        }
        cout<<endl;
    }
    void DFSMAIN(ll a)  // IF GRAPH IS CONNECTED, WE CAN JUST CALL THIS FUNCTION WITH OUR DESIRED ROOT NODE A
    {
        visited[a]=true;
        cout<<a<<" ";
        for(auto itr = adj[a].begin(); itr!=adj[a].end(); itr++)
        {
            if(!visited[*itr])
            {
                DFSMAIN(*itr);
            }
        }
    }





    ll numberOfConnectedComponents()    // THIS CAN BE FOUND WITH DFS OR BFS, WITH INCREASING THE COUNT BY 1 IF A NODE IS MISSING AFTER TRAVERSING ALL THE CONNECTED NODES OF PREVIOUSLY SELECTED NODE
    {
        return connectedComponents;
    }




    void BFS()  
    {
        for(auto itr=visited.begin(); itr!=visited.end(); itr++)
        {
            visited[itr->first]=0;
        }
        for(auto itr = visited.begin(); itr!=visited.end(); itr++)
        {
            if(itr->second==0)
            {
                BFSMAIN(itr->first);
            }
        }
        cout<<endl;
    }
    void BFSMAIN(ll a)  // BASICALLY, BFS = LEVEL ORDER TRAVERSAL
    {
        queue<ll> q1;
        q1.push(a);
        visited[a]=true;

        while(!q1.empty())
        {
            a = q1.front();
            cout<<a<<" ";
            q1.pop();
            for(auto itr = adj[a].begin(); itr!=adj[a].end(); itr++)
            {
                if(!visited[*itr])
                {
                    visited[*itr]=1;
                    q1.push(*itr);
                }
            }
        }
    }
};
int main()
{
    Graph g1;
    g1.addEdge(0, 1);
    g1.addEdge(0, 9);
    g1.addEdge(1, 2);
    g1.addEdge(2, 0);
    g1.addEdge(2, 3);
    g1.addEdge(9, 3);
    g1.addEdge(4, 5);
    cout<<"DFS : ";
    g1.DFSMAIN(2); cout<<endl; // DFS CONSIDERING NODE 2 AS ROOT VERTEX, 4 AND 5 NOT INCLUDED BECAUSE DISCONNECTED, TO INCLUDE DISCONNECTED GRAPHS, WE MUST DO DFS, NOT DFSMAIN  
    cout<<"DFS : ";
    g1.DFS();
    
    cout<<"TOTAL NUMBER OF CONNECTED COMPONENTS IN THE ABOVE GRAPH : "<<g1.numberOfConnectedComponents()<<endl;

    Graph g2;
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(0, 7);
    g2.addEdge(7, 5);
    g2.addEdge(1, 2);
    g2.addEdge(2, 0);
    g2.addEdge(2, 3);
    g2.addEdge(3, 3);
    g2.addEdge(4, 6);
    cout<<"BFS : ";
    g2.BFSMAIN(2); cout<<endl;
    cout<<"BFS : ";
    g2.BFS();

    return 0;
}