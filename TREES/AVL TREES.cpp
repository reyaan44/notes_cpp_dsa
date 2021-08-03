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
    ll data,height;
    node* left,*right;
    node()
    {
        data=-1,height=1;
        left=right=NULL;
    }
    node(ll key)
    {
        data=key;
        height=1;
        left=right=NULL;
    }
}*root;
ll height(node* temp)
{
    if(temp==NULL) return 0;
    return temp->height;
}
ll balanceFactor(node* temp)
{
    if(temp==NULL) return 0;
    return height(temp->left) - height(temp->right);
}
node* LLRotate(node* & p1)
{
    node* p2 = p1->left;
    node* p3 = p2->right;

    p2->right = p1;
    p1->left = p3;

    p1->height = 1 + max(height(p1->left),height(p1->right));
    p2->height = 1 + max(height(p2->left),height(p2->right));

    if(root==p1)
    {
        root=p2;
    }
    return p2;
}
node* RRRotate(node* & p1)
{
    node* p2 = p1->right;
    node* p3 = p2->left;

    p2->left = p1;
    p1->right = p3;

    p1->height = 1 + max(height(p1->left),height(p1->right));
    p2->height = 1 + max(height(p2->left),height(p2->right));

    if(p1==root)
    {
        root=p2;
    }
    return p2;
}
node* LRRotation(node* & p1)
{
    node *p2=p1->left;
    node *p3=p2->right;
    p2->right=p3->left;
    p1->left=p3->right;
    p3->left=p2;
    p3->right=p1;
    p2->height = 1 + max(height(p2->left),height(p2->right));
    p1->height = 1 + max(height(p1->left),height(p1->right));
    p3->height = 1 + max(height(p3->left),height(p3->right));
    if(root==p1) root=p3;
    return p3;
}
node* RLRotation(node* & p1)
{
    node* p2 = p1->right;
    node* p3 = p2->left;
    p2->left = p3->right;
    p1->right = p3->left;
    p3->right = p2;
    p3->left = p1;
    p2->height = 1 + max(height(p2->left),height(p2->right));
    p1->height = 1 + max(height(p1->left),height(p1->right));
    p3->height = 1 + max(height(p3->left),height(p3->right));
    if(root==p1) root=p3;
    return p3;
}
node* insert(node* p, ll key)
{
    if(p==NULL)
    {
        node* temp = new node(key);
        if(root==NULL) root=temp;
        return temp;
    }
    if(key<p->data) p->left=insert(p->left,key);
    else if(key>p->data) p->right=insert(p->right,key);
    else return p;

    p->height = 1 + max(height(p->left),height(p->right)); // UPDATE THE HEIGHT OF ANCESTOR NODE

    ll balance = balanceFactor(p);

    if(balance>1 && key<p->left->data)   // LL
    {
        return LLRotate(p);
    }
    else if(balance<-1 && key>p->right->data)    // RR
    {
        return RRRotate(p);
    }
    else if(balance>1 && key>p->right->data)     // LR  
    {
        return LRRotation(p);
    }
    else if(balance<-1 && key<p->right->data)    // RL
    {
        return RLRotation(p);
    }
    return p;
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
node* deleteNode(node* temp, ll key)
{
    if(temp==NULL) return NULL;
    if(key>temp->data) temp->right=deleteNode(temp->right,key);
    else if(key<temp->data) temp->left=deleteNode(temp->left,key);
    else
    {
        if(temp->left==NULL || temp->right==NULL)
        {
            node* p = (temp->left ? temp->left : temp->right);
            if(p==NULL)
            {
                p=temp;
                temp=NULL;
                delete p;
            }
            else
            {
                temp=p;
                delete p;
            }
        }
        if(temp==NULL) return NULL;
        if(height(temp->left)>height(temp->right))
        {
            node* inpre = InorderPredecessor(temp->left);
            temp->data = inpre->data;
            temp->left = deleteNode(temp->left,inpre->data);
        }
        else
        {
            node* insucc = InorderSuccessor(temp->right);
            temp->data = insucc->data;
            temp->right = deleteNode(temp->right,insucc->data);
        }
    }

    if(temp==NULL) return NULL;

    temp->height = 1 + max(height(temp->left),height(temp->right));

    ll balance = balanceFactor(temp);

    if(balance>1 && balanceFactor(temp->left)>=0)   // LL
    {
        return LLRotate(temp);
    }
    else if(balance<-1 && balanceFactor(temp->right)<=0)    // RR
    {
        return RRRotate(temp);
    }
    else if(balance>1 && balanceFactor(temp->left)<0)     // LR  
    {
        return LRRotation(temp);
    }
    else if(balance<-1 && balanceFactor(temp->right)>0)    // RL
    {
        return RLRotation(temp);
    }
    return temp;
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
    root=insert(root,10);
    insert(root,20);
    insert(root,30);
    insert(root,40);
    insert(root,50);
    insert(root,25);
    preorder(root); cout<<endl;

    root=deleteNode(root,50);
    preorder(root); cout<<endl;
    deleteNode(root,20);
    preorder(root); cout<<endl;
    return 0;
}