#include<bits/stdc++.h>
using namespace std;
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	vector<int> vect(10,5);
	// for(int i=0; i<n; i++)
	// {
	// 	cout<<vect[i]<<" ";
	// }
	vect.push_back(10);
	vect.push_back(13);
	vect.push_back(34);
	// vect.pop_back();
	int z;
	 z=vect.size();
	 cout<<"Z = "<<z<<endl;
	 // vect.pop_back();
	 vect[2]=7;
	 for(int i=0; i<z; i++)
	 {
	 	vect[i]+=4;
	 }
	 for(int i=0; i<vect.size(); i++)
	 {
	 	cout<<vect[i]<<" ";
	 }
	return 0;
}