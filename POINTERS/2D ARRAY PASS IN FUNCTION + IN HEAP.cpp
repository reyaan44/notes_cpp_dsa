#include<bits/stdc++.h>
#define ll long long int
ll n,m;
ll r,c;
using namespace std;
void upperTriangular(ll **M1, ll **M2)
{
	bool first=true,second=true;
	for(ll i = 1; i < n; i++)
	{
        for(ll j = 0; j < i; j++)
        {
            if(M1[i][j]!=0) first=false;
        }
	}
	for(ll i=1; i<r; i++)
	{
		for(ll j=0; j<i; j++)
		{
			if(M2[i][j]!=0) second=false;
		}
	}
	if(first)
	{
		cout<<"THE FIRST MATRIX IS AN UPPER TRIANGULAR MATRIX"<<endl;
	}    
	else
	{
		cout<<"THE FIRST MATRIX IS NOT AN UPPER TRIANGULAR MATRIX"<<endl;
	}
	if(second)
	{
		cout<<"THE SECOND MATRIX IS AN UPPER TRIANGULAR MATRIX"<<endl;
	}
	else
	{
		cout<<"THE SECOND MATRIX IS NOT AN UPPER TRIANGULAR MATRIX"<<endl;
	}
	cout<<endl;
}
void sumOfDiagonal(ll **M1,ll **M2)
{
	ll sum1 = 0,sum2 = 0;
	for(ll i=0; i<min(n,m); i++)
	{
		sum1+=M1[i][i];
	}
	cout<<"THE SUM OF DIAGONALS OF FIRST MATRIX IS "<<sum1<<endl;
	for(ll i=0; i<min(r,c); i++)
	{
		sum2+=M2[i][i];
	}
	cout<<"THE SUM OF DIAGONALS OF SECOND MATRIX IS "<<sum2<<endl;
	cout<<endl;
}
void transpose(ll **M1, ll **M2)
{
    ll i, j;
    cout<<"THE TRANSPOSE OF FIRST MATRIX IS : "<<endl;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            cout<<M1[j][i]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"THE TRANSPOSE OF SECOND MATRIX IS : "<<endl;
    for(i=0; i<c; i++)
    {
    	for(j=0; j<r; j++)
    	{
    		cout<<M2[j][i]<<" ";
    	}
    	cout<<endl;
    }
    cout<<endl;
}
void SumOfMatrices(ll **M1, ll ** M2)
{
	if(n==r && m==c)
	{
		for(ll i=0; i<n; i++)
		{
			for(ll j=0; j<m; j++)
			{
				cout<<M1[i][j]+M2[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	else
	{
		cout<<"THE MATRIXES CANNOT BE ADDED DUE TO DIFFERENCE IN THEIR SIZES"<<endl<<endl;
	}
}
void SubtractOfMatrices(ll **M1, ll ** M2)
{
	if(n==r && m==c)
	{
		for(ll i=0; i<n; i++)
		{
			for(ll j=0; j<m; j++)
			{
				cout<<M1[i][j]-M2[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	else
	{
		cout<<"THE MATRIXES CANNOT BE SUBTRACTED DUE TO DIFFERENCE IN THEIR SIZES"<<endl<<endl;
	}
}
void multiply(ll **M1,ll **M2)
{
	if(m!=r)
	{
		cout<<"MULTIPLICATION OF MATRICES IS NOT POSSIBLE"<<endl;
	}
	else
	{
		ll arr[n][c]={};
		for(ll i=0; i<n; i++)
		{
			for(ll j=0; j<c; j++)
			{
				for(ll k=0; k<m; k++)
				{
					arr[i][j] += M1[i][k] + M2[k][j];
				}
			}
		}
		for(ll i=0; i<n; i++)
		{
			for(ll j=0; j<c; j++)
			{
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
}
int main()
{
    cout<<"ENTER THE NUMBER OF ROWS OF FIRST MATRIX : ";
    cin>>n;
    cout<<"ENTER THE NUMBER OF COLUMNS OF FIRST MATRIX: ";
    cin>>m;
    cout<<"ENTER THE VALUES OF FIRST MATRIX : "<<endl;
    ll **M1;
    M1 = new ll *[n];
    for(ll i = 0; i<n; i++)
    {
    	M1[i]= new ll[m];
    	for(ll j=0; j<m; j++)
    	{
    		cin>>*(M1[i]+j);
    	}
    }
    cout<<"ENTER THE NUMBER OF ROWS OF SECOND MATRIX : ";
    cin>>r;
    cout<<"ENTER THE NUMBER OF COLUMNS OF SECOND MATRIX : ";
    cin>>c;
    cout<<"ENTER THE VALUES OF SECOND MATRIX : "<<endl;
    ll **M2;
    M2 = new ll *[r];
    for(ll i = 0; i<r; i++)
    {
    	M2[i] = new ll[c];
    	for(ll j=0; j<c; j++)
    	{
    		cin>>*(M2[i]+j);
    	}
    }
    cout<<endl;
    while(1)
    {
    	cout<<endl;
    	ll n1;
    	cout<<"ENTER YOUR CHOICE : "<<endl;
        cout<<"1. CHECK IF A MATRIX IS UPPER TRIANGULAR MATRIX OR NOT"<<endl;
        cout<<"2. SUM OF DIAGONAL ELEMENTS"<<endl;
        cout<<"3. PRINT TRANSPOSE OF A MATRIX"<<endl;
        cout<<"4. PRINT ADDITION OF TWO MATRICES"<<endl;
        cout<<"5. SUBTRACT TWO MATRICES"<<endl;
        cout<<"6. MULTIPLY TWO MATRICES"<<endl<<endl;
        cout<<"0. FOR END THE PROGRAM"<<endl;
        cin>>n1;
        if(n1==0) break;
        switch (n1)
    	{
    		case 1: upperTriangular(M1,M2); break;
    		case 2: sumOfDiagonal(M1, M2); break;
    		case 3: transpose(M1, M2); break;
    		case 4: SumOfMatrices(M1,M2); break;
    		case 5: SubtractOfMatrices(M1,M2); break;
    		case 6: multiply(M1,M2); break;
    		default: cout<<"INVALID NUMBER"<<endl; break;
    	}
    }
    return 0;
}