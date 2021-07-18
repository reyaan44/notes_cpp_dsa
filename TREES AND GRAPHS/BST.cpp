#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define precision(a) cout<<fixed<<setprecision(a)
#define testcase ll t; cin>>t; while(t--)
#define endl "\n"
#define iendl "\n", cout.flush // FOR INTERACTIVE PROBLEMS
#define forl(i,a,b) for(ll i=a; i<b; ++i)
using namespace std;
class node
{
public:
    ll data;
    node* left;
    node* right;
    node()
    {
        left=right=NULL;
        data=-1;
    }
    node(ll x)
    {
        left=right=NULL;
        data=x;
    }
};





bool searchIterative(node* temp, ll key);
void insert(node* & root, ll x)
{
    node* temp = new node(x);
    if(root==NULL)
    {
        root=temp;
        return;
    }
    node* p = root;
    if(searchIterative(root,x))
    {
        cout<<"NODE ALREADY INSIDE TREE"<<endl;
        return;
    }
    while(1)
    {
        if(p->data>x)
        {
            if(p->left) p=p->left;
            else
            {
                p->left=temp;
                break;
            }
        }
        else
        {
            if(p->right) p=p->right;
            else
            {
                p->right=temp; 
                break;
            } 
        }
    }
}





ll heightOfBST(node* temp)
{
    if(temp==NULL) return 0;
    ll a1 = heightOfBST(temp->left);
    ll a2 = heightOfBST(temp->right);
    return max(a1,a2)+1;
}
node* InorderPredecessor(node* temp)
{
    while(temp && temp->right)
    {
        temp=temp->right;
    }
    return temp;
}
node* InorderSuccessor(node* temp)
{
    while(temp && temp->left)
    {
        temp=temp->left;
    }
    return temp;
}
void deleteNode(node* & temp, node* & root, ll key)
/*
CASE 1 : DELETING LEAF NODE : JUST FREE IT FROM MEMORY
CASE 2 : HAS ONE CHILD : ITS ONE CHILD WILL REPLACE THAT NODE AND THE REST SUBTREE OF THAT CHILD REMAINS INTACT 
CASE 3 : HAS TWO CHILD : CHECK THE HEIGHT OF LEFT(HAS INORDER PREDECESSOR) AND RIGHT(HAS INORDER SUCCESSOR) SUBTREES AND WHICHEVER IS BIGGER, WE JUST REPLACE BOTH THE NODES AND RUN THE DELETE AGAIN FOR THE REPLACES NODE WHICH IS NOW PREDECESSOR OR SUCCESSOR
*/
{
    if(temp==NULL) return;
    if(temp->left==NULL && temp->right==NULL && temp->data==key)
    {
        if(temp==root)
        {
            root=NULL;
            return;
        }
        temp=NULL;
        delete temp;
        return;
    }
    if(key<temp->data)
    {
        deleteNode(temp->left,root,key);
    }
    else if(key>temp->data)
    {
        deleteNode(temp->right,root,key);
    }
    else
    {
        if(heightOfBST(temp->left)>heightOfBST(temp->right))
        {
            node* inpre = InorderPredecessor(temp->left);
            temp->data = inpre->data;
            deleteNode(temp->left,root,inpre->data);
        }
        else
        {
            node* insucc = InorderSuccessor(temp->right);
            temp->data = insucc->data;
            deleteNode(temp->right,root,insucc->data);
        }
    }
}





bool searchReccursive(node* temp, ll key)
{
    if(temp==NULL) return false;
    if(temp->data==key) return 1;
    if(temp->data>key) return searchReccursive(temp->left,key);
    return searchReccursive(temp->right,key);
}
bool searchIterative(node* temp, ll key)
{
    while(temp!=NULL)
    {
        if(temp->data==key) return 1;
        if(temp->data>key) temp=temp->left;
        else temp=temp->right;
    }
    return 0;
}






bool isValidBST(node* temp, node* maxAllowed, node* minAllowed)
{
    if(temp==NULL) return 1;
    if(minAllowed!=NULL && temp->data<=minAllowed->data) return 0;
    if(maxAllowed!=NULL && temp->data>=maxAllowed->data) return 0;
    bool leftSubTree =  isValidBST(temp->left,temp,minAllowed);
    bool rightSubTree = isValidBST(temp->right,maxAllowed,temp);
    return (leftSubTree && rightSubTree);
}








void printZigZag(node* temp)
{
    if(root==NULL) return;
    stack<node*> currLevel;
    stack<node*> nextLevel;
    bool LeftToRight = 1;
    currLevel.push(temp);
    while(!currLevel.empty())
    {
        node* p = currLevel.top();
        currLevel.pop();
        
        if(p)
        {
            cout<<p->data<<" ";
            if(LeftToRight)
            {
                if(p->left) nextLevel.push(p->left);
                if(p->right) nextLevel.push(p->right);
            }
            else
            {
                if(p->right) nextLevel.push(p->right);
                if(p->left) nextLevel.push(p->left);
            }
        }

        if(currLevel.empty())
        {
            LeftToRight=!LeftToRight;
            swap(nextLevel,currLevel);
        }
    }
}





void inorder(node* temp)
{
    if(temp==NULL) return;
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
}
int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    node* root;
    insert(root,30);
    insert(root,20);
    insert(root,50);
    insert(root,12);
    insert(root,40);
    insert(root,25);
    insert(root,100);


    inorder(root); cout<<endl;


    if(searchReccursive(root,12)) cout<<"FOUND IN TREE"<<endl;
    else cout<<"NOT FOUND"<<endl;
    if(searchReccursive(root,10000)) cout<<"FOUND IN TREE"<<endl;
    else cout<<"NOT FOUND"<<endl;

    if(searchIterative(root,12)) cout<<"FOUND IN TREE"<<endl;
    else cout<<"NOT FOUND"<<endl;
    if(searchIterative(root,10000)) cout<<"FOUND IN TREE"<<endl;
    else cout<<"NOT FOUND"<<endl;

    cout<<"HEIGHT OF BST : ";
    cout<<heightOfBST(root)<<endl;

    deleteNode(root,root,40);
    inorder(root); cout<<endl;
    deleteNode(root,root,20);
    inorder(root); cout<<endl;

    if(isValidBST(root,NULL,NULL)) cout<<"VALID BST"<<endl;
    else cout<<"NOT A VALID BST"<<endl;

    printZigZag(root); cout<<endl;
    return 0;
}