#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Time
{
    ll hrs,min;
    public:
        Time(ll h,ll m)
        {
            hrs=h;
            min=m;
        }
        Time()
        {
            cout<<"Time's Object Created"<<endl;
        }
        ll getMinutes()                 // TOTAL MINUTES ARE CALCULATED AND RETURNED
        {
            ll tot_min = ( hrs * 60 ) + min;
                        return tot_min;
        }
        void display()
        {
            cout<<"Hours: "<<hrs<<endl ;
                        cout<<"Minutes : "<<min <<endl ;
        }
};
class Minute
{
    ll min;
    public:
    Minute()
    {
        min = 0;
    }
    void operator=(Time T)          // OPERATOR OVERLOADED WITH '=' OPERATOR
    {
        min=T.getMinutes();         // T.GETMINUTES() IS PUBLIC AND IT RETURNS THE VALUES IN TOTAL MINUTES
    }
    void display()
    {
        cout<<"Total Minutes : " <<min<<endl;
    }
};
int main()
{
    Minute obj;
    obj.display();
    Time a(2,10);
    a.display();
    obj = a;            // HERE, OBJ IS OBJECT OF MINUTE CLASS, AND A IS OBJECT OF TIME CLASS, OBJ = A IS SAME AS X OP Y, WHICH CALLS OPERATOR OVERLOADED FUNCTIONS AS X.OP(Y) IN CASE OF MEMBER FUNCTIONS
                        // SO, HERE, WE CALL OPERATOR OVERLOADED FUNCTION AND PASS A AS OBJECT AND A IS RECIEVED BY T.
    obj.display();
    return 0;
}