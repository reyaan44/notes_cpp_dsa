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
    node(ll x)
    {
        data = x;
        left=NULL;
        right=NULL;
    }
}*root;
void create()
{
    cout<<"INSERT THE ROOT ELEMENT : ";
    ll x;
    cin>>x;
    root = new node(x);
    queue<node*> q1;
    q1.push(root);
    node* p = root;
    while(!q1.empty())
    {
        p = (q1.front());
        q1.pop();
        cout<<"ENTER THE LEFT CHILD OF "<<p->data<<" : ";
        ll y;
        cin>>y;
        if(y!=-1)
        {
            node* temp = new node(y);
            p->left = temp;
            q1.push(temp);
        }
        cout<<"ENTER THE RIGHT CHILD OF "<<p->data<<" : ";
        cin>>y;
        if(y!=-1)
        {
            node* temp = new node(y);
            p->right=temp;
            q1.push(temp);
        }
    }
}
void preorder(node* temp)
{
    if(temp==NULL)
    {
        return;
    }
    cout<<temp->data<<" ";
    preorder(temp->left);
    preorder(temp->right);
}
void iterativePreorder()
{
    node* temp = root;
    stack<node*> st;
    while(temp!=NULL || !st.empty())
    {
        if(temp!=NULL)
        {
            cout<<temp->data<<" ";
            st.push(temp);
            temp=temp->left;
        }
        else
        {
            node* temp1 = st.top();
            st.pop();
            temp=temp1->right;
        }
    }
}
void inorder(node* temp)
{
    if(temp==NULL)
    {
        return;
    }
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
}
void iterativeInorder()
{
    node* temp = root;
    stack<node*> st;
    while(temp!=NULL || !st.empty())
    {
        if(temp!=NULL)
        {
            st.push(temp);
            temp=temp->left;
        }
        else
        {
            node* temp1 = st.top();
            st.pop();
            cout<<temp1->data<<" ";
            temp = temp1->right;
        }
    } 
}
void postorder(node* temp)
{
    if(temp==NULL)
    {
        return;
    }
    postorder(temp->left);
    postorder(temp->right);
    cout<<temp->data<<" ";
}
void iterativePostorder()
{
    if (root == NULL) return;
    stack<node*> s1, s2;
    s1.push(root);
    node* temp;
    while (!s1.empty()) 
    {
        temp = s1.top();
        s1.pop();
        s2.push(temp);
        if (temp->left) s1.push(temp->left);
        if (temp->right) s1.push(temp->right);
    }
    while (!s2.empty()) 
    {
        temp = s2.top();
        s2.pop();
        cout<<temp->data<<" ";
    }
}
void levelOrderTraversal()      // WE ARE INSERTING A NULL EVERY TIME A LEVEL ENDS
{
    if(root==NULL) return;
    queue<node*> q1;
    node* temp = root;
    q1.push(root);
    q1.push(NULL);
    while(!q1.empty())
    {
        node* temp1 = q1.front();
        q1.pop();
        if(temp1!=NULL)
        {
            cout<<temp1->data<<" ";
            if(temp1->left) q1.push(temp1->left);
            if(temp1->right) q1.push(temp1->right);
        }  
        else if(!q1.empty())
        {
            q1.push(NULL);
        } 
    }
}
ll sumOfNodesAtKthLevel(ll k)
{
    ll level = 0, sum = 0;
    if(root==NULL) return 0;
    queue<node*> q1;
    node* temp = root;
    q1.push(root);
    q1.push(NULL);
    while(!q1.empty())
    {
        node* temp1 = q1.front();
        q1.pop();
        if(temp1!=NULL)
        {
            if(k==level)
            {
                sum+=temp1->data;
            }
            if(temp1->left) q1.push(temp1->left);
            if(temp1->right) q1.push(temp1->right);
        }
        else if(!q1.empty())
        {
            level++;
            q1.push(NULL);
        }
    }
    return sum;
}





