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
class node
{
public:
    node* left;
    ll data;
    node* right;
    node()
    {
        left = right = NULL;
        data=-1;
    }
    node(ll x)
    {
        left = right = NULL;
        data=x;
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
void levelOrderTraversal(node* temp)
{
    if(temp==NULL) return;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp1 = q.front();
        q.pop();
        if(temp1!=NULL)
        {
            cout<<temp1->data<<" ";
            if(temp1->left) q.push(temp1->left);
            if(temp1->right) q.push(temp1->right);
        }
        else if(!q.empty())
        {
            q.push(NULL);
        }
    }
    cout<<endl;
}
void inorderTraversal(node* temp)
{
    if(temp==NULL) return;
    inorderTraversal(temp->left);
    cout<<temp->data<<" ";
    inorderTraversal(temp->right);
}







void sumReplacement(node* temp)     // CHANGING THE DATA OF THE NODE WITH THE SUM OF ALL NODES OF SUBTREES AND ITSELF
{
    if(temp==NULL) return;
    sumReplacement(temp->left);
    sumReplacement(temp->right);
    if(temp->left != NULL) temp->data+=temp->left->data;
    if(temp->right != NULL) temp->data+=temp->right->data;
}
bool isBalanced(node* temp, ll *height) // A BINARY TREE IS BALANCED IF EVERY NODE'S HEIGHT OF LEFT AND RIGHT SUBTREE HAS DIFFERENCE LESS THAN OR EQUAL TO 1. ABS(LHEIGHT-RHEIGHT)<=1. 
{
    ll lh=0,rh=0;
    if(temp==NULL) return 1;
    if(isBalanced(temp->left, &lh)==false) return false;
    if(isBalanced(temp->right, &rh)==false) return false;
    *height = max(lh,rh)+1;
    if(abs(lh-rh)<=1) return 1;
    return 0;
}





bool getPath(node* temp, ll key, vector<ll> &path)
{
    if(temp==NULL) return false;
    path.push_back(temp->data);
    if(temp->data==key) return 1;
    if(getPath(temp->left, key, path) || getPath(temp->right, key, path))
    {
        return true;
    }
    path.pop_back();
    return 0;
}
ll lowestCommonAncestor(node* temp, ll n1, ll n2)
{
    vector<ll> path1,path2;
    if(!getPath(temp,n1,path1) || !getPath(temp,n2,path2))
    {
        return -1;      // NO PATH EXIST FROM ROOT, WRONG NODES
    }
    ll pc;
    for(pc=0; pc<min(path1.size(),path2.size()); pc++)
    {
        if(path1[pc]!=path2[pc])
        {
            break;
        }
    }
    return path1[pc-1];
}
node* lowestCommonAncestorSecondMethod(node* temp, ll n1, ll n2)
{
    if(temp==NULL) return NULL;
    if(temp->data==n1 || temp->data==n2)
    {
        return temp;
    }
    node* LLCA = lowestCommonAncestorSecondMethod(temp->left,n1,n2);
    node* RLCA = lowestCommonAncestorSecondMethod(temp->right,n1,n2);

    if(LLCA && RLCA) return temp;       // IT WILL SHOW THE ANSWER OF THE LOWEST COMMON ANCESTOR AS IT IS THE NODE WHICH CONNECTED BOTH OF THEM AND RETURN WILL GET US TO THAT
    if(LLCA) return LLCA;
    return RLCA;
}






ll findDistanceBetweenRootAndNode(node* temp, ll key, ll dis)
{
    if(temp==NULL) return -1;
    if(temp->data==key)
    {
        return dis;
    }
    ll ldis = findDistanceBetweenRootAndNode(temp->left,key,dis+1);
    if(ldis!=-1) return ldis;
    ll rdis = findDistanceBetweenRootAndNode(temp->right,key,dis+1);
    if(rdis!=-1) return rdis;
    return -1;
}
ll ShortestDistanceBetweenTwoNodes(node* temp, ll n1, ll n2)
{
    if(temp==NULL) return -1;
    node* lca = lowestCommonAncestorSecondMethod(temp,n1,n2);
    ll d1 = findDistanceBetweenRootAndNode(lca,n1,0);
    ll d2 = findDistanceBetweenRootAndNode(lca,n2,0);
    return d1+d2;
}




void flattenTheBinaryTree(node* temp)
{
    if(temp==NULL || (temp->left==NULL && temp->right==NULL)) return;
    if(temp->left)
    {
        flattenTheBinaryTree(temp->left);
        node* rightFirst = temp->right;
        temp->right = temp->left;
        temp->left=NULL;
        node* rtail = temp;
        while(rtail->right!=NULL)
        {
            rtail=rtail->right;
        }
        rtail->right = rightFirst;
    } 
    flattenTheBinaryTree(temp->right);
}




ll maximumPathSumUti(node* temp,ll &ans)
{
    if(temp==NULL) return 0;
    ll leftsum = maximumPathSumUti(temp->left,ans);
    ll rightsum = maximumPathSumUti(temp->right,ans);

    ll nodeMax = max({temp->data,temp->data+leftsum,temp->data+rightsum,temp->data+leftsum+rightsum});
    ans = max(ans,nodeMax);

    ll sum = max({temp->data,temp->data+leftsum,temp->data+rightsum});
    return sum; //    THIS IS FOR SINGLE SIDES, NOT COMPLTEE PATH
}
ll maximumPathSum(node* temp)
{
    ll ans = LLONG_MIN;
    maximumPathSumUti(temp,ans);
    return ans;
}
int main()
{
    create();
    levelOrderTraversal(root);
    // sumReplacement(root);    // IT IS CORRECT, JUST INTERRUPTING
    levelOrderTraversal(root);

    ll height = 0;
    if(isBalanced(root,&height)) cout<<"BALANCED TREE"<<endl;
    else cout<<"UNBALANCED TREE"<<endl;

    cout<<"LOWEST COMMON ANCESTOR : "<<lowestCommonAncestor(root,7,6)<<endl;

    cout<<"SHORTEST DISTANCE BETWEEN TWO NODES : "<<ShortestDistanceBetweenTwoNodes(root,6,7)<<endl;

    inorderTraversal(root); cout<<endl;
    // flattenTheBinaryTree(root);  // IT IS CORRECT, JUST INTERRUPTING
    inorderTraversal(root); cout<<endl;

    cout<<"MAXIMUM SUM : "<<maximumPathSum(root)<<endl;
    return 0;
}