#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class complexa
{
    double a,b;
public:
    void set(double real, double img)
    {
        a=real;
        b=img;
    }
    void display(complexa c);
    friend complexa sum(complexa c1, complexa c2);
};
void complexa :: display(complexa c)
{
    cout<<c.a<<" + i"<<c.b<<endl;
}
complexa sum(complexa c1, complexa c2)
{
    complexa c3;
    c3.a = c1.a + c2.a;
    c3.b = c1.b + c2.b;
    return (c3);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    complexa w,s,d;
    w.set(3.2,3.5);
    w.display(w);  //HERE WE COULD ALSO DO w.set() AND NOT GIVING W AS ARGUMENT BUT IN THE FUNCTION WE ARE RECIEVING AN OBJECT AS AN ARGUMENT. AND IF WE DIDN'T USE IT AS RECIEVING ARGUMENT, THEN IN ABOVE "C.A" THIS WOULDNT BE NECESSARY, BECAUSE IT WOULD TAKE "A" AS W'S OBJECT ONLY
    s.set(5.2,6.3);
    s.display(s);
    d = sum(w,s);
    d.display(d);
    cerr<<fixed<<setprecision(10);
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}