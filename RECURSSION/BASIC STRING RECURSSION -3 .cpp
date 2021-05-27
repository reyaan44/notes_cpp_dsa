#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define precision(a) cout<<fixed<<setprecision(a)
#define testcase ll t; cin>>t; while(t--)
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,b) for(ll i=a; i<b; ++i)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;




void reverseString(string s)
{
    if(s.length()==0)
    {
        return;
    }
    string s1 = s.substr(1);
    reverseString(s1);
    cout<<s[0];
}




void replacePI(string  s)
{
    if(s.length()==0) return;
    if(s[0]=='p' && s[1]=='i')
    {
        cout<<"3.14";
        return replacePI(s.substr(2));
    }
    cout<<s[0];
    return replacePI(s.substr(1));
}




void towerOfHanoi(ll n, char src, char helper, char dest)
{
    if(n==0) return;
    towerOfHanoi(n-1,src,dest,helper);                  // AMONG ALL STEPS, HERE, WE ARE REACHING TO LAST SECOND STEP, WHERE SOURCE ROD HAS ONLY AND BIGGEST ONE, HELPER HAS ALL OTHERS SMALLER THAN IT, AND WE ARE ABOUT TO PLACE BIGGEST ON THE DESTINATION ROD, THATS WHY WE CHANGES HELPER TO DESTINATION, BECOZ TILL NOW, THIS WAS OUR DESTINATION TO PLACE N-1 RODS ON HELPER AND BIGGEST ON SOURCE
    cout<<"Moves from "<<src<<" to "<<dest<<endl;
    towerOfHanoi(n-1,helper,src,dest);                  // NOW AFTER THE LAST STEP, WE WILL MAKE HELPER ROD THE SOURCE ROD, AND SOURCE ROD THE HELPER ROD, N-1 INDICATES THERE ARE ONLY N-1 HANOI LEFT ON RODS
}




string removeDuplicates(string s)
{
    if(s.length()==0)
    {
        return "";
    }
    char a = s[0];
    string s1 = removeDuplicates(s.substr(1));
    if(a==s1[0])
    {
        return s1;
    }
    return a+s1;
}






string moveAllXToEnd(string s)
{
    if(s.length()==0)
    {
        return "";
    }
    if(s[0]=='x')
    {
        return moveAllXToEnd(s.substr(1))+'x';
    }
    else
    {
        return (s[0]+moveAllXToEnd(s.substr(1)));
    }
}




void subStrings(string s, string ans)
{
    if(s.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    string a = s.substr(1);
    subStrings(a,ans);
    subStrings(a,ans+s[0]);
}





int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s = "binod";
    reverseString(s);
    cout<<endl<<endl;

    string s1 = "pippxxppiixipi";
    replacePI(s1);
    cout<<endl<<endl;

    towerOfHanoi(3,'A','B','C');
    cout<<endl;

    string s2 = "aaaabbccddddzz";
    cout<<removeDuplicates(s2)<<endl<<endl;

    string s3="abxxdfjkscxnxxnxoanaax";
    cout<<moveAllXToEnd(s3)<<endl<<endl;

    string s4="abc";
    subStrings(s4,"");
    timetaken;
    return 0;
}