#include<bits/stdc++.h>
#define ll long long int
#define testcase ll t; cin>>t; while(t--)
#define endl "\n"
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,b) for(ll i=a; i<b; ++i)
using namespace std;
const ll M = 1000000007;
inline ll mod(ll x) {ll a1=(x%M); if(a1<0){a1+=M;} return a1;}
#define N 51
ll arrayMain[N][N];
ll I[N][N];
void mul(ll A[N][N], ll B[N][N], ll dim)
{
    ll res[N][N];
    for(ll i=0; i<dim; i++)
    {
        for(ll j=0; j<dim; j++)
        {
            res[i][j]=0;
            for(ll k=0; k<dim; k++)
            {
                res[i][j] += mod(mod(A[i][k]) * mod(B[k][j]));
                res[i][j] = mod(res[i][j]);
            }
        }
    }
    for(ll i=0; i<dim; i++)
    {
        for(ll j=0; j<dim; j++)
        {
            A[i][j] = res[i][j];
            A[i][j] = mod(A[i][j]);
        }
    }
}
void powerMatrix(ll dim, ll n)
{
    forl(i,0,dim)
    {
        forl(j,0,dim)
        {
            if(i==j) I[i][j]=1;
            else I[i][j]=0;
        }
    }
    while(n>0)
    {
        if(n%2)     // HERE IS THE MAGIC, THE MATRIX IS MULTIPLIED IN LOGN TIME.
        {
            mul(I,arrayMain,dim);
            n--;
        }
        else
        {
            mul(arrayMain,arrayMain,dim);
            n=n/2;
        }
    }
    for(ll i=0; i<dim; i++)
    {
        for(ll j=0; j<dim; j++)
        {
            cout<<mod(I[i][j])<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    testcase
    {
        ll m,n;
        cin>>m>>n;
        forl(i,0,m)
        {
            forl(j,0,m)
            {
                cin>>arrayMain[i][j];
            }
        }
        powerMatrix(m,n);
    }
    return 0;
} 