#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class BasicToClass1                  // CLASS
{
    ll hr,min;
public:
    BasicToClass1()                 // DEFAULT CONSTRUCTOR
    {
        hr = 0;
        min = 0;
    }
    BasicToClass1(ll a)             // PARAMETERIZED CONSTRUCTOR
    {
        hr=a/60;
        min=a%60;
    }
    void display()
    {
        cout<<"HR = "<<hr<<endl<<"MIN = "<<min<<endl;
    }
};
int main()
{
    BasicToClass1 obj;
    obj.display();
    ll timeinmin = 95;                      // NORMAL LL DATA TYPE
    obj = timeinmin;                  // HERE, OBJ = TIMEINMIN, OBJ IS AN OBJECT OF A CLASS AND TIMEINMIN IS A LONG LONG INT DATA TYPE, BUT AS WE DO OBJ = ..., IT INVOKES PARAMETERIZED CONSTRUCTOR EXPLICITLY WHICH MAKES 
                                      // PASS TIMEINMIN AS A PARAMETER WHICH IS RECIEVED BY A IN PARAMETERIZED CONSTRUCTOR AND IN THIS WAY, BY EXPLICIT CONSTUCTOR CALL, WE CONVERT BASIC DATA TYPE TO CLASS. 
    obj.display();
    return 0;
}