ll countNumberOfNodes(node* temp)
{
    if(temp==NULL) return 0;
    return countNumberOfNodes(temp->left)+countNumberOfNodes(temp->right)+1;    // +1 IS THE THING WHICH INCREASES COUNT
}
/*
    TO FIND THE NUMBER OF LEAF NODES, 
    ADD ONE CONDITION
    if(temp==NULL) return 0;
    if(temp->left==NULL && temp->right==NULL)
    {
        return func(temp->left)+func(temp->right)+1;    THIS +1 IS THE ONLY THING FROM WHICH COUNT IS INCREASING
    }
    else
    {
        return func(temp->left)+func(temp->right); 
    }
*/
ll countSumOfNodes(node* temp)
{
    if(temp==NULL) return 0;
    return countSumOfNodes(temp->left)+countSumOfNodes(temp->right)+temp->data;
}





ll heightOfBinaryTree(node* temp)
{
    ll lsum=0,rsum=0;
    if(temp==NULL) return 0;
    lsum = heightOfBinaryTree(temp->left);
    rsum = heightOfBinaryTree(temp->right);
    return max(lsum,rsum)+1;
}
ll diameterOfBinaryTree(node* temp)   // O(N^2)  // DIAMETER OF BINARY TREE IS THE LONGEST POSSIBLE PATH IN THAT BINARY TREE BETWEEN ANY TWO NODES 
                                        // WE WILL TAKE A NODE, THEN WE WILL CHECK ITS LEFTSUBTREE HEIGHT+RIGHTSUBTREE HEIGHT + 1, THEN WE WILL ITERATE THROUGH EACH NODE AND FIND THE MAXIMUM FROM THE ANSWERS
{
    if(temp==NULL) return 0;
    ll lheight = heightOfBinaryTree(temp->left);
    ll rheight = heightOfBinaryTree(temp->right);
    ll curr = lheight+rheight+1;

    ll ldiameter = diameterOfBinaryTree(temp->left);
    ll rdiameter = diameterOfBinaryTree(temp->right);
    return max({ldiameter,rdiameter,curr});
}
ll diameterOfBinaryTreeOptimized(node* temp, ll *height)    // O(N) // HERE, HEIGHT IS ALSO BEING CALCULATED INSIDE IT ONLY
{
    ll lh=0,rh=0;
    ll ldiameter = 0,rdiameter = 0;
    if(temp==NULL)
    {
        *height = 0;
        return 0;
    }
    ldiameter = diameterOfBinaryTreeOptimized(temp->left, &lh);
    rdiameter = diameterOfBinaryTreeOptimized(temp->right, &rh);
    *height = max(lh,rh) + 1;

    return max({lh+rh+1,ldiameter,rdiameter});
}
int main()
{
    create();

    cout<<"PREORDER : "<<endl;
    preorder(root); cout<<endl;
    iterativePreorder(); cout<<endl;

    cout<<"INORDER : "<<endl;
    inorder(root); cout<<endl;
    iterativeInorder(); cout<<endl;

    cout<<"POSTORDER : "<<endl;
    postorder(root); cout<<endl;
    iterativePostorder(); cout<<endl;

    cout<<"LEVEL ORDER : "<<endl;
    levelOrderTraversal(); cout<<endl;

    cout<<"THE NUMBER OF NODES : "<<countNumberOfNodes(root)<<endl;

    cout<<"THE HEIGHT OF BINARY TREE : "<<heightOfBinaryTree(root)<<endl;

    cout<<"THE SUM OF NODES AT LEVEL K (IN THIS CASE LEVEL 1) : "<<sumOfNodesAtKthLevel(1)<<endl;

    cout<<"THE SUM OF ALL NODES : "<<countSumOfNodes(root)<<endl;

    cout<<"THE DIAMETER OF BINARY TREE : "<<diameterOfBinaryTree(root)<<endl;
    ll height = 0;
    cout<<"THE DIAMETER OF BINARY TREE (OPTIMIZED) : "<<diameterOfBinaryTreeOptimized(root,&height);
    return 0;
}