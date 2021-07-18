#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class timea
{
    ll milliseconds;
    ll seconds;
public:
    void gettime(ll a, ll b)
    {
        milliseconds=b;
        seconds=a;
    }
    void display() const; // IF WE USE CONST AFTER THE DECLARATION AND DEFINITION, THEN THAT FUNCTION IS UNABLE TO ALTER THE VALUES OF DATA MEMBERS OF THAT FUNCTION, IF IT TRIES, IT WILL GIVE ERROR
    void t(timea t1, timea t2);
};
void timea :: t(timea t1, timea t2)
{
    milliseconds = t1.milliseconds + t2.milliseconds; // t3.milliseconds not necessary becoz it called the function, so by default it will take it implicitly
    seconds = milliseconds/100;
    milliseconds = milliseconds % 100;
    seconds+=t1.seconds+t2.seconds;
}
void timea :: display() const // IF WE USE CONST AFTER THE DECLARATION AND DEFINITION, THEN THAT FUNCTION IS UNABLE TO ALTER THE VALUES OF DATA MEMBERS OF THAT FUNCTION, IF IT TRIES, IT WILL GIVE ERROR
{
    cout<<"SECONDS : "<<seconds<<endl;
    cout<<"MILLISECONDS : "<<milliseconds<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    timea t1;
    timea t2;
    timea t3;
    t1.gettime(3,234);
    t2.gettime(2,345);
    t3.t(t1,t2);
    t1.display();
    t2.display();
    t3.display();
    cerr<<fixed<<setprecision(10);
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}