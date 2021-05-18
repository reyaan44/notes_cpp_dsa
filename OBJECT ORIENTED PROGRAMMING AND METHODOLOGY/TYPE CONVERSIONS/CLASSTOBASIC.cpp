#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class data
{
    ll x;
    float f;
    public:
        data()              // DEFAULT CONSTRUCTOR
        {
            x=0;
            f=0;
        }
        data(float m)       // PARAMETERIZED CONSTRUCTOR
        {
            x=2;
            f=m;
        }
        operator float();       // OVERLOADING CASTING OPERATOR OF FLOAT // THESE ARE NECESSARY TO CONVERT CLASS INTO BASIC
        operator ll()           // OVERLOADING CASTING OPERATOR OF LONG LONG INT
        {
            return x*x;           // RETURNING X*X FROM THE DATA MEMBER
        }
        void show()
        {
            cout<<"x : "<<x<<" f : "<<f<<endl;
        }
};
data :: operator float()        // A WAY TO SHOW HOW OVERLOADING CASTING OPERATOR CAN BE DEFINED OUTSIDE THE CLASS
{
    return f;               // RETURNING THE VALUE OF F FROM THE DATA MEMBER
}
int main()
{
    ll j;               // INITIALIZING A NORMAL LL DATA TYPE
    float f1;
    data a;             // MAKING OBJECT AND INVOKING DEFAULT CONSTRUCTOR MAKING X=0,F=0
    a.show();           // X=0,F=0
    a=5.5;              // INVOKING PARAMETERIZED CONSTRUCTOR MAKING X=2,F=5.5
    a.show();           // X=2,F=5.5
    j=a;                // HERE J IS A LL DATA TYPE AND A IS AN OBJECT OF A CLASS, HERE J=A INVOKES THE OVERLOADING CASTING OPERATOR OF LONG LONG INT AND ASSIGNS J = X*X, BECOZ X*X WAS RETURNED
    a.show();           // X=2,F=5.5
    cout<<j<<endl;      // J=4
    f1=a;               // HERE, F1 = A INVOKES OVERLOADING CASTING OPERATOR OF FLOAT AND ASSIGNS F1 = F
    cout<<f1<<endl;     // F1 = 5.5
    a.show();           // X=2,F.5.5
    cout<<"j : "<<j<<" f1 :"<<f1;       // J=4, F=5.5
    return 0;
}

// vector :: operator double()          // HERE, IMAGINE A FUNCTION VECTOR WITH OVERLOADING CASTING OPERATOR DOUBLE
// {
//     double sum = 0;
//     for(ll i=0; i<size; i++)         // FINDING THE MOD/MAGNITUDE OF A VECTOR
//     {
//         sum+=(v[i]*v[i]);
//     }
//     return sqrt(sum);
// }

// double length = V1;              // HERE, V1 IS AN OBJECT OF CLASS VECTOR AND MOD/MAGNIUDE OF VECTOR WILL BE STORED IN A VARABLE LENGTH.

// THIS EXAMPLE IS FOR BETTER UNDERSTANDING....