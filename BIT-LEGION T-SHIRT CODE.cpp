#include<bits/stdc++.h>
#define ll long long int
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,b) for(ll i=a; i<b; ++i)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
using namespace std;
int main()
{
    quick;
    ll freqans[26]={0};
    vector<string> vect;
    string s = "sipasmtiuktmavvaisdhtarajyjmsrnnuurarnyrshoeoaka";
    string s1,s2,s3,s4;
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    forl(i,0,s.length())
    {
        freqans[s[i]-'A']++;
    }
    forl(i,0,249)
    {
        string x;
        getline(cin,x);
        vect.push_back(x);
    }
    forl(i,0,vect.size())
    {
        string str = vect[i];
        forl(j,0,str.length())
        {
            if(str[j]=='B' || str[j]=='C' || str[j]=='F' || str[j]=='F' || str[j]=='L' || str[j]=='Q' || str[j]=='W' || str[j]=='X' || str[j]=='Z')
            {
                vect[i]="0";
                break;
            }
        }
    }
    vector<string> ans;
    forl(i,0,vect.size())
    {
        if(vect[i]!="0") ans.push_back(vect[i]);
    }
    forl(i,0,ans.size())
    {
        forl(j,i+1,ans.size())
        {
            forl(k,j+1,ans.size())
            {
                forl(m,k+1,ans.size())
                {
                    bool check=1;
                    ll freq[26]={0};
                    s1=ans[i];
                    s2=ans[j];
                    s3=ans[k];
                    s4=ans[m];
                    for (int ii = 0; ii < ans[i].size(); ii++)
                    freq[s1[ii] - 'A']++;
                    for (int jj = 0; jj < ans[j].size(); jj++)
                    freq[s2[jj] - 'A']++;
                    for (int kk = 0; kk < ans[k].size(); kk++)
                    freq[s3[kk] - 'A']++;
                    for (int mm = 0; mm < ans[m].size(); mm++)
                    freq[s4[mm] - 'A']++;
                    forl(aa,0,26)
                    {
                        if(freq[aa]!=freqans[aa]) check=0;
                    }
                    if(check)
                    {
                        cout<<"S1 = "<<s1<<" "<<"s2 = "<<s2<<" "<<"s3 = "<<s3<<" "<<"s4 = "<<s4<<endl;
                    }
                }
            }
        }
    }

    timetaken;
    return 0;
}