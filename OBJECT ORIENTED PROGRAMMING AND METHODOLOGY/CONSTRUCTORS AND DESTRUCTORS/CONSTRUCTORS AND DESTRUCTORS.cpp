#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class reyaan     // CLASS EXPLAINING ABOUT CONSTRUCTOR OVERLOADING, COPY CONSTRUCTOR, AND DEFAULT CONSTRUCTOR
{
    ll a,b;
public:
    reyaan(){}      // HERE, THIS DEFAULT CONSTRUCTOR IS NECESSARY IF WE DECLARE ANY OTHER CONSTRUCTOR
                    // BECAUSE BEFOR THIS, COMPILER USED IT IMPLICITLY, BUT AFTER DECLARING ANY OTHER CONSTRUCTOR
                    // IT IS NECESSARY TO DEFINE A DEFAULT CONSTRUCTOR

    reyaan(ll w)    // PARAMETERIZED CONSTRUCTOR
    {
        a=w;
        b=20;
    }
    reyaan(reyaan & i) // COPY CONSTRUCTOR, HERE REFERNECE OF CLASS IS COMPULSARY
    {
        a=i.a;   // NEED TO DEFINE FOR EVERY DATA MEMBER
        b=i.b;
    }
    void display()
    {
        cout<<a<<endl;
        cout<<b<<endl;
    }
};




// DESTRUCTOR IS CALLED IN A CLASS WHEN A SCOPE OF AN OBJECT ENDS {}





class reyaan1   // CLASS EXPLAINING DYNAMIC MEMORY ALLOCATION, DECLARING MEMORY IN CONSTRUCTOR IN HEAP SAVES
                // MEMORY
{
  ll *p;        // POINTER
  ll odd=0,even=0;
public:
  reyaan1()
  {
    p = new ll[5]; 
    for (ll i=0; i<5; i++)
    {
        cout<<"INPUT AN INTEGER : ";
        cin>>*(p+i);
        if((*(p+i))%2==0) even++;
        else odd++;
    }
    cout<<"THE NUMBER OF EVEN INTEGERS ARE = "<<even<<endl;
    cout<<"THE NUMBER OF ODD INTEGERS ARE = "<<odd<<endl;
  }
  ~reyaan1()        // DESTRUCTOR IS CALLED BY COMPILER IMPLICITLY DELETING OBJECTS IF THEY GO OUT OF 
                    // SCOPE, BUT HERE IF NEW IS USED, WE NEED TO CALL DESTRUCTOR EXPLICITLY TO DELETE
                    // THE MEMORY STORED IN HEAP TO FREE IT UP FOR FUTURE USE.
  {
    cout<<endl;
    cout<<"THE DESTRUCTOR IS CALLED"<<endl;
    delete[] p;
  }
};







class matrix
{
    ll **p;       // DECLARING LIKE THIS BECAUSE P[M][N] WILL GIVE ERROR AS THEY AS UNDEFINED
    ll m,n;
public:
    matrix(){}
    matrix(ll,ll);
    void store_value(ll,ll,ll);
    ~matrix()                           // DESTRUCTOR CALLED
    {
        cout<<"DESTRUCTOR CALLED"<<endl;
        for(ll i=0; i<m; i++)
        {
            delete p[i];        // COLUMS DELETED
            delete p;           // ROWS DELETED
                                // ALWAYS DELETED IN REVERSE ORDER OF DECLARATION
        }
    }
    ll get_value(ll,ll);
    void display();
};
void matrix :: display()        
{
    for(ll i=0; i<m; i++)
    {
        for(ll j=0; j<n; j++)
        {
            cout<<get_value(i,j)<<" ";
        }
        cout<<endl;
    }
}
ll matrix :: get_value(ll row, ll column)
{
    return p[row][column];
}
void matrix :: store_value(ll row, ll column, ll value)
{
    p[row][column]=value;
}
matrix :: matrix (ll x, ll y)   // CONSTRUCTOR CALLED
{
    m=x;
    n=y;
    p = new ll *[m];
    for(ll i=0; i<n; i++)
    {
        p[i] = new ll[n]; 
    }
    for(ll i=0; i<m; i++)
    {
        for(ll j=0; j<n; j++)
        {
            ll value;
            cout<<"ENTER VALUE : ";
            cin>>value;
            store_value(i,j,value);
        }
    }
}












int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    //REYAAN
    reyaan q;   // CALLING DEFAULT CONSTRUCTOR
    q.display();
    reyaan z(100); // CALLING PARAMETERIZED CONSTRUCTOR
    z.display();
    reyaan t(z);  // CALLING COPY CONSTRUCTOR AND PASSING OBJECT AS AN ARGUMENT
    t.display();
    reyaan g;    
    g=t;           // ALL THE VALUES CORRESPONDING TO DATA MEMBERS OF OBJECT T ARE COPIED TO ALL DATA MEMBERS
                   // OF OBJECT G.
    g.display();
    // REYAAN

    // REYAAN1
    reyaan1 a;
    //REYAAN1

    // MATRIX
    cout<<"ENTER M AND N : ";
    ll m,n;
    cin>>m>>n;              // ROW M AND COLUMN N
    matrix b(m,n);          
    b.display();    
    // MATRIX
    return 0;
}