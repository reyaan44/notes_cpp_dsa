#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void multidimensional(ll arr[][3][3]) //OR ll (*ARR)[3][3]
{
    // IN CALLING ARGUNENTS, ALL DIMENSIONS EXCEPT THE FIRST DIMENSIONS NEED TO BE ENFORCED IN A CALLED FUNCTION
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    multidimensional(arr);
    // FIRST WE WILL GET 3 2D ARRAYS, DEREFFERENCING ONCE WILL ENTER US INTO ONE OF THE 2D ARRAYS AND WE WILL GET 3 1D ARRAYS, DEREFFERENCING AGAIN WILL GIVE US A PARTICULAR 1D ARRAY, DEREFFERENCINGONCE AGAIN WILL GIVE US A PARTICULAR VALUE OF AN ELEMENT IN THAT 1D ARRAY. 
    ll arr[3][3][3]=
    {
    	{{1,2,3},{4,5,6},{7,8,9}},
    	{{10,11,12},{13,14,15},{16,17,18}},
    	{{19,20,21},{22,23,24},{25,26,27}}
    }; // ARR[I][J][K]= (*ARR[I][J]+K) = *(*(ARR[I]+J)+K) = *(*(*(ARR+I)+J)+K)
    // IMP - ARR[i] IS SAME AS *(ARR+i) AND &ARR[i][0]
    cout<<arr<<endl;
    cout<<arr[1]<<endl;
    cout<<*(arr+1)<<endl;
    cout<<&arr[1][0]<<endl;
    ll (*ptr)[3][3]=arr; //HERE, PTR POINTS TO THE START OF FIRST 2D ARRAY OF 3 2D ARRAYS
    // PTR IS A POINTER TO A TWO DIMENSIONAL ARRAY OF 2*2
    cout<<ptr<<endl;
    cout<<ptr+1<<endl; // HERE, PTR+1 POINTS TO THE START OF 2ND 2D ARRAY OF 3 2D ARRAYS
    cout<<ptr+2<<endl;
    cout<<*ptr<<endl; // HERE, PTR POINTS TO THE FIRST 1D ARRAY OF THE GIVEN 3 1D ARRAYS OF THE FIRST 2D ARRAY OF GIVEN 3 2D ARRAYS 
    cout<<*(ptr+1)<<endl; // HERE, *(PTR+1) POINTS TO THE FIRST 1D ARRAY OF THE 2ND 2D ARRAY OR IT CAN BE OBSERVED LIKE THIS AS WELL, *(PTR+1) = PTR[1], ANS PTR[1] = &PTR[1][0]
    cout<<ptr[2][1]<<endl; //HERE, IT IS (*(PTR+2)+1) AS WELL AS &PTR[2][1][0]
    cout<<ptr[2][1][1]<<endl;
    cout<<*(*(*(ptr+2)+1)+1)<<endl;
    cout<<*(*(*(ptr+1)+1)+2)<<endl;
    cout<<*(*(*(ptr)+2))<<endl;
    // TO PRINT THE COMPLETE ARRAY IN 3D
    for(ll i=0; i<3; i++)
    {
    	for(ll j=0; j<3; j++)
    	{
    		for(ll k=0; k<3; k++)
    		{
    			//cout<<arr[i][j][k]<<" ";
    			//cout<<*(arr[i][j]+k)<<" ";
    			cout<<*(*(*(arr+i)+j)+k)<<" ";
    		}
    		cout<<endl;
    	}
    	cout<<endl;
    }
    //TO PRINT THE COMPLETE ARRAY IN 3D
    ll *p;
    ll i=0;
    for(p=arr[0][0]; p<=&arr[2][2][2]; p++) //HERE, ARR[0][0] ==== &ARR[0][0][0]
    {
    	if(i%3==0 && i!=0)
    	{
    		cout<<endl;
    	}
    	if(i%9==0 && i!=0)
    	{
    		cout<<endl;
    	}
    	cout<<*p<<" ";
    	i++;
    }
    return 0;
}

