//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int missingNumber(int a[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i=0, n;
		cin>>n;
		int a[n+5];
		for(i=0;i<n-1;i++)
			cin>>a[i];
			
		cout<<missingNumber(a, n)<<endl;
	}
}
// } Driver Code Ends


int XOR(int N)
{
    if(N%4==0) return N;
    if(N%4==1) return 1;
    if(N%4==2) return N+1;
    if(N%4==3) return 0;
}
int missingNumber(int A[], int N)
{
    int X=XOR(N);
    for(int i=0;i<N-1;i++)
    {
        X^=A[i];
    }
    return X;
}