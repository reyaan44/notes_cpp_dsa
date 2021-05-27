#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define precision(a) cout<<fixed<<setprecision(a)
#define testcase ll t; cin>>t; while(t--)
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,b) for(ll i=a; i<b; ++i)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;





void revrseSentence(string s1)  
{
    stack<string> s;
    for(ll i =0; i<s1.length(); i++)
    {
        string word="";
        while(s1[i]!=' ' && i<s1.length())
        {
            word+=s1[i];
            i++;
        }
        s.push(word);
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}





void insertAtBottom(stack<ll> & s,ll ele)   // SUPPOSE WE HAVE A STACK OF 1->2->3 WITH 1 AT TOP, NOW WE NEED TO ADD 4, IT WILL NORMALLY GO AS 4->1->2->3, BUT WE WANT TO PUSH AT THE BOTTOM OF STACK
                                            // SO, WE WILL START TAKING OUT ALL EMENTS FROM STACK AND KEEPING TOP ELEMENT AS A VARIABLE TOPELE, WE WILL PASS 4 IN RECURSSION TILL STACK IS EMPTY, NOW THAT STACK 
                                            // BECOMES EMPTY, WE WILL PUSH 4, THEN PREV RECURSSION STEP 3,2,1.
{
    if(s.empty())
    {
        s.push(ele);
        return;
    }
    ll topele = s.top();
    s.pop();
    insertAtBottom(s,ele);
    s.push(topele);
}
void reverseStack(stack<ll> & s)        // FIRST, WE WILL EMPTY THE WHOLE STACK BY RECURSSION AND KEEP TOP ELEMENT AS A, NOW IF STACK IS EMOTY RETURN, AFTER THAT SUPPOSE TOPELEMENT IS 5, SO A WILL HAVE 1, IT WILL BE SENT TO INSERT AT BOTTOM OF STACK, THEN COMES 2, IT WILL BE INSERTED AT BOTTOM OF 1, AND SO ON
{
    if(s.empty())
    {
        return;
    }
    ll a=s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s,a);
}




void insertAtBottomDemoOnOwn(stack<ll> & s, ll a)       // SUPPOSE WE HAVE A STACK OF 1->2->3 WITH 1 AT TOP, NOW WE NEED TO ADD 4, IT WILL NORMALLY GO AS 4->1->2->3, BUT WE WANT TO PUSH AT THE BOTTOM OF STACK
                                                        // SO, WE WILL START TAKING OUT ALL EMENTS FROM STACK AND KEEPING TOP ELEMENT AS A VARIABLE TOPELE, WE WILL PASS 4 IN RECURSSION TILL STACK IS EMPTY, NOW THAT STACK 
                                                        // BECOMES EMPTY, WE WILL PUSH 4, THEN PREV RECURSSION STEP 3,2,1.
{
    if(s.empty())
    {
        s.push(a);
        return;
    }
    ll b = s.top();
    s.pop();
    insertAtBottomDemoOnOwn(s,a);
    s.push(b);
    return;
}





ll prefixEvaluation(string s)
{
    stack<ll> st;
    reverse(s.begin(), s.end());            // NOTE
    forl(i,0,s.length())
    {
        if(s[i]>=48 && s[i]<=57) st.push(s[i]-'0');
        else 
        {
            ll op1 = st.top();          // NOTE
            st.pop();
            ll op2 = st.top();          // NOTE
            st.pop();

            switch(s[i])
            {
                case '+':
                    st.push(op1+op2);
                    break;
                case '-':
                    st.push(op1-op2);
                    break;
                case '*':
                    st.push(op1*op2);
                    break;
                case '/':
                    st.push(op1/op2);
                    break;
                case '^':
                    st.push(pow(op1,op2));
                    break;
            }
        }
    }
    return st.top();
}





