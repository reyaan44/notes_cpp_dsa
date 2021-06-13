#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define precision(a) cout<<fixed<<setprecision(a)
#define testcase ll t; cin>>t; while(t--)
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,b) for(ll i=a; i<b; ++i)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;
const ll M = 1000000007;
int largestRectangleArea(vector<ll>& heights) 
    {
        vector<ll> left(heights.size());
        vector<ll> right(heights.size());
        stack<ll> st;
        for(ll i=0; i<heights.size(); i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty()) left[i]=0;
            else left[i]=st.top()+1;
            st.push(i);
        }
        stack<ll> st1;
        for(ll i=heights.size()-1; i>=0; i--)
        {
            while(!st1.empty() && heights[st1.top()]>=heights[i])
            {
                st1.pop();
            }
            if(st1.empty()) right[i]=heights.size()-1;
            else right[i]=st1.top()-1;
            st1.push(i);
        }
        ll max = INT_MIN;
        forl(i,0,heights.size())
        {
            cout<<left[i]<<" ";
        }
        cout<<endl;
        forl(i,0,heights.size())
        {
            cout<<right[i]<<" ";
        }
        cout<<endl;
        for(ll i=0; i<heights.size(); i++)
        {
            if((right[i]-left[i]+1)*heights[i]>max) max=(right[i]-left[i]+1)*heights[i];
        }
        return max;
    }
ll mod(ll x)
{
    return (x%M + M)%M;
}
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<ll> vect;
    vect.push_back(2);
    vect.push_back(1);
    vect.push_back(5);
    vect.push_back(6);
    vect.push_back(2);
    vect.push_back(3);
    cout<<largestRectangleArea(vect)<<endl;
    timetaken;
    return 0;
}