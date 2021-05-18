#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class bookstore
{
public:
        ll uid,price,numberofpages;
        string nameofbook,nameofauthor,genre;
        bool status;
} library[100];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    ll o=0;
    bool found=true;
    bool found1=true;
    bool found11=true;
    bookstore a;
    ll w=0;
    for(ll i=0; i<100; i++)
    {
        library[i].uid=0;
        library[i].price=0;
        library[i].numberofpages=0;
        library[i].nameofbook="";
        library[i].nameofauthor="";
        library[i].genre="";
        library[i].status=false;
    }
    cout<<"PRESS KEYS CORRESPONDING TO TASKS"<<endl;
    cout<<"1.ADD A BOOK"<<endl<<"2.WITHDRAW A BOOK"<<endl<<"3.SEARCH BOOK"<<endl<<"4.EXIT SYSTEM"<<endl;
    for(ll i=0; i>=0; i++)
    {
        cout<<"PRESS THE KEY"<<endl;
        ll x;
        cin>>x;
        if(x==4)
        {
            cout<<endl;
            cout<<"EXITED FROM LIBRARY. VISIT AGAIN"<<endl;
            return 0;
        }
        else if(x==1)
        {
            cout<<"ENTER UID OF BOOK : ";
            cin>>library[w].uid;
            cout<<"ENTER PRICE OF BOOK : ";
            cin>>library[w].price;
            cout<<"ENTER NUMBER OF PAGES OF BOOK : ";
            cin>>library[w].numberofpages;
            cout<<"ENTER NAME OF AUTHOR OF BOOK : ";
            cin>>library[w].nameofauthor;
            cout<<"ENTER GENRE OF BOOK : ";
            cin>>library[w].genre;
            library[w].status=true;
            cout<<"ENTER NAME OF BOOK : ";
            cin>>library[w].nameofbook;
            cout<<"BOOK ADDED IN LIBRARY"<<endl;
            w++;
        }
        else if(x==2)
        { 
            ll y;
            found=true;
            cout<<"1.UID"<<endl<<"2.AUTHOR"<<endl<<"3.BOOK NAME"<<endl;
            ll z;
            cin>>z;
            if(z==1)
            {
                o=0;
                cout<<"ENTER UID : ";
                ll aa;
                cin>>aa;
                while(library[o].uid!=0)
                {
                    if(library[o].uid==aa && library[o].status==true)
                    {
                        cout<<"BOOK AVAILABLE AND WITHDRAWN"<<endl;
                        library[o].status=false;
                        found=false;
                        break;
                    }
                    o++;
                }
                if(found) cout<<"BOOK NOT FOUND<<endl";
            }
            else if(w==2)
            {
                o=0;
                found1=true;
                cout<<"ENTER AUTHORS NAME : ";
                string bb;
                cin>>bb;
                while(library[o].nameofauthor!="")
                {
                    if((library[o].nameofauthor)==bb && library[o].status==true)
                    {
                        cout<<"BOOK AVAILABLE AND WITHDRAWN"<<endl;
                        library[o].status=false;
                        found1=false;
                        break;
                    }
                    o++;
                }
                if(found1) cout<<"BOOK NOT FOUND"<<endl;
            }
            else if(w==3)
            {
                o=0;
                found11=true;
                cout<<"ENTER BOOKS NAME : ";
                string bxb;
                cin>>bxb;
                while(library[o].nameofbook!="")
                {
                    if(library[o].nameofbook==bxb && library[o].status==true)
                    {
                        cout<<"BOOK AVAILABLE AND WITHDRAWN"<<endl;
                        library[o].status=false;
                        found11=false;
                        break;
                    }
                    o++;
                }
                if(found11) cout<<"BOOK NOT FOUND"<<endl;
            }
        }
        else if(x==3)
        {
            ll yy;
            bool foundd=true;
            cout<<"1.UID"<<endl<<"2.AUTHOR"<<endl<<"3.BOOK NAME"<<endl;
            ll zz;
            o=0;
            cin>>zz;
            if(zz==1)
            {
                foundd=true;
                cout<<"ENTER UID : ";
                ll aaa;
                cin>>aaa;
                while(library[o].uid!=0)
                {
                    if(library[o].uid==aaa && library[o].status==true)
                    {
                        cout<<"BOOK AVAILABLE"<<endl;
                        foundd=false;
                        break;
                    }
                    o++;
                }
                if(foundd) cout<<"BOOK NOT FOUND<<endl";
            }
            else if(zz==2)
            {
                o=0;
                bool foundd1=true;
                cout<<"ENTER AUTHORS NAME : ";
                string bbb;
                cin>>bbb;
                while(library[o].nameofauthor!="")
                {
                    if((library[o].nameofauthor)==bbb && library[o].status==true)
                    {
                        cout<<"BOOK AVAILABLE"<<endl;
                        foundd1=false;
                        break;
                    }
                    o++;
                }
                if(foundd1) cout<<"BOOK NOT FOUND"<<endl;
            }
            else if(zz==3)
            {
                o=0;
                bool foundd11=true;
                cout<<"ENTER BOOKS NAME : ";
                string bxbb;
                cin>>bxbb;
                while(library[o].nameofbook!="")
                {
                    if(library[o].nameofbook==bxbb && library[o].status==true)
                    {
                        cout<<"BOOK AVAILABLE"<<endl;
                        foundd11=false;
                        break;
                    }
                    o++;
                }
                if(foundd11) cout<<"BOOK NOT FOUND"<<endl;
            }   
        }
    }
    return 0;
}