ll postfixEvaluation(string s)
{
    stack<ll> st;
    forl(i,0,s.length())
    {
        if(s[i]>=48 && s[i]<=57) st.push(s[i]-'0');
        else 
        {
            ll op2 = st.top();      // NOTE
            st.pop();
            ll op1 = st.top();      // NOTE
            st.pop();

            switch(s[i])
            {
                case '+':
                    st.push(op1+op2);
                    break;
                case '-':
                    st.push(op1-op2);
                    break;
                case '*':
                    st.push(op1*op2);
                    break;
                case '/':
                    st.push(op1/op2);
                    break;
                case '^':
                    st.push(pow(op1,op2));
                    break;
            }
        }
    }
    return st.top();
}




ll precedence(char a)       // NOTE, HIGHER PRECEDENCE MEANS EARLIER
{
    if(a=='^') return 3;
    if(a=='*' || a=='/') return 2;
    if(a=='+' || a=='-') return 1;
    return -1;              // FOR PARENTHESIS
}
string infixToPostfix(string s)
{
    string ans="";
    stack<char> st;
    forl(i,0,s.length())
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<'9')) ans+=s[i];
        else if(s[i]=='(') st.push(s[i]);
        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                ans+=st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        }
        else
        {
            while(!st.empty() && precedence(st.top())>precedence(s[i]))     // IF PRECEDENCE OF TOP ELEMENT IN STACK IS MORE THAT THAT TO BE PUSHED, WE TAKE THE TOP ELEMENT OUT, PRINT IT, AND PUSH THE NEW ELEMENT, TILL PRECEDENCE OF TOP ELEMENT IS MORE OR PARENTHESIS COMES
            {
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())      // NOTE
    {
        ans+=st.top();
        st.pop();
    }
    return ans;
}





string infixToPrefix(string str)
{
    reverse(str.begin(),str.end());     // NOTE
    forl(i,0,str.length())
    {
        if(str[i]=='(') str[i]=')';
        else if(str[i]==')') str[i]='(';
    }
    string ans = infixToPostfix(str);       // NOTE
    reverse(ans.begin(), ans.end());        // NOTE
    return ans;
}





bool balancedParenthesis(string s)
{
    stack<char> st;
    forl(i,0,s.length())
    {
        if(s[i]=='{' || s[i]=='[' || s[i]=='(') st.push(s[i]);
        else
        {
            if(st.empty()) return 0;        // NOTE
            if(s[i]=='}')
            {
                if(st.top()!='{') return 0;
                st.pop(); 
            }
            else if(s[i]==']')
            {
                if(st.top()!='[') return 0;
                st.pop();
            }
            else if(s[i]==')')
            {
                if(st.top()!='(') return 0;
                st.pop();
            }
        }
    }
    if(st.empty()) return 1;        // NOTE
    return 0;
}





int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string str = "Hey, how are you doing?";         // REVERSING THE SENTENCE WITH STACK
    revrseSentence(str);
    cout<<endl;

    stack<ll> s;                // REVERSING A STACK WITHOUT MAKING ANOTHER STACK, USING RECURSSION
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<s.top()<<endl;
    reverseStack(s);
    cout<<s.top()<<endl<<endl;

    stack<ll> s1;
    insertAtBottomDemoOnOwn(s1,1);          // INSERTING A NEW ELEMENT AT THE BOTTOM OF THE STACK
    cout<<s1.top()<<endl;
    insertAtBottomDemoOnOwn(s1,2);
    insertAtBottomDemoOnOwn(s1,3);
    insertAtBottomDemoOnOwn(s1,4);
    cout<<s1.top()<<endl;
    s1.pop();
    cout<<s1.top()<<endl<<endl;

            // WE USE PREFIX AND POSTFIX BECAUSE COMPUTER DOESNOT UNDERSTAND DMAS AND PRECEDENCE

    cout<<prefixEvaluation("-+7*45+20")<<endl<<endl;    // 7+(4*5)-(2+0)

    cout<<postfixEvaluation("46+2/5*7+")<<endl<<endl;   // (4+6)/2*5+7

    cout<<infixToPostfix("(a-b/c)*(a/b-c)")<<endl<<endl;

    cout<<infixToPrefix("(a-b/c)*(a/b-c)")<<endl<<endl;

    cout<<balancedParenthesis("([{}])")<<endl;      // TRUE
    cout<<balancedParenthesis("([{)}]")<<endl;      // FALSE
    timetaken;
    return 0;
}                                                                                                     