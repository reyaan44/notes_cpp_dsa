#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define precision(a) cout<<fixed<<setprecision(a)
#define testcase ll t; cin>>t; while(t--)
#define endl "\n"
#define iendl "\n", cout<<flush // FOR INTERACTIVE PROBLEMS
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,b) for(ll i=a; i<b; ++i)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;
const ll M = 1000000007;
ll mod(ll x)
{
    return (x%M + M)%M;
}
class node
{
public:
    node* left;
    ll data;
    node* right;
    node()
    {
        data=-1;
        left=NULL;
        right=NULL;
    }
    node(ll a)
    {
        data=a;
        left=NULL;
        right=NULL;
    }
} *root, *root1;
ll search(ll in[], ll start, ll end, ll key)        // SEARCHING THE VALUE OF PREORDER IN THE INORDER
{
    for(ll i=start; i<=end; i++)
    {
        if(in[i]==key) return i;
    }
    return -1;
}





node* buildTree(ll in[], ll pre[], ll start, ll end)    // INORDER AND PREORDER
{
    static ll preIndex=0;
    if(start>end) return NULL;          // BASE CONDITION
    node* temp = new node(pre[preIndex++]);
    if(start==end) return temp;         // BASE CONDITION
    ll Inindex = search(in,start,end,temp->data);
    temp->left = buildTree(in,pre,start,Inindex-1);     // MOVING ONE STEP AHEAD IN PREORDER AND FINDING THEPOSITION OF THAT ELEMENT IN INORDER, THE LEFT ELEMENTS TO THAT ELEMENT IN INORDER IS IN THE LEFT SUBTREE OF THAT ELEMENT AND THE RIGHT ELEMENTS TO THAT ELEMENT IN INORDER IS IN THE RIGHT SUBTREE
    temp->right = buildTree(in,pre,Inindex+1,end);
    return temp;
}



// WE CAN MAKE A BINARY TREE WITH PREORDER AND POSTORDER ONLY IF THE TREE IS A FULL BINARY TREE



node* buildTree1(ll in[], ll post[], ll start, ll end)      // INORDER AND POSTORDER
{
    static ll postorderIndex = 7-1;     // LENGTH - 1
    if(start>end) return NULL;
    node* temp = new node(post[postorderIndex--]);
    if(start==end) return temp;
    ll Inindex = search(in,start,end,temp->data);           
    temp->right = buildTree1(in,post,Inindex+1,end);        // NOTICE CHANGE // FIRST WE WEILL DO RIGHT SUBTREE
    temp->left = buildTree1(in,post,start,Inindex-1);       // NOTICE CHANGE
    return temp;
}







void postorder(node* temp)
{
    if(temp==NULL) return;
    postorder(temp->left);
    postorder(temp->right);
    cout<<temp->data<<" ";
}
void preorder(node* temp)
{
    if(temp==NULL) return;
    cout<<temp->data<<" ";
    preorder(temp->left);
    preorder(temp->right);
}
int main()
{
    ll pre[7] = {1,2,4,5,3,6,7};
    ll in[7] = {4,2,5,1,6,3,7};
    root = buildTree(in,pre,0,6);
    postorder(root); cout<<endl;
    // BOTH THESE CAN BE MADE OPTIMAL BY USING MAP IN PLACE OF SEARCHING, JUST ITERATE ONCE AND PLACE ALL THE INDEX OF THE INORDER IN THE MAP CORRESPONDING TO THEIR VALUES, THEN JUST CALL THE VALUE OF MAP TO GET ITS INDEX
/*
    unordered_map<ll,ll> m;
    for(ll i=0; i<7; i++)
    {
        m[in[i]]=i;
    }

    AND WHILE IN PLACE OF SEARCH, 
    ll inIndex = m[temp->data];
*/    
    ll in1[7] = {4,2,5,1,6,3,7};
    ll post1[7] = {4,5,2,6,7,3,1};
    root1 = buildTree1(in1,post1,0,6);
    preorder(root1); cout<<endl;
    return 0;